class Solution {
private:
    void find(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int target, int index){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            if(nums[i] > target)    break;

            if( i > index && nums[i] == nums[i-1]){
                continue;
            }

            ds.push_back(nums[i]);
            find(nums, ans, ds, target - nums[i], i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        sort(nums.begin(), nums.end());

        find(nums, ans, ds, target, 0);

        return ans;
    }
};