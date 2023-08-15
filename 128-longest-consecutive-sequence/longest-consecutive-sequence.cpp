class Solution {
private:
// B R U T E
    // bool search(vector<int>& nums, int ele){
    //     for(auto it: nums){
    //         if(it == ele)   return 1;
    //     }
    //     return 0;
    // }
public:
    int longestConsecutive(vector<int>& nums) {
        int n  = nums.size();
        int maxConsec = 0;
        int curr = 1;

        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        for(int i = 0 ; i < n ; i++){

            if(i == 0)  last = nums[i];
            

            if(nums[i] - 1 == last){
                curr++;
            }
            else if(nums[i]  != last){

                curr = 1;
            }
                maxConsec = max(maxConsec, curr);
                last = nums[i];
        }

        return maxConsec;
    }
};

        // B R U T E 

        // for(int i = 0 ; i < n ; i++){
        //     int temp = nums[i];
        //     int currConsec = 0;
        //     while(search(nums, temp) == true){
        //         currConsec++;
        //         temp++;
        //     }
        //     maxConsec = max(maxConsec, currConsec);
        // }