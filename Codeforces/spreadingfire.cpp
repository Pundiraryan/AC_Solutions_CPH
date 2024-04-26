#include<bits/stdc++.h>
using namespace std;

int fun(int m, int n, int k, vector<pair<int, int>> &arr, int r, int t){
    int ans = 0;
    r *= t;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            bool flag = true;
            for(int l=0; l<k; l++){
                int dist = (i-arr[l].first)
                *(i-arr[l].first) + (j-arr[l].second)*(j-arr[l].second);
                if(dist <= r*r){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    int m, n, k;
    cin>>m>>n>>k;
    vector<pair<int, int>> arr(k);
    for(int i=0; i<k; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    int r, t;
    cin>>r>>t;
    cout<<fun(m, n, k, arr, r, t)<<endl;
    return 0;
}