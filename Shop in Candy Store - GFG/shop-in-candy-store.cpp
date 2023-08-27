//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        
        sort(candies, candies+n);
        
        int mini = 0;
        int buy = 0;
        int gift = n-1;
        
        while(buy <= gift){
            mini += candies[buy];
            buy++;
            gift -= k;
        }
        
        int maxi = 0;
        buy = n-1;
        gift = 0;
        
        while(gift <= buy){
            maxi += candies[buy];
            buy--;
            gift += k;
        }
        
        return {mini, maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends