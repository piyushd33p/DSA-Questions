//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void subSum(int index, vector<int>&arr, int n, vector<int>& ans, int sum){
        if(index == n){
            ans.push_back(sum);
            return;
        }
        
        sum += arr[index];
        subSum(index+1, arr, n, ans, sum);
        
        sum -= arr[index];
        subSum(index+1, arr, n, ans, sum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        int sum = 0;
        
        subSum(0, arr, n, ans, sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends