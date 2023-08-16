class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st;
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        int count = st.size();
        int maxPossible = n/2;

        if(count > maxPossible)     return maxPossible;
        else  return count;
    }
};