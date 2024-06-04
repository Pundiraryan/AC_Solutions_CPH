class Solution {
    unordered_map<int, vector<vector<int>>> dp;
    int f(int i, int jump, bool can,int k) {
        if (i >=k+2)return 0;
        if(jump > 31)return 0;
        if(dp.count(i) && dp[i][jump][can] != -1)return dp[i][jump][can];
        int ans = (i == k);
        if (can)ans += f(i - 1, jump, 0,k);
        long long val=i+(1<<jump);
        if (val<=k+1)ans += f(k, i + (1 << jump), jump + 1, 1,k);

        dp[i].resize(32, vector<int>(2, -1));

        return dp[i][jump][can] = ans;
    }
public:
    int waysToReachStair(int k) {
        return f(1, 0, 1,k);
    } 
};