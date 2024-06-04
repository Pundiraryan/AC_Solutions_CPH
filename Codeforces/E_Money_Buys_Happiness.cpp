#define ll long long
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ll ans=0;
        ll maxi=1e6;
        unordered_map<ll,ll>freq,divfreq;
        for(auto &x:nums1)freq[x]+++;
        for (auto &x:nums2) {
            ll sv=x*k,dc=0;
            if (divfreq.count(sv)) {
                ans+=divfreq[sv];
                continue;
            }
            
            for (ll fac=sv;fac<=maxi;fac+=sv) {
                if(freq.count(fac)) {
                    dc +=freq[fac];
                }
            }

            divfreq[sv]=dc;
            ans+=dc;
        }

        return ans;
    }
};