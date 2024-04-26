
class Solution {
public:
int minimumOperations (vector<vector<int>>& grid) {
int n = grid.size(), m = grid[0].size();
vector<vector<int>> dp (m + 1, vector<int>(10, (int)19)); 
for (int i = 0; i < 10; i++) dp[0][i] = 0;
for (int j = 0; j < m; j++) {
for (int k = 0; k <= 9; k++) {
int m = 0;
for (int i = 0; i < n; i++) m += grid[i][j] != k;

dp[j+1][k] = min(dp[j+1][k], dp[j][l] + m);
for (int k = 0; k <= 9; k++) ans = min(ans, dp[m][k]); return ans 1e9 ? -1: ans;
}
};