// // Using Recursion but will give TLE
// class Solution {
// private:
//     int solve(vector<int> &cost, int n){
//         if(n==0 || n==1) return cost[n];
        
//         int ans = cost[n] + min(solve(cost,  n-1), solve(cost, n-2));
        
//         return ans;
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int ans = min(solve(cost, n-1), solve(cost,n-2));
        
//         return ans;
//     }
// };

// Using DP
class Solution{
private:
    int solve(vector<int> &cost, vector<int> &dp, int n){
        if(n==0 || n==1) return dp[n]=cost[n];
        if(dp[n]!=-1) return dp[n];
        
        int ans = cost[n] + min(solve(cost, dp, n-1), solve(cost, dp, n-2));
        dp[n] = ans;
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int> &cost){
        int n = cost.size();
        vector<int> dp(cost.size(), -1);
        int ans = min(solve(cost, dp, n-1), solve(cost, dp, n-2));
        
        return ans;
    }
};