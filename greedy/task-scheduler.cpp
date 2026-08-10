/*
    Problem: Task Scheduler
    Link: https://leetcode.com/problems/task-scheduler/
    Input from STDIO:
        First line: number of tasks
        Second line: task characters
        Third line: cooldown period n
    Output:
        Minimum time required to execute all tasks
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks){
            freq[c - 'A']++;
        }
        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCnt = count(freq.begin(), freq.end(), maxFreq);
        int frame = (maxFreq - 1) * (n + 1) + maxCnt;
        return max((int)tasks.size(), frame);
    }
    // Time Complexity: O(T), where T = number of tasks
    // Space Complexity: O(1)
};
int main() {
    int numTasks, n;
    cin >> numTasks;
    vector<char> tasks(numTasks);
    for(int i = 0; i < numTasks; i++){
        cin >> tasks[i];
    }
    cin >> n;
    Solution sol;
    int ans = sol.leastInterval(tasks, n);
    cout << ans << endl;
    return 0;
}