class Solution {
public:
    unordered_map<int,unordered_map<int,int>>dp;
    int f(int i,int cr,vector<int>&nums){
        if(i==nums.size())return 0;
        if(dp.find(i)!=dp.end() && dp[i].find(cr)!=dp[i].end())return dp[i][cr];
        int idx=upper_bound(nums.begin(),nums.end(),cr+nums[i])-nums.begin();
        int take=nums[i]+f(idx,cr+nums[i],nums);
        int nt=f(i+1,cr,nums);
        return dp[i][cr]=max(take,nt);
    }
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n+1);
         unordered_map<int,int>fre;
            int ans=0;
        for(int i=0;i<n;i++){
            dp[i].push_back(nums[i]);
            fre[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                for(auto it:dp[j]){
                    if(nums[i]>it and fre[nums[i]+it]==0){
                        dp[i].push_back(nums[i]+it);
                        fre[nums[i]+it]++;
                        ans=max(ans,nums[i]+it);
                    }
                }
            }
        }
       
        
        return ans;
    }
};