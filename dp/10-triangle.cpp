/*
This code is a solution for the triangle problem from leetcode at the link
https://leetcode.com/problems/triangle/description/
I have directly approached from the tabulation approach and the space optimized approach without the recursion and memoization
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
// Tabulation
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> ans = triangle;
        int n = triangle.size();
        for(int i = n-2; i >= 0; i--){
            for(int j = i; j>=0; j--){
                ans[i][j] += min(ans[i+1][j+1], ans[i+1][j]);
            }
        }
        return ans[0][0];
    }
//Time Complexity -> O(n^2)
//Space Complexity -> O(n^2)
*/
//Space Optimization
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> curr(0);
        if(n==1){
            return triangle[0][0];
        }
        vector<int> next = triangle[n-1];
        for(int i = n-2; i >= 0; i--){
            curr.clear();
            for(int j = 0; j <= i; j++){
                int tmp = triangle[i][j] + min(next[j+1], next[j]);
                curr.push_back(tmp);
            }
            next = curr;
        }
        return curr[0];
    }
//Time Complexity -> O(n^2)
//Space Complexity -> O(n)
};

int main(){
    Solution sol = Solution();
    int n;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }
    int ans = sol.minimumTotal(triangle);
    cout << ans << "\n";
    return 0;
}