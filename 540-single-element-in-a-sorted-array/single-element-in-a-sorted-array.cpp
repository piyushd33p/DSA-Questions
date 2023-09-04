class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        if(nums.size() == 1)    return nums[0];
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(mid == 0 && nums[mid] != nums[mid+1])  
                return nums[mid];
            else if(mid == nums.size()-1 && nums[mid-1] != nums[mid])
                return nums[mid];
            else if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }

            else if(mid%2 == 0 && nums[mid] == nums[mid+1]){
                s = mid+1;
            }
            else if(mid%2 == 0 && nums[mid] != nums[mid+1]){
                e = mid-1;
            }
            else if(mid%2 !=0 && nums[mid] == nums[mid+1]){
                e = mid-1;
            }
            else if(mid%2 != 0 && nums[mid] != nums[mid+1]){
                s = mid+1;
            }
        }
        return -1;
    }
};