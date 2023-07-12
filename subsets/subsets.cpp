class Solution {
private: 
    void solve(int index, int n, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        if(index ==  n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(index+1, n, nums, ans, temp);

        temp.pop_back();
        solve(index+1, n, nums, ans, temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        int index = 0;
        vector<vector<int>> ans;
        solve(index, n, nums, ans, temp);
        return ans;
    }
};