class Solution {
public:
    int numTrees(int n) {
        
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i <= n; i ++) {
            int result = 0;
            for (int j  = 1; j <= i; j ++) {
                result += dp[j-1] * dp[i-j];
            }
            dp[i] = result;
        }
        return dp[n];
    }
};