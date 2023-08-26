class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i= 1; i<nums.size(); i++){
            if(nums[i] == nums[i-1])
                count++;
            else
                nums[i-count] = nums[i];
        }
        return nums.size() - count;
    }
};
        // int count = 0;
        // if(nums.size() == 1)    return 1;
        // int i =0, j = 0;

        // while( i < nums.size() && j< nums.size()){
        //     count++;
        //     nums[i] = nums[j];

        //     while(nums[i] == nums[j] && j < nums.size()){

        //         j++;
        //     }
        //     i++;
        // }
        // return count;