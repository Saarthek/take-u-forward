/*
This code is a solution for the problem kth smallest element in the array from leetcode at the link
https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
//Sort the array
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
//Time Complexity -> O(n*log n)
//Space Complexity -> O(1)
*/
/*
//Naive Priority Queue
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        int ans = pq.top();
        for(int i = 0; i < k; i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
//Time Complexity -> O(n*log n)
//Space Complexity -> O(n)
*/
//Priority queue
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        int ans = pq.top();
        return ans;
    }
//Time Complexity -> O(n*log k)
//Space Complexity -> O(k) 
};

int main(){
    Solution sol;
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = sol.findKthLargest(arr, k);
    cout << ans << '\n';
    return 0;
}