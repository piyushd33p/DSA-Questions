class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        int i = 0;
        while(i <= s.size()){
            if(s[i] == ' ' || i == s.size()){
                if(temp.size()){
                    ans = temp + " " + ans;
                }
                i++;
                temp = "";
            }else{
                temp += s[i];
                i++;
            }
        }   
        ans.pop_back();

        return ans;
        
    }
};