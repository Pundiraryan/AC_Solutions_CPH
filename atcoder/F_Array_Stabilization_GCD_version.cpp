#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int int64_t
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
struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
// http://xorshift.di.unimi.it/splitmix64.c
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};
#define umpl   unordered_map<ll,ll,custom_hash>
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
class SGTree
{
    vector<ll> seg;
 
public:
    SGTree(ll n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<ll> &v, ll low, ll high, ll idx)
    {
        if (low == high)
        {
            seg[idx] = v[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(v, low, mid, 2 * idx);
        build(v, mid + 1, high, 2 * idx + 1);
        seg[idx] = __gcd(seg[2 * idx], seg[2 * idx + 1]);
    }
    int maxi(int index, int l, int r, int start, int end)
    {
        if ((start > r) || (end < l))
        {
            return 0;
        }
        if ((start <= l) && (end >= r))
        {
            return seg[index];
        }
        int mid = (l + r) / 2;
        int lft = maxi((index * 2) , l, mid, start, end);
        int rght = maxi((index * 2) + 1, mid + 1, r, start, end);
        return __gcd(lft, rght);
    }
};
int logb2(ll x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vl nums(n);
        cin>>nums;
        unordered_set<int>st;
        for(auto &x:nums)st.insert(x);
        if(st.size()==1){
            cout<<0<<endl;continue;
        }
        SGTree segt(n);
        segt.build(nums,0,n-1,1);
        ll l=1,r=n;
        ll ans=r;
        auto check=[&](ll mid)->bool{
            unordered_set<ll>st;
            for(ll i=0;i<n;i++){
                ll eidx=(i+mid)%n;
                if(eidx>=i){
                    ll v1=segt.maxi(1,0,n-1,i,eidx);
                    // cout<<i<<" -- "<<v1<<endl;
                    st.insert(v1);
                }else{
                    ll v2=segt.maxi(1,0,n-1,0,eidx);
                    ll v3=segt.maxi(1,0,n-1,i,n-1);
                    // cout<<i<<" || "<<v2<<" || "<<v3<<endl;
                    st.insert(__gcd(v2,v3));
                }
            }
            return st.size()==1;
        };
        while(l<=r){
            ll mid=(l+r)>>1;
            // cout<<mid<<" -- "<<check(mid)<<endl;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}