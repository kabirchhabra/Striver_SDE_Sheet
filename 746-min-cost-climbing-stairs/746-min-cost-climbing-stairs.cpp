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

// // Using memoization
// class Solution{
// private:
//     int solve(vector<int> &cost, vector<int> &dp, int n){
//         if(n==0 || n==1) return dp[n]=cost[n];
//         if(dp[n]!=-1) return dp[n];
        
//         int ans = cost[n] + min(solve(cost, dp, n-1), solve(cost, dp, n-2));
//         dp[n] = ans;
//         return dp[n];
//     }
// public:
//     int minCostClimbingStairs(vector<int> &cost){
//         int n = cost.size();
//         vector<int> dp(cost.size(), -1);
//         int ans = min(solve(cost, dp, n-1), solve(cost, dp, n-2));
        
//         return ans;
//     }
// };

// //using tabulation
// class Solution{
// public:
//     int minCostClimbingStairs(vector<int> &cost){
//         int n = cost.size();
//         vector<int> dp(n+1, -1);
        
//         dp[0] = cost[0];
//         dp[1] = cost[1];
//         for(int i=2;i<n;i++){
//             dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//         }
        
//         return min(dp[n-1], dp[n-2]);
//     }
// };


// Space Optimization in tabulation
class Solution{
public:
    int minCostClimbingStairs(vector<int> &cost){
        int prev2 = cost[0];
        int prev1 = cost[1];
        for(int i=2;i<cost.size();i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1, prev2);
    }
};