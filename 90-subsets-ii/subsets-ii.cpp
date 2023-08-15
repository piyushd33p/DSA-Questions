class Solution {
private:
    void subSum(int index, vector<int>& nums, vector<int>& ds, int n, set<vector<int>>& st){
        if(index == n){
            st.insert(ds);
            return;
        }
        ds.push_back(nums[index]);

        subSum(index+1, nums, ds, n, st);

        ds.pop_back();
        subSum(index+1, nums, ds, n, st);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        int n = nums.size();

        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        subSum(0, nums, ds, n, st);

        vector<vector<int>> ans;

        for(auto it:st)     ans.push_back(it);

        return ans;
    }
};