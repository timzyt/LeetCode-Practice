class Solution {
    public int longestPalindromeSubseq(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) { // 需要从末尾开始算 这样才能使用递归
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j]); // 保证所有的dp值是算过的
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = Math.max(dp[i + 1][j - 1] + 2, dp[i][j]);
                }  
            }
        }
        return dp[0][n - 1];
    }
}
