class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());

        int i =0 , j = 0, n = strs.size();

        while( i< strs[0].size() && j < strs[n-1].size()){

            if(strs[0][i] != strs[n-1][j])  break;

            ans += strs[0][i];

            i++;
            j++;

        }
        return ans;
    }
};