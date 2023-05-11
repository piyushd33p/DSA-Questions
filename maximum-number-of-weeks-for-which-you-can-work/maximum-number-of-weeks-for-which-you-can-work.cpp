class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long totalTask = 0;
        long long maxTask = *max_element(milestones.begin(),milestones.end());

        for(auto i : milestones)    totalTask += i;

        long long remTask = totalTask - maxTask;

        if(remTask > maxTask || remTask == maxTask || remTask == maxTask+1)     return  totalTask;
        else    return remTask*2 +1;
    }
};