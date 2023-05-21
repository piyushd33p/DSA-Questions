class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;

        for(int i =0 ; i< s.size(); i++){
            mp[s[i]]++;
        }
        
        vector<pair<int, char>> v;

        for(auto i : mp){
            v.push_back(make_pair(i.second, i.first));
        }

        sort(v.rbegin(), v.rend());

        s.erase();

        for(int i = 0; i < v.size(); ++i){
            int j = v[i].first;

            while(j){
                s += v[i].second;
                j--;
            }
        }
        
        return s;
    }
};

