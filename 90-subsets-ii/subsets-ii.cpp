class Solution {
private:
    void getSub(vector<int>& nums, int n, int index, set<vector<int>>& st, vector<int>& temp){
        if(index == n){
            st.insert(temp);
            return;
        }

        temp.push_back(nums[index]);
        getSub(nums, n, index+1, st, temp);

        temp.pop_back();
        getSub(nums, n, index+1, st, temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        int index = 0;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        getSub(nums, n, index, st, temp);

        vector<vector<int>> ans;
        for(auto it: st){
            ans.push_back(it);
        }

        return ans;
    }
};