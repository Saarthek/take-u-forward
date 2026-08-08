/*
    Problem: Valid Sequence
    Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/

    Input:
        word1, word2

    Output:
        Vector of indices forming a valid sequence.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
/*
//Recursion
private:
    bool recValidSeq(string &word1, string &word2, int i, int j, int n1, int n2,
                     vector<int>& ans, bool onech) {
        int chkp = ans.size();
        if (j >= n2) {
            return true;
        }
        if (i >= n1) {
            return false;
        }
        if (word1[i] == word2[j]) {
            ans.push_back(i);
            return recValidSeq(word1, word2, i + 1, j + 1, n1, n2, ans, onech);
        }
        else if (!onech) {
            ans.push_back(i);
            if (recValidSeq(word1, word2, i + 1, j + 1, n1, n2, ans, true)) {
                return true;
            }
            ans.resize(chkp);
        }
        return recValidSeq(word1, word2, i + 1, j, n1, n2, ans, onech);
    }

public:
    vector<int> validSequence(string word1, string word2) {
        // w1[i] == w2[j] -> include
        // w1[i] != w2[j] -> exclude, or pick if dissimilar character not picked
        vector<int> ans;
        int n1 = word1.size();
        int n2 = word2.size();
        if (recValidSeq(word1, word2, 0, 0, n1, n2, ans, false)) {
            return ans;
        }
        return vector<int>(0);
    }
    // Time Complexity: O(2^n1)
    // Space Complexity: O(n1)
    */
//Memoization
private:
    int recValidSeq(string &word1, string &word2, vector<vector<vector<int>>> &dp, int i, int j, int n1, int n2, vector<int>& ans, bool onech){
        int &m = dp[i][j][onech];
        if(m!=-1){
            return m;
        }
        int chkp = ans.size();
        if(j>=n2){
            return m=true;
        }
        if(i>=n1){
            return m=false;
        }
        if(word1[i]==word2[j]){
            ans.push_back(i);
            return m=recValidSeq(word1, word2, dp, i+1, j+1, n1, n2, ans, onech);
        }
        else if(!onech){
            ans.push_back(i);
            if(recValidSeq(word1, word2, dp, i+1, j+1, n1, n2, ans, true)){
                return m=true;
            }
            ans.resize(chkp);
        }
        return m=recValidSeq(word1, word2, dp, i+1, j, n1, n2, ans, onech);
    }
public:
    vector<int> validSequence(string word1, string word2) {
        // w1[i]==w2[j] -> include
        // w1[i]!=w2[j] -> exclude, or pick (pick if not one dissimilar was not picked)
        vector<int> ans;
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(2, -1)));
        if(recValidSeq(word1, word2, dp, 0, 0, n1, n2, ans, false)){
            return ans;
        }
        return vector<int>(0);
    }
    // Time Complexity: O(n1*n2)
    // Space Complexity: O(n1*n2) (DP array + stack space)
};

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    Solution sol;
    vector<int> ans = sol.validSequence(word1, word2);
    for (int idx : ans) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}