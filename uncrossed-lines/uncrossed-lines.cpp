class Solution {
public:

    int findM(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if((i<0 && j>=0) || (j<0 && i>=0) || (i<0 && j<0))  return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        if(nums1[i] == nums2[j])     
            return  dp[i][j] =  1 + findM(i-1, j-1, nums1, nums2, dp);
        else        
            return dp[i][j] =  max(findM(i-1, j, nums1, nums2, dp) , findM(i, j-1, nums1, nums2, dp));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        if(nums1 == nums2)  return nums1.size();

        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));

        return findM(nums1.size()-1, nums2.size()-1, nums1, nums2, dp);

    }
};