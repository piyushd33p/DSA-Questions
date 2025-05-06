class Solution {
private:
    char to_lower(char s){
            if((s <= 'z' && s >= 'a') || (s >= '0' && s <= '9'))    return s;

            
                char temp = s - 'A' +'a' ;
            return temp;
        
    }

    bool isPal(string s){
        int i = 0, j = s.length()-1;

        while( i <= j){
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    }
public:
    bool isPalindrome(string s) {
        string temp = "";

        //checking if the character is alphanumeric or not 
        for(auto it : s){
            if(isalnum(it))
            {  
                char f = to_lower(it);
                temp.push_back(f);
            }
        }

        return isPal(temp);
        
    }
};