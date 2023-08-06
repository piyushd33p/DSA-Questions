class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i+1] == nums[i]){
                ans = nums[i];
                break;
            }
        }

        return ans;

        // int n = nums.size();
        
        // sort(nums.begin(), nums.end());

        // int low = 1, high = n;

        // while(low <= high){
        //     int mid = low + (high - low)/2;
        //     if((nums[mid] == nums[mid+1] && mid+1 <= n)) {
        //         return nums[mid];
        //     }
        //     if(nums[mid] == nums[mid-1] && mid-1 >=0)  return nums[mid];
        //     else if(mid == nums[mid])   low = mid+1;
        //     else    high = mid-1;
        // }
        // return -1;
    }
};


// map<int,int> mp;

//         for(auto it : nums){
//             mp[it]++;
//             if(mp[it] > 1)  return it;
//         }
//         return -1;

// sort(nums.begin(), nums.end());
        // int ans = 0;
        // for(int i = 1 ; i < n ; i++){
        //     if(nums[i] == nums[i+1]){
        //         ans = nums[i];
        //         break;
        //     }
        // }

        // return ans;