/*
This code is a solution for the problem named Coin Change in Leetcode
https://leetcode.com/problems/coin-change/description/
The code progresses from recursion to space optimization
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
// Recursion
private:
    int recCoinChange(vector<int>& coins, int amount, int ind){
        if(amount==0){
            return 0;
        }
        if(ind==0){
            return (amount%coins[ind]) ? -1 : (amount/coins[ind]);
        }
        int ans = -1;
        int numIter = amount/coins[ind];
        for(int i = 0; i <= numIter; i++){
            int nxt = recCoinChange(coins, amount-(i*coins[ind]), ind-1);
            int curr = (nxt==-1)?nxt:i+nxt;
            if(nxt!=-1){
                ans = (ans ==-1)?curr:min(ans, curr);
            }
        }
        return ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        return recCoinChange(coins, amount, n-1);
    }
//Time Complexity -> Exponential
//Space Complexity -> Linear (Stack space)
*/
/*
//Memoization
private:
    int recCoinChange(vector<int>& coins, vector<vector<int>> &dp, int amount, int ind){
        if(dp[amount][ind]!=-2){
            return dp[amount][ind];
        }
        if(amount==0){
            return dp[amount][ind]=0;
        }
        if(ind==0){
            return dp[amount][ind] = ((amount%coins[ind]) ? -1 : (amount/coins[ind]));
        }
        int pick = -1;
        if(amount>=coins[ind]){
            int val = recCoinChange(coins, dp, amount-coins[ind], ind);
            if(val!=-1){
                pick = 1+val;
            }
        }
        int notPick = recCoinChange(coins, dp, amount, ind-1);
        int ans = -1;
        if(pick==-1){
            ans = notPick;
        }
        else if(notPick == -1){
            ans = pick;
        }
        else{
            ans = min(pick, notPick);
        }
        return dp[amount][ind] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int> (n, -2));
        sort(coins.begin(), coins.end());
        return recCoinChange(coins, dp, amount, n-1);
    }
//Time Complexity -> O(amount * n)
//Space Complexity -> O(amount * n) (Stack Space + DP array)
*/
//Tabulation
private:
    int auxCoinChange(vector<int>& coins, vector<vector<int>> &dp, int amount, int ind){
        int n = coins.size();
        for(int i = 0; i <= ind; i++){
            dp[0][i] = 0;
        }
        for(int amt = 0; amt <= amount; amt++){
            dp[amt][0] = (amt%coins[0])?-1:(amt/coins[0]);
        }
        for(int i = 1; i <= ind; i++){
            for(int amt = 1; amt <= amount; amt++){
                int pick = -1;
                if(amt>=coins[i]){
                    int val = dp[amt-coins[i]][i];
                    if(val!=-1){
                        pick = 1+val;
                    }
                }
                int notPick = dp[amt][i-1];
                int ans = -1;
                if(pick==-1){
                    ans = notPick;
                }
                else if(notPick == -1){
                    ans = pick;
                }
                else{
                    ans = min(pick, notPick);
                }
                dp[amt][i] = ans;
            }
        }
        return dp[amount][ind];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int> (n, -1));
        sort(coins.begin(), coins.end());
        return auxCoinChange(coins, dp, amount, n-1);
    }
//Time Complexity -> O(amount * n)
//Space Complexity -> O(amount * n) (Stack Space + DP array)
};

int main(){
    Solution sol;
    int n, amt;
    cin >> n >> amt;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    int ans = sol.coinChange(coins, amt);
    cout << ans << "\n";
    return 0;
}