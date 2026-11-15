// A4: 0-1 Knapsack using Dynamic Programming - O(n*W)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int capacity;
    cout << "Items and capacity: ";
    cin >> n >> capacity;

    vector<int> values(n + 1);
    vector<int> weights(n + 1);
    cout << "Enter value weight:\n";
    for (int i = 1; i <= n; i++) {
        cin >> values[i] >> weights[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int currentCapacity = 0; currentCapacity <= capacity;
             currentCapacity++) {
            dp[i][currentCapacity] = dp[i - 1][currentCapacity];
            if (weights[i] <= currentCapacity) {
                dp[i][currentCapacity] = max(
                    dp[i][currentCapacity],
                    values[i] + dp[i - 1][currentCapacity - weights[i]]);
            }
        }
    }

    cout << "Max value = " << dp[n][capacity] << "\nItems taken: ";
    for (int i = n, remainingCapacity = capacity; i > 0; i--) {
        if (dp[i][remainingCapacity] != dp[i - 1][remainingCapacity]) {
            cout << i << " ";
            remainingCapacity -= weights[i];
        }
    }
    cout << endl;
}
