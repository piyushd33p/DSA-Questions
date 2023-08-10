class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())    return false;

        map<char, int> mp;
        for(int i = 0 ; i< s.size(); i++){
            char ch = s[i];
            mp[ch]++;
        }

        for(int i = 0 ; i< t.size(); i++){
            char ch = t[i];
            if(mp.find(ch) == mp.end() || mp[ch] == 0)     return false;
            mp[ch]--;
        }
        return true;
    }
};