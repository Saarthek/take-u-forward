/*
This code is a solution for the Longest Substring Without Repeating Characters from LeetCode at
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Sliding window
        unordered_map<char, int> vis;
        int n = s.size();
        if(n==0){
            return 0;
        }
        int st = 0;
        int ans = 1;
        vis[s[0]] = 0;
        for(int i = 1; i < n; i++){
            if(vis.find(s[i])!=vis.end()){
                if(vis[s[i]]>=st){
                    st = vis[s[i]]+1;
                }
            }
            vis[s[i]] = i;
            ans = max(ans, i-st+1);
        }
        return ans;
    }
//Time Complexity -> O(n)
//Space Complexity -> O(unique Char) which is finite
};

int main(){
    Solution sol;
    string s;
    getline(cin, s);
    int ans = sol.lengthOfLongestSubstring(s);
    cout << ans << '\n';
    return 0;
}