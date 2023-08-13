class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ele1 = INT_MIN, cnt1 = 0;
        int ele2 = INT_MIN, cnt2 = 0;
        vector<int> ans;

        for(auto it: nums){
            if(cnt1 == 0  && it!= ele2){
                ele1 = it;
                cnt1++;
            }
            else if(cnt2 == 0 && it!= ele1){
                ele2 = it;
                cnt2++;
            }
            else if(it == ele1)   cnt1++;
            else if(it == ele2)   cnt2++;

            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for(auto  it:nums){
            if(it == ele1)  cnt1++;
            else if(it == ele2) cnt2++;
        }

        if(cnt1 > n/3)     ans.push_back(ele1);
        if(cnt2 > n/3)     ans.push_back(ele2);
        return ans;
        
    }
};
        // map<int,int> mp;
        // vector<int> ans;

        // for(auto it: nums){
        //     mp[it]++;
        //     if(mp[it] > n/3)    ans.push_back(it);
        // }