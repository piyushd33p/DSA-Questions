class Solution {
private:
    void findSub(vector<int>& nums, set<vector<int>>& st, int index, vector<int>& ds){
        if(index == nums.size()){
            st.insert(ds);
            return;
        }

        ds.push_back(nums[index]);
        findSub(nums, st, index+1, ds);

        ds.pop_back();
        findSub(nums, st, index+1, ds);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        set<vector<int>> st;
        vector<int> ds;

        sort(nums.begin(), nums.end());
        findSub(nums, st, 0, ds);

        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};