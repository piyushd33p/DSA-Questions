class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = INT_MIN, cnt1 = 0;
        int n2 = INT_MIN, cnt2 = 0;
        int n = nums.size();

        for(auto it : nums){
            if(cnt1 == 0 && it != n2)
            {
                n1 = it;
                cnt1 = 1;
            }
            else if(cnt2 == 0 && it != n1){
                n2 = it;
                cnt2 = 1;
            }
            else if(it == n1)   cnt1++;
            else if(it == n2)   cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        vector<int> ans;

        for(auto it: nums){
            if(it == n1)    cnt1++;
            if(it == n2)    cnt2++;

        }

        if(cnt1 > n/3)  ans.push_back(n1);
        if(cnt2 > n/3)  ans.push_back(n2);
        
        return ans;
    }
};