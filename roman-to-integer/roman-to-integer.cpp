class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;

        int i = s.size()-1;
        while(i>=0){
            // char ch = s[i];
            if( i-1 >= 0 && ( mp[s[i]] > mp[s[i-1]] )){
            //   char cha = s[i-1];
                ans += mp[s[i]] - mp[s[i-1]];
                i -= 2;
            }
            else{
                ans += mp[s[i]];
                i--;
            }
        }
        return ans;
    }
};