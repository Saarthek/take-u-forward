class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            int rem = target - nums[i];
            if(mpp[rem]!=0){
                ans = {mpp[rem]-1, i};
                return ans;
            }
            mpp[nums[i]] = (i+1);
        }
        return ans;
    }
};