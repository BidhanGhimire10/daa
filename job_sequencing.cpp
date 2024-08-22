#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;         // Job ID to identify the job
    int deadline;
    int profit;
};

bool compare_jobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

void job_sequencing_with_deadlines(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare_jobs);

    int max_deadline = 0;
    for (const auto& job : jobs) {
        if (job.deadline > max_deadline)
            max_deadline = job.deadline;
    }

    vector<int> schedule(max_deadline, 0);
    vector<int> job_sequence(max_deadline, 0);

    int total_profit = 0;
    for (const auto& job : jobs) {
        int deadline = job.deadline;
        while (deadline > 0) {
            if (schedule[deadline - 1] == 0) {
                schedule[deadline - 1] = 1;
                job_sequence[deadline - 1] = job.id;  // Store the job ID in the sequence
                total_profit += job.profit;
                break;
            }
            deadline--;
        }
    }

    cout << "Total profit: " << total_profit << endl;
    cout << "Job sequence: ";
    for (int i = 0; i < max_deadline; i++) {
        if (schedule[i] == 1) {
            cout << "Job" << job_sequence[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job details :\n";
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;  // Assigning job IDs starting from 1
        cin >> jobs[i].deadline >> jobs[i].profit;
    }

    job_sequencing_with_deadlines(jobs);

    return 0;
}
