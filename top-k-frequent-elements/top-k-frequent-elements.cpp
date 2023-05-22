class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;

        map<int, int> mp;

        for(int i = 0 ; i< nums.size(); i++)     mp[nums[i]]++;

        priority_queue<pair<int, int>> p;

        for(auto it : mp){
            p.push(make_pair(it.second, it.first));
        }

        for(int i = 0 ; i< k ; i++){
            ans.push_back(p.top().second);
            p.pop();
        }

        return ans;
        
    }
};