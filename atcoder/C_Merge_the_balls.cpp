long long dp[205][205][405][3];
#define mod 1000000007
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        function<long long(int, int, int, int)> solve = [&](int i, int j, int last, int prev) -> long long {
            int len = (zero - i) + (one - j);
            if (len - last > limit)
                return 0;

            if (i == 0 && j == 0)
                return 1;

            if(dp[i][j][last][prev] != -1)
                return dp[i][j][last][prev];

            long long ans = 0;
            if (i > 0) {
                int new_last = last;
                if (prev == 1)
                    new_last = len;
                ans = solve(i - 1, j, new_last, 0);
            }
            if (j > 0) {
                int new_last = last;
                if (prev  == 0)
                    new_last = len;
                ans = (ans + solve(i, j - 1, new_last, 1)) % mod;
            }

            return dp[i][j][last][prev] = ans;
        };
        
        for(int i = 0; i <= zero; i++)
            for(int j = 0; j <= one; j++)
                for(int k = 0; k <= one + zero; k++)
                    for(int l = 0; l <= 2; l++)
                        dp[i][j][k][l] = -1;
        return solve(zero, one, 0, 2);
    }
};
