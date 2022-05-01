// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        // your code here
        vector<pair<int,int>>v;
        vector<int>v2;
        for(int i=0;i<n;i++){
         v.push_back(make_pair(arr[i].profit,arr[i].dead));
        }
       
        int counting=0, profit=0, k=v.size();
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int array[v.size()]={0};
        for (int i=0;i<v.size();i++) {
           for(int j=min(k,v[i].second-1);j>=0;j--) {
               if(array[j]==false) {
                   counting++;
                   profit=profit+v[i].first;
                   array[j]=true;
                   break;
                   
               }
           }
       }
       v2.push_back(counting);
       v2.push_back(profit);
       
       return v2;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends