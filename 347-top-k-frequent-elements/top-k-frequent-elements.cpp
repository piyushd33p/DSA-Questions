class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<int> pq;
        priority_queue<pair<int,int>> pq2;
        vector<int> ans;

        for(auto it: nums)  pq.push(it);

        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();

            int cnt = 1;

            while(pq.top() == temp && !pq.empty()){
                cnt++;
                pq.pop();
            }
            pq2.push({cnt, temp});
        }

        int cnt = 0;

        while(cnt < k && !pq2.empty()){
            ans.push_back(pq2.top().second);
            pq2.pop();
            cnt++;
        }

        return ans;

    }
};