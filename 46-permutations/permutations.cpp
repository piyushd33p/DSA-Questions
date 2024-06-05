class Solution {
private:
    void find(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, vector<int>& mp){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!mp[i]){
                ds.push_back(nums[i]);
                mp[i] = 1;

                find(nums, ans, ds, mp);

                mp[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        vector<int> mp(nums.size(), 0);

        find(nums, ans, ds, mp);

        return ans;
    }
};