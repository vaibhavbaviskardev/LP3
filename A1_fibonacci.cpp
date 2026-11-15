// A1: Fibonacci numbers + count of computational steps (iterative vs recursive)
#include <iostream>

using namespace std;

long long calls = 0;

long long fibRec(int n) {
    calls++;
    return n <= 1 ? n : fibRec(n - 1) + fibRec(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 1) {
        return 0;
    }
    
    long long a = 0;
    long long b = 1;
    int steps = 0;

    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
        steps++;
    }

    cout << "\nIterative steps = " << steps
         << " -> O(n) time, O(1) space\n";
    cout << "Recursive fib(" << n - 1 << ") = " << fibRec(n - 1)
         << ", function calls = " << calls
         << " -> O(2^n) time, O(n) stack\n";
}
