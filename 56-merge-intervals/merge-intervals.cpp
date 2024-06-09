class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> v(2);

        sort(intervals.begin(), intervals.end());

        v[0] = intervals[0][0];
        v[1] = intervals[0][1];

        int mini = 0, maxi = 0;

        for(int i = 0 ; i < intervals.size(); i++){
            mini = intervals[i][0];
            maxi = intervals[i][1];

            if(mini <= v[1]){
                v[1] = max(maxi, v[1]);
                if(mini <= v[0]){
                    v[0] = min(mini, v[0]);
                }
            }
            else{
                ans.push_back(v);
                v[0] = mini;
                v[1] = maxi;
            }
        }

        if(ans.empty() || v != ans.back()){
            ans.push_back(v);
        }
        return ans;

        
    }
};