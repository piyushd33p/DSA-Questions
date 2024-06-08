class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0, two = 0, zero  =0;

        for(auto it: nums){
            if(it == 0) zero++;
            if(it == 1) one++;
            if(it == 2) two++;
        }

        for(int i =0; i  < nums.size(); i++){
            if(i < nums.size() - (one + two))   nums[i] = 0;
            else if(i < nums.size() - two)   nums[i] = 1;
            else    nums[i] = 2;
        }
    }
};