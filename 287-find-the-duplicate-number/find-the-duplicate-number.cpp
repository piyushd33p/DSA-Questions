class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;

        for(auto it : nums){
            mp[it]++;
            if(mp[it] > 1)  return it;
        }
        return -1;
    }
};

// sort(nums.begin(), nums.end());
        // int ans = 0;
        // for(int i = 1 ; i < n ; i++){
        //     if(nums[i] == nums[i+1]){
        //         ans = nums[i];
        //         break;
        //     }
        // }

        // return ans;