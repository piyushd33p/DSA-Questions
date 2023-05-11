class Solution {
public:

    // int findM(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
    //     if((i<0 && j>=0) || (j<0 && i>=0) || (i<0 && j<0))  return 0;
    //     if(dp[i][j] != -1)  return dp[i][j];

    //     if(nums1[i] == nums2[j])     
    //         return  dp[i][j] =  1 + findM(i-1, j-1, nums1, nums2, dp);
    //     else        
    //         return dp[i][j] =  max(findM(i-1, j, nums1, nums2, dp) , findM(i, j-1, nums1, nums2, dp));
    // }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        if(nums1 == nums2)  return nums1.size();

        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));

        int n = nums1.size(), m = nums2.size();

        for(int i = 0 ; i<=n; i++)  dp[i][0] = 0;
        for(int j = 0 ; j<=m; j++)  dp[0][j] = 0;

        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                if(nums1[i-1] == nums2[j-1])    dp[i][j] = 1+ dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];

    }
};