/*
This code is a solution of the problem Climb Stairs from leetcode at the link
https://leetcode.com/problems/climbing-stairs/
The solution progresses from brute force to optimal
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:  
    //Recursion
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        else{
            return climbStairs(n-1)+climbStairs(n-2);
        }

    }
   //Memoization
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    int ans = sol.climbStairs(n);
    cout << ans;
    return 0;
}