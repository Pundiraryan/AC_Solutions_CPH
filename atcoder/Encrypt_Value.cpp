#include<bits/stdc++.h>
#define int int64_t
#define mod 1000000007;
using namespace std;
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int tc=1;
    cin>>tc;
    while(tc--){
        int n;
        cin >> n;
        int val[n];
        for(int i=0;i<n;i++)cin>>val[i];
        sort(val,val+n);
        unordered_map<int,int>fre;
        for(int i=0;i<n;i++)fre[val[i]]++;
        int res=val[0];
        for(int i=1; i<n; i++){
            // cout<<res<<" -- ";
            if(res==1){
                res+=val[i];
                fre[val[i]]--;
            }
            else{
                if(val[i]!=1){
                    res=(res*val[i]);
                }else{
                    res+=val[i];
                }
                if(fre[val[i]]<0){
                    fre.erase(fre.find(val[i]));
                }
            }
            res%=mod;
        }
        cout<<res<<endl;
    }
    return 0;
}