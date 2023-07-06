// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int start = 1, end = nums.size()-2;
//         int mid = start +(end-start)/2;

//         if(nums.size() == 1)    return 0;

//         if(nums[0] > nums[1])   return 0;
//         if(nums[nums.size()-1] > nums[nums.size()-2])   return nums.size()-1;

//         while(start <= end){
//                 if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])  break;
//                 else if(nums[mid] > nums[mid-1] )   start = mid+1;
//                 else    end = mid-1;
            
            
//             mid = start + (end-start)/2;
//         }
//         return mid;
//     }
// };


class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        int s = 1,  e = n-2;
        int mid = s + (e-s)/2;

        if(n == 1)  return 0;
        if(nums[0] > nums[1])   return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])   return nums.size()-1;


        while(s<=e){
            
            if(nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid])     break;
            
            else if(nums[mid] > nums[mid-1] )   s = mid+1;
            else     e = mid-1;
        
            mid = s + (e-s)/2;
        }
        return mid;
    }
};