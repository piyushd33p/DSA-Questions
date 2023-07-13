class Solution {
private:
    void solve(int index,vector<int>& nums, int target, vector<int>& temp, 
                vector<vector<int>>& ans){

        if(index == nums.size()){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            return;
        }

        if(nums[index] <= target){
            temp.push_back(nums[index]);

            solve(index, nums, target - nums[index], temp, ans);

            temp.pop_back();
        }

        solve(index+1, nums, target, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        int index = 0;

        solve(index, candidates, target, temp, ans);

        return ans;
    }
};