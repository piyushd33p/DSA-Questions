class Solution {
    void subs(vector<int>& nums, int index, int n,
                 set<vector<int>> &st, vector<int>&ds){

        if(index == n){
            st.insert(ds);
            return;
        }

        ds.push_back(nums[index]);
        subs(nums, index+1, n, st, ds);

        ds.pop_back();
        subs(nums, index+1, n, st, ds);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        subs(nums, 0, n, st,ds);

        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    
    }
}; 