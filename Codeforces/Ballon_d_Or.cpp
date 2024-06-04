#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define endl "\n"
#define mod 1000000007
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n>>s;
        if(n==1){
            cout<<-1<<endl;
        }
        else if(n%2==0){
            if(s%2==0){
                if(s>=n){
                    int p=s/n,pp=s%n;
                    for(int i=0; i<n; i++){
                        if(pp){
                            cout<<p+1<<" ";
                            pp--;
                        }
                        else{
                            cout<<p<<" ";
                        }
                    }
                    cout<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            if(s%2){
                cout<<-1<<endl;
            }
            else{
                if(n>3){
                    if(s>=(n+3)){
                        cout<<1<<" "<<2<<" "<<3<<" ";
                        n-=3;
                        s-=6;
                        int p=s/n,pp=s%n;
                        for(int i=0; i<n; i++){
                            if(pp){
                                cout<<p+1<<" ";
                                pp--;
                            }
                            else{
                                cout<<p<<" ";
                            }
                        }
                        cout<<endl;
                    }
                    else{
                        cout<<-1<<endl;
                    }
                }
                else{
                    if(s<6 || s==(1<<((int)log2(s)))){
                        cout<<-1<<endl;
                    }
                    else{
                        
                    }
                }
            }
        }
    }
    return 0;
}