/*
Problem: Palindromic Substrings
Link: https://leetcode.com/problems/palindromic-substrings/
Input (stdin): A single string s
Output (stdout): Number of palindromic substrings in s
Example Input: aaa
Example Output: 6
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
/*
private:
    bool isPalin(string &s, int st, int end){
        while(st<end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalin(s, i, j)){
                    ans++;
                }
            }
        }
        return ans;
    }
    // Time Complexity -> O(n^3)
    // Space Complexity -> O(1)
*/
/*
//Needlessly complicated DP Tabulation
private:
    bool isPalin(string &s, int st, int end){
        while(st<end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int diag = 1; diag < n; diag++){
            int endrow = n-diag-1;
            for(int i = 0; i <= endrow; i++){
                dp[i][diag+i] += dp[i+1][diag+i];
                if(diag+i>0){
                    dp[i][diag+i] += dp[i][diag+i-1]; 
                }
                if(isPalin(s, i, diag+i)){
                    dp[i][diag+i] ++;
                }
                dp[i][diag+i] -= dp[i+1][diag+i-1];
            }
        }
        return dp[0][n-1];
    }
    // Time Complexity -> O(n^3)
    // Space Complexity -> O(n^2)
    */
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int diag = 1; diag < n; diag++){
            int endrow = n-diag-1;
            for(int i = 0; i <= endrow; i++){
                if(diag==1){
                    dp[i][diag+i]= s[i]==s[diag+i];
                }
                else{
                    dp[i][diag+i] = dp[i+1][diag+i-1] && (s[i]==s[diag+i]); 
                }
                ans += dp[i][diag+i];
            }
        }
        return ans;
    }
    //// Time Complexity -> O(n^2)
    // Space Complexity -> O(n^2)
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.countSubstrings(s) << '\n';
    return 0;
}