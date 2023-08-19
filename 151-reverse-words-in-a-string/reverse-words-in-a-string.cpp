class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        int n(s.length()), i(0);

        string temp = "";

        
        while(s[i] == ' ' && i<n)  i++;

        while(i < n ){
            int j = i;

            if(s[j] == ' ' && j < n){
                while(s[j] == ' ' && j<n)   j++;
            }

            while( s[j] != ' '  && j<n){
                temp += s[j];
                j++;
            }
            if(temp != "")  st.push(temp);
            temp = "";
            i = j+1;

        }

        s = "";

        while(!st.empty()){
            s += st.top();
            st.pop();
            s += ' ';
        }
        s.pop_back();

        return s;

    }
};