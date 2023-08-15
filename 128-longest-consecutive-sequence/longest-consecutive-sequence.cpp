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
        
        unordered_set<int> st;

        for(auto it: nums)  st.insert(it);

        for(auto it: st){
            if(st.find(it -1) == st.end()){
                int temp = it;
                int count = 1;

                while(st.find(temp+1) != st.end()){
                    count++;
                    temp = temp+1;
                }
                maxConsec = max(maxConsec, count);
            }
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