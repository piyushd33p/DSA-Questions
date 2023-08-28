//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int sundays = S/7;
        int avlDays = S-sundays;
        
        int reqFood = S*M;
        
        int ans = 0;
        
        if(reqFood % N == 0){
            ans = reqFood / N;
        }
        else    ans = reqFood/N + 1;
        
        if(ans <= avlDays)   return ans;
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends