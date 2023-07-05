class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int start = 0, end = nums.size()-2;

        int mid = start +(end - start)/2;

        while(start <= end){

            if(mid % 2 == 0){
                if(nums[mid + 1] != nums[mid])  end = mid-1;
                else    start = mid+1;
            }
            else{
                if(nums[mid+1] != nums[mid] )   start = mid+1;
                else end = mid-1;
            }

            mid = start + (end - start)/2;
        }
        return nums[mid];
    }
};