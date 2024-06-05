class Solution {
private:
    void find(vector<int>& nums, vector<vector<int>>& ans, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            find(nums, ans, index+1);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        find(nums, ans, 0);

        return ans;
    }
};