// A2: Job Sequencing with deadlines (Greedy) - O(n^2)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cout << "Number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    int maxDeadline = 0;
    cout << "Enter id deadline profit:\n";
    for (Job& job : jobs) {
        cin >> job.id >> job.deadline >> job.profit;
        maxDeadline = max(maxDeadline, job.deadline);
    }

    sort(jobs.begin(), jobs.end(),
         [](const Job& first, const Job& second) {
             return first.profit > second.profit;
         });

    vector<string> slots(maxDeadline);
    int totalProfit = 0;

    for (const Job& job : jobs) {
        for (int time = job.deadline - 1; time >= 0; time--) {
            if (slots[time].empty()) {
                slots[time] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Job sequence: ";
    for (const string& jobId : slots) {
        if (!jobId.empty()) {
            cout << jobId << " ";
        }
    }
    cout << "\nMax profit: " << totalProfit << endl;
}
