class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for(int i = 0; i< arr.size()-1; i++){
            int commonDiff = arr[i+1] - arr[i];
            if(commonDiff != d)     return false;
        }
        return true;
    }
};