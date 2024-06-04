class Solution {
private:
    void find(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& ds, int index){
        if(index == nums.size()){
            if(target == 0)
                ans.push_back(ds);
            
            return;
        }
        int curr = nums[index];
        if(curr <= target){
            ds.push_back(curr);
            find(nums, target-curr, ans, ds, index);
            ds.pop_back();
        }

        find(nums, target, ans, ds, index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        find(nums, target, ans, ds, 0);

        return ans;
        
    }
};