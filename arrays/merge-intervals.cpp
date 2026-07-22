/*
This is a solution of the problem merge intervals in leetcode at the link
https://leetcode.com/problems/merge-intervals/description/
This code contains the optimal solution
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if(n<=1){
            return intervals;
        }
        int st = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(end < intervals[i][0]){
                ans.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({st, end});
        return ans;
    }
//Time Complexity -> O(n * log n) for merging O(n) for sorting
//Space Complexity -> O(n) to store output array, O(1) auxiliary space
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    Solution sol;
    vector<vector<int>> ans = sol.merge(intervals);
    for(auto interval : ans){
        cout << interval[0] << " " << interval[1] << '\n';
    }
    return 0;
}