# LP-III (410246) Practical Answers

| Code | Question | File |
|------|----------|------|
| A1 | Fibonacci + step count | GroupA_DAA/A1_fibonacci.cpp |
| A2 | Job sequencing (greedy) | GroupA_DAA/A2_job_sequencing.cpp |
| A3 | Fractional knapsack (greedy) | GroupA_DAA/A3_fractional_knapsack.cpp |
| A4 | 0-1 knapsack (DP) | GroupA_DAA/A4_01_knapsack.cpp |
| A5 | Binomial coefficient (DP) | GroupA_DAA/A5_binomial_coeff.cpp |
| A6 | 8-Queens (backtracking) | GroupA_DAA/A6_8queens.cpp |
| B1 | Uber fare: Linear Reg vs Random Forest | GroupB_ML/B1_uber_fare.py |
| B2 | Spam: KNN vs SVM | GroupB_ML/B2_spam_knn_svm.py |
| B3 | Churn: Neural network | GroupB_ML/B3_churn_nn.py |
| B4 | Diabetes: KNN | GroupB_ML/B4_diabetes_knn.py |
| B5 | Sales: K-Means + elbow | GroupB_ML/B5_kmeans_sales.py |
| C1 | MetaMask + gas cost (steps) | GroupC_Blockchain/C1_MetaMask_Gas.md |
| C2 | MetaMask wallet + transaction (steps) | GroupC_Blockchain/C2_MetaMask_Wallet.md |
| C3 | Bank account contract | GroupC_Blockchain/C3_BankAccount.sol |
| C4 | Student data contract | GroupC_Blockchain/C4_StudentData.sol |
| C3/C4 | Deploying in Remix | GroupC_Blockchain/C3_C4_Deploy_Steps.md |

## Group A: Simple theory and algorithms

### A1. Fibonacci series

**Theory:**  
The Fibonacci series starts with 0 and 1. Every next number is the sum of
the previous two numbers. The iterative method uses a loop and needs `O(n)`
time and `O(1)` extra space. The recursive method calls itself for smaller
values and needs exponential time.

**Algorithm:**
1. Read the number of terms `n`.
2. Set `first = 0` and `second = 1`.
3. Print `first`.
4. Find the next number by adding `first` and `second`.
5. Move `second` into `first` and the next number into `second`.
6. Repeat until `n` terms are printed.

### A2. Job sequencing with deadlines

**Theory:**  
Each job takes one unit of time and has a deadline and a profit. The greedy
method schedules the jobs with higher profit first. Each job is placed in the
latest available time slot before its deadline.

**Algorithm:**
1. Read all jobs with their IDs, deadlines, and profits.
2. Sort the jobs in decreasing order of profit.
3. Create empty time slots up to the largest deadline.
4. For each job, check slots from its deadline backwards.
5. Put the job in the first empty slot found.
6. Add its profit to the total profit.
7. Print the job sequence and total profit.

### A3. Fractional knapsack

**Theory:**  
In fractional knapsack, an item can be divided into smaller parts. The greedy
method selects items according to their value-to-weight ratio. Items with the
highest ratio are selected first.

**Algorithm:**
1. Read the item values, weights, and knapsack capacity.
2. Calculate `value / weight` for every item.
3. Sort the items by decreasing ratio.
4. Take the complete item if it fits.
5. Otherwise, take only the fraction that fits.
6. Add the selected value to the total value.
7. Stop when the knapsack is full.

### A4. 0-1 knapsack

**Theory:**  
In 0-1 knapsack, an item is either selected completely or not selected.
Dynamic programming stores the best value for every item count and capacity.
The time complexity is `O(n * capacity)`.

**Algorithm:**
1. Read the values, weights, and capacity.
2. Create a table `dp` initialized with zero.
3. For each item and capacity:
   - Do not select the item.
   - Select the item if its weight fits.
4. Store the larger of these two values in `dp`.
5. The last table value is the maximum profit.
6. Trace the table backwards to find the selected items.

### A5. Binomial coefficient

**Theory:**  
The binomial coefficient is written as `C(n, k)` and represents the number
of ways to select `k` items from `n` items. Pascal's rule is:
`C(n, k) = C(n-1, k-1) + C(n-1, k)`.

**Algorithm:**
1. Read `n` and `k`.
2. Create a table for the binomial coefficients.
3. Set the first column and diagonal values to `1`.
4. For other positions, use Pascal's rule.
5. Print the table and `C(n, k)`.

### A6. 8-Queens problem

**Theory:**  
The 8-Queens problem places eight queens on a chessboard so that no two
queens attack each other. Backtracking tries a position, continues if it is
safe, and removes the queen when no solution is possible.

**Algorithm:**
1. Read the row and column of the first queen.
2. Place the first queen on the board.
3. Start with the next row.
4. Try every column in that row.
5. Place a queen only if it does not share a row, column, or diagonal.
6. Move to the next row and repeat.
7. If no column is safe, remove the previous queen and try another position.
8. Print the board when all eight queens are placed.

## Compile and run
### C++
    g++ -O2 GroupA_DAA/A1_fibonacci.cpp -o a
    .\a.exe
    g++ -O2 GroupA_DAA/A4_01_knapsack.cpp -o a
    .\a.exe

### Python
    python GroupB_ML/B1_uber_fare.py [uber.csv]
    python GroupB_ML/B2_spam_knn_svm.py [emails.csv]
    python GroupB_ML/B3_churn_nn.py [Churn_Modelling.csv]
    python GroupB_ML/B4_diabetes_knn.py [diabetes.csv]
    python GroupB_ML/B5_kmeans_sales.py [sales_data_sample.csv]

Each Group B program accepts an optional CSV path. If no path is supplied,
the default Kaggle file name shown above is used.

## Sample inputs (Group A)
- A1: `10`
- A2: `5` then `a 2 100  b 1 19  c 2 27  d 1 25  e 3 15` → c a e, profit 142
- A3: `3 50` then `60 10  100 20  120 30` → 240
- A4: same input → 220 (items 2, 3)
- A5: `5 2` → 10
- A6: `1 1` (row col of first queen)
- https://github.com/Anuj-Gholve/LP3
