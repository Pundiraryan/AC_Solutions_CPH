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
int logb2(ll x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
       int n;cin>>n;
       vi nums(n);
       cin>>nums;
       vector<int>po(n+1,0),pt(n+1,0);
       for(int i=1;i<=n;i++){
        po[i]=po[i-1]+(nums[i-1]==1);
        pt[i]=pt[i-1]+(nums[i-1]==2);
       }
       int q;cin>>q;
       while(q--){
        int l,r,k;cin>>l>>r>>k;
        ll co=po[r]-po[l-1],ct=pt[r]-pt[l-1];
        if(co>ct)swap(co,ct);
        ll len=r-l+1;
        ll pc=len-ct;
        ll poss=min({ct,co+k,pc});
        k-=(poss-co);
        co=poss;
        if(co==ct){
             k = min(k,len-(co+ct));
            co += (k + 1) / 2;
            ct += (k-1)/ 2;
            
            ll ans = (ll)co*ct;
            cout<<ans<<endl;
        }
       }else{
        
       }
    
    int q; cin >> q;
    
    while (q--){
        int l, r, k; cin >> l >> r >> k;
        
        int x = p1[r] - p1[l - 1];
        int y = p2[r] - p2[l - 1];
        
        if (x > y) swap(x, y);
        
        int reach = min({y, r - l + 1 - y, x + k});
        k -= reach - x;
        x = reach;
        
     //   cout << x << " " << y << "\n";
        
        int ans;
        
        if (x == y){
            // increase both
            k = min(k, r - l + 1 - x - y);
            x += (k + 1) / 2;
            y += k / 2;
            
            ans = x * y;
        } else if (k > 0){
            // change y to x 
            int nx = x + 2 * k;
            if (nx > y){
                int len = r - l + 1;
                ans = (len / 2) * ((len + 1) / 2);
            } else {
                x += k;
                y -= k;
                ans = x * y;
            }
        } else {
            ans = x * y;
        }
        
        
        cout << ans << "\n";
    }
}
    return 0;
}