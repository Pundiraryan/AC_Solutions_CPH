class Solution {
public:
    int minSwaps(string s) {
      int n=s.length();
        int co=0,cz=0;
        for(auto &x:s){
            co+=(x=='1');
            cz+=(x=='0');
        }
        int ans=1e9;
        if(abs(co-cz)>=2)return -1;
        vector<int>c1(n,-1),c2(n,-1);
        int fc1=0,fc2=1;
        int co1=co,co2=co,cz1=cz,cz2=cz;
        for(int i=0;i<n;i++){
            if(fc1 && co1){
                c1[i]=fc1;
                co1--;
            }
            if(!fc1 && cz1){
                c1[i]=!fc1;
                cz1--;
            }
            if(fc2 && co2){
                c2[i]=fc2;
                co2--;
            }
            if(!fc2 && cz2){
                c2[i]=!fc2;
                cz2--;
            }
            fc1^=1;
            fc2^=1;
        }
        bool v1=true,v2=true;
        for(int i=0;i<n;i++){
            if(c1[i]==-1)v1=false;
            if(c2[i]==-1)v2=false;
        }
        if(v1){
            int cnt=0;
             for(int i=0;i<n;i++){
                 int val=s[i]-'0';
                 if(val!=c1[i])cnt++;
             }
            ans=min(ans,cnt);
        }
         if(v2){
            int cnt=0;
             for(int i=0;i<n;i++){
                 int val=s[i]-'0';
                 if(val!=c2[i])cnt++;
             }
            ans=min(ans,cnt);
        }
        return ans;
    }
};