class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int a = INT_MIN, cnt1 = 0;
        int b = INT_MIN, cnt2 = 0;

        for(int i= 0; i < n ;i++){
            if(a == INT_MIN && nums[i] != b){
                a = nums[i];
                cnt1 = 1;
            }
            else if(b == INT_MIN && nums[i] != a){
                b = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == a)   cnt1++;
            else if(nums[i] == b)   cnt2++;
            else if(nums[i] != a && nums[i] != b){
                if(cnt1 <= cnt2 ){
                    a = nums[i];
                    cnt1 = 1;
                }
                else{
                    b = nums[i];
                    cnt2 = 1;
                }
            }
        }
        cout<< cnt1 << "   "<< cnt2;
        if(cnt1 <= cnt2)    return b;
        else    return a;
    }
};