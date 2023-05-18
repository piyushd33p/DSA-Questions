class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        for(int i = 0 ; i<= s.size(); i++){

            if(i == s.size() || s[i] == ' '){
                if(temp.size()){
                    st.push(temp);
                }
                temp = "";
            }
            else    temp += s[i];
        }

        temp = "";

        while(!st.empty()){
            temp += st.top() + ' ';
            st.pop();
        }

        temp.pop_back();
        return temp;
    }
};