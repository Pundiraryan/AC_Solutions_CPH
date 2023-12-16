// Author- Aryan Pundir
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag,
tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
#define ll          long long
#define lli         long long int
#define ld          long double
#define vl          vector<ll>
#define vi          vector<int>
#define vs          vector<string>
#define vpi          vector<pair<int,int>>
#define vpl          vector<pair<ll,ll>>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define qi          queue<int>
#define ql          queue<ll>
#define pb          push_back
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define mpi          map<int,int>
#define si          set<int>
#define msi          multiset<int>
#define sl          set<ll>
#define msl          multiset<ll>
#define mpl          map<ll,ll>
#define mpcl          map<char,ll>
#define pqi          priority_queue<int>
#define pql          priority_queue<ll>
#define mpql          priority_queue <ll,vl ,greater<ll>>
#define mod          1000000007
#define mod1          998244353
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<' '; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
const ll maxn = 2e5+5 ;
#define inf 1e18 
// Sieve of Eratosthenes
const int N=1300000;
const int nax=1e9+1;
bool isPrime[N];
vector<int> primes;
void sieve(int n=N) {
fill(isPrime + 2, isPrime + n, true);
primes.pb(2);
for (ll i=3;i*i<=nax;i++) {
bool isPrime =true;
for (auto p : primes) {
if (i % p == 0) {
isPrime = false;
break;
}
}
if (isPrime) {
primes.push_back(i);
}
}
}
ll factorial[maxn];
void calcfact()
{
factorial[0] = 1;
for (ll i = 1; i < maxn; i++) 
factorial[i] = (factorial[i - 1] * i) % mod; 
}
ll power(ll x, ll y)
{
ll res = 1;
 x = x % mod;
if (x == 0)
return 0;
while (y > 0)
 {
if (y & 1ll)
res = (res * x) % mod;
 y = y >> 1ll;
 x = (x * x) % mod;
}
return res;
}
ll power(ll x, ll y, ll p)
{
ll res = 1; // Initialize result
x = x % p; // Update x if it is more than or equal to p
while (y > 0)
{
// If y is odd, multiply x with result
if (y & 1)
res = (res * x) % p;
// y must be even now
y = y >> 1; // y = y/2
x = (x * x) % p;
}
return res;
}
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
return power(n, p - 2, p);
}
ll nCrModPFermat(ll n,ll r, ll p)
{
if (n < r)
return 0;
if (r == 0)
return 1;
ll fac[n + 1];
fac[0] = 1;
for (int i = 1; i <= n; i++)
fac[i] = (fac[i - 1] * i) % p;
return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)% p;
}
ll accurateFloor(ll a, ll b) {
ll val = a / b;
while (val * b > a)
val--;
return val;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi nums(n);
        for(int i=0;i<n;i++)cin>>nums[i];
        string s;cin>>s;
        vi prexor(n,0);
        prexor[0]=nums[0];
        for(int i=1;i<n;i++){
            prexor[i]=prexor[i-1]^nums[i];
        }
        int zz=0,oz=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zz^=nums[i];
            }else{
                oz^=nums[i];
            }
        }
        int q;
        cin>>q;
        while (q--)
        {
            int type;cin>>type;
            if(type==2){
                int val;cin>>val;
                if(val)cout<<oz<<" ";
                else cout<<zz<<" ";
            }else{
                int l,r;
                cin>>l>>r;
                if(l!=1){
                    int xorval=prexor[r-1]^prexor[l-2];
                    oz^=xorval;
                    zz^=xorval;
                }
                else{
                    oz^=prexor[r-1];
                    zz^=prexor[r-1];
                }
            }
        }
        cout<<endl;
        
    }
    return 0;
}