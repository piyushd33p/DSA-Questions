class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        if(len == 0)    return 0;

        int i =0;
        double ans = 0;

        while( i < len && s[i] == ' ')      i++;

        int sign = 1;
        s = s.substr(i);

        if(s[0] == '-'){
            sign = -1;
            i = 1;
        }else if(s[0] == '+')   i = 1;
        else    i = 0;

        while(i < s.length() ){
            if(s[i] == ' ' || !(isdigit(s[i]))) break;

            ans = ans *10 + s[i]-'0';

            if(sign == -1 &&  -1*ans < INT_MIN)     return INT_MIN;
            if(sign == 1 &&  ans > INT_MAX)     return INT_MAX;

            i++;
        }

        return  ans*sign;


        
    }
};