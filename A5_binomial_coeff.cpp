// A5: Binomial coefficient C(n,k) using DP (Pascal's triangle) - O(n*k)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    if (n < 0 || k < 0 || k > n) {
        cout << "C = 0\n";
        return 0;
    }

    vector<vector<long long>> binomial(n + 1, vector<long long>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                binomial[i][j] = 1;
            } else {
                binomial[i][j] =
                    binomial[i - 1][j - 1] + binomial[i - 1][j];
            }
            cout << binomial[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "C(" << n << ", " << k << ") = " << binomial[n][k] << endl;
}
