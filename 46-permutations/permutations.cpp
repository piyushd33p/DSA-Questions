class Solution {
private:
    void findPerm(vector<int>& nums, vector<int>& vis,vector<vector<int>>& ans,vector<int>& temp, 
        int n, int index){

        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){

                vis[i] = 1;
                temp.push_back(nums[i]);

                findPerm(nums, vis, ans, temp, n, index+1 );

                vis[i] = 0;
                temp.pop_back();
            }
        }

    }


public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n  = nums.size();

        vector<int> vis(n, 0);
        vector<vector<int>> ans;
        vector<int> temp;

        findPerm(nums, vis,ans, temp,n, 0);

        return ans;
    }
};