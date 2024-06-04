class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=2e9;
        int prefnums[31][n];

    for (int i = 0; i < 31; i++) {

        prefnums[i][0] = ((nums[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            prefnums[i][j] = ((nums[j] >> i) & 1);
            prefnums[i][j] += prefnums[i][j - 1];
        }
    }
    auto rand=[&](int l, int r)->int
{
 
    // To store the answer
    int ans = 0;
    for (int i = 0; i < 31; i++) {
        // To store the number of variables
        // with ith bit set
        int x;
        if (l == 0)
            x = prefnums[i][r];
        else
            x = prefnums[i][r]
                - prefnums[i][l - 1];
 
        // Condition for ith bit
        // of answer to be set
        if (x == r - l + 1)
            ans = (ans | (1 << i));
    }
 
    return ans;
};
        for(int i=0;i<n;i++){
            int l=i,r=n;
            int mindiff=2e9;
            while(l<=r){
                int mid=(l+r)>>1;
                int rand=rangeand(i,mid);
                if(rand>=k){
                    mindiff=min(mindiff,abs(rand-k));
                    l=mid+1;
                }else{
                    r=mid-1;
                }
                
            }
            ans=min(ans,mindiff);
        }
        return ans;
    }
};