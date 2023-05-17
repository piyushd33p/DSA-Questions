class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        map<int,int> mp;

        int left = 0, right = 0;

        while(right < s.size()){
            if(mp.find(s[right]) != mp.end() && mp[s[right]] >=left)
                left = mp[s[right]] +1 ;

            mp[s[right]] = right;

            int tempLen = right - left +1;
            maxLen = max(maxLen, tempLen);
            right++;
        }
        return maxLen;


        // int maxLen = 0;
        // set<int> st;
        // int left = 0 , right = 0;

        // // while(right < s.size()){
        // //     if(st.find(s[right]) == st.end()){
        // //         st.insert(s[right]);
        // //         int tempLen = right - left +1;
        // //         maxLen = max(maxLen, tempLen);
        // //         right++;

        // //     }
        // //     else{
        // //         while(st.find(s[right]) != st.end()){
        // //             st.erase(s[left]);
        // //             left++;
        // //         }
        // //         int tempLen = right - left +1;
        // //         maxLen = max(maxLen, tempLen);
        // //         st.insert(s[right]);
        // //         right++;
        // //     }
        // // }
        // // return maxLen;

        // for(int i = 0; i <s.size(); ++i){
        //     string st = "";
        //     int tempLen = 0;

        //     for(int j = i; j< s.size(); ++j){
        //         if(st.find(s[j]) == -1){
        //             st += s[j];
        //             tempLen++;
        //             maxLen = max(maxLen, tempLen);
        //         }
        //         else    break;
        //     }
        // }
        // return maxLen;
    }
};