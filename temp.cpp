#define ll long long
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll n=maxHeights.size();
        ll ans=0;
        stack<ll>st;
        vector<vector<ll>>dp(n,vector<ll>(2,0));
        for(int i=0;i<n;i++){
            while(!st.empty() && maxHeights[i]<=maxHeights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                dp[i][0]=max(dp[i][0],(ll)(i-st.top())*(ll)maxHeights[i]+dp[st.top()][0]);
            }else{
                dp[i][0]=(ll)(i+1)*(ll)maxHeights[i];
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && maxHeights[i]<=maxHeights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                dp[i][1]=max(dp[i][1],(ll)(st.top()-i)*(ll)maxHeights[i] +dp[st.top()][1]);
            }else{
                dp[i][1]=(ll)(n-i)*(ll)maxHeights[i];
            }
            st.push(i);
        }
        ans=max(ans,max(dp[n-1][0],dp[0][1]));
        for(ll i=0;i<n-1;i++){
            ans=max(ans,dp[i][0]+dp[i+1][1]);
        }
        return ans;
    }
};