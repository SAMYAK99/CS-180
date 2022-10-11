class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n);
        dp[0] = "1";
        for (int i = 1; i < n; i++) {
            int count = 0;
            char cur = dp[i - 1][0];
            for (char c : dp[i - 1]) {
                if (c == cur) count++;
                else {
                    dp[i] += to_string(count) + cur;
                    count = 1;
                    cur = c;
                }
            }
            dp[i] += to_string(count) + cur;
        }
        return dp[n - 1];
    }
};
