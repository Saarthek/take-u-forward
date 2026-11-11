class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            int rem = target - nums[i];
            if(mpp.find(rem)!=mpp.end()){
                ans = {i, mpp[rem]};
                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};