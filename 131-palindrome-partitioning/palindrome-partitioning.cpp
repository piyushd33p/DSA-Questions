class Solution {
private:

    bool isPal(string s, int low, int high){
        while(low <= high){
            if(s[low] != s[high])   return 0;
            low++;
            high--;
        }
        return 1;
    }

    void findPart(string s, vector<vector<string>>& ans, vector<string>& temp, int index)
    {
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPal(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                findPart(s, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        findPart(s, ans, temp, 0);

        return ans;
    }
};