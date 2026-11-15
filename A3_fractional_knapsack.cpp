// A3: Fractional Knapsack (Greedy by value/weight ratio) - O(n log n)
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    double capacity;
    cout << "Items and capacity: ";
    cin >> n >> capacity;

    vector<pair<double, double>> items(n); // {value, weight}
    cout << "Enter value weight:\n";
    for (auto& item : items) {
        cin >> item.first >> item.second;
    }

    sort(items.begin(), items.end(),
         [](const auto& first, const auto& second) {
             return first.first / first.second > second.first / second.second;
         });

    double totalValue = 0;
    for (const auto& item : items) {
        if (capacity <= 0) {
            break;
        }

        double amount = min(capacity, item.second);
        totalValue += amount * item.first / item.second;
        capacity -= amount;
        cout << "Take " << amount << "/" << item.second
             << " of item (value " << item.first << ")\n";
    }

    cout << "Max value = " << totalValue << endl;
}
