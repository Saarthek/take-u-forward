/*
This code is a solution of the problem Geek's training from Geeks for Geeks at the link
https://www.geeksforgeeks.org/problems/geeks-training/1
The solution progresses from brute force to optimal
P.S. Add the define statement to the top of your submission
*/

#include <bits/stdc++.h>

using namespace std;

#define NUM_ACT 3

class Solution {
    /*
    //Recursion
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = recMaxPts(mat, 0, n-1, -1);
        return ans;        
    }
  private:
    int recMaxPts(vector<vector<int>> &mat, int st, int end, int prev){
        if(st>end){
            return 0;
        }
        int ans = -1;
        for(int i = 0; i < NUM_ACT; i++){
            if(i!=prev){
                int tmp = mat[st][i]+recMaxPts(mat, st+1, end, i);
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
    Time Complexity -> Exponential
    Space Complexity -> Linear (Stack space)    
    */
/*
//Memoization
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n+1, vector<int> (NUM_ACT+1, -1));
        //int ans = -1;
        //for(int i = 0; i <  NUM_ACT; i++){
        //    int temp = recMaxPts(mat, dp, 0, n-1, i);
        //    ans = max(ans, temp);
        //}
        int ans = recMaxPts(mat, dp, 0, n-1, NUM_ACT);
        return ans;        
    }
  private:
    int recMaxPts(vector<vector<int>> &mat, vector<vector<int>>&dp, int st, int end, int prev){
        if(dp[st][prev]!=-1){
            return dp[st][prev];
        }
        
        if(st>end){
            return dp[st][prev]=0;
        }
        int ans = -1;
        for(int i = 0; i < NUM_ACT; i++){
            if(i!=prev){
                int tmp = mat[st][i]+recMaxPts(mat, dp, st+1, end, i);
                ans = max(ans, tmp);
            }
        }
        return dp[st][prev]=ans;
    }
    //Time Complexity -> O(n*NUM_ACT)
    //Space Complexity -> O(n*NUM_ACT) (DP array + Auxiliary Stack Space)
*/
//Tabulation
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n+1, vector<int> (NUM_ACT, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < NUM_ACT; j++){
                int ans = -1;
                for (int k = 0; k < NUM_ACT; k++){
                    if(j!=k){
                        int tmp = mat[i][j]+dp[i+1][k];
                        ans = max(ans, tmp);
                    }
                }
                dp[i][j] = ans;
            }
        }
        int ans = -1;
        for(int i = 0; i < NUM_ACT; i++){
            ans = max(dp[0][i], ans);
        }
        return ans;
    }
    //Time Complexity -> O(NUM_ACT * n)
    //Space Complexity -> O(NUM_ACT * n)
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (NUM_ACT, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < NUM_ACT; j++){
            cin >> arr[i][j];
        }
    }
    Solution sol = Solution();
    int ans = sol.maximumPoints(arr);
    cout << ans << "\n";
    return 0;
}