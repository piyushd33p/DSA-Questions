class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.size(), m = goal.size();

        if( n!= m)      return false;
        if(s == goal)   return true;
        string temp = "";
        for(int  i = 1; i<n; i++){
            temp = s[0];

            s = s.substr(1, n) + temp;
            if(s == goal)   return true;
        }
        return false;
        
    }
};