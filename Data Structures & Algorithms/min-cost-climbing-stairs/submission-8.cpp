class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        

        int n = cost.size();
        // vector<int>dp(n+1 , INT_MAX);
        // dp[0] = 0;
        // dp[1] = min(0 , (dp[0] + cost[0]));

        // these are the two conditions on which we are working we have
        // initialized the first step
       int prev1 = 0;
       int prev2 = 0;
        for( int i = 2 ; i <= n ; i++){
            int current = min(prev1+cost[i-1] , prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = current;

        }
        return prev1;
    }
};
