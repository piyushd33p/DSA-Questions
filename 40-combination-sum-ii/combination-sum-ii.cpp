class Solution {
private:
    void find(vector<int>& nums, int target, int n, vector<vector<int>>& ans, vector<int>& temp, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < n; i++){
            if(nums[i] > target)    break;
            if(i > index && nums[i] == nums[i-1])   continue;

            temp.push_back(nums[i]);
            find(nums, target - nums[i],n, ans, temp, i+1);
            temp.pop_back();
        }
        


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;

        vector<vector<int>> ans;
        find(nums, target, nums.size(), ans, temp, 0);

        return ans;
    }
};