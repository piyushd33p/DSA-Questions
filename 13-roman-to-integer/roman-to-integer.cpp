class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;


        int n = s.size();
        int i = 0;

        int finalNum = 0;

        while(i < n){
            if(mp[s[i+1]] > mp[s[i]]){
                finalNum += mp[s[i+1]] - mp[s[i]];
                i+=2;
            }
            else{
                finalNum += mp[s[i]];
                i++;
            }
        }
        // if(i == n-1)    finalNum += mp[s[i+1]];

        return finalNum;
        
        
    }
};