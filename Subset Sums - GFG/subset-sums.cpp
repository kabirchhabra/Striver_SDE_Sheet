// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    vector<int> v;
private:
    void solve(vector<int> &arr, int N, int i=0, int sum=0){
        if(i==N){ 
            v.push_back(sum);
            return;
        }
        solve(arr, N, i+1, sum+arr[i]);
        solve(arr, N, i+1, sum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        // Write Your Code here
        solve(arr,N);
        return v;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends