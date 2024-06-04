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
// z[i] - ith index se start substring ka kitna prefix match karta string ke prefix se (z[0]=))int pref[M], c;
int pref[2000066];
string longestprefixpalindrome(string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    int c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        if(n==1){
            cout<<s<<endl;continue;
        }  
        int i=0,j=n-1;
        while(i<j && s[i]==s[j]){
            i++;j--;
        }
        string ans="";
        if(i)ans+=s.substr(0,i);
        if (n> 2 *i)
        {
            string str = s.substr(i,n-2*i);
            string a = longestprefixpalindrome(str);
            reverse(all(str));
            string b = longestprefixpalindrome(str);
            if(a.length()>=b.length())ans+=a;
            else ans+=b;
        }
        if(i){
            ans+=s.substr(j+1,i);
        }
        cout<<ans<<endl;
    //     int p = 10;
    //     vector<long long> p_pow(n+1); 
    //     p_pow[0] = 1; 
    // for (int i = 1; i < (int)p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * p) % mod;
    //     vl fhash(n);
    //     vl bhash(n);
    //     fhash[0]=(s[i]-'a'+1);
    //     bhash[n-1]=((s[n-1]-'a'+1)*p_pow[0])%mod;
    //     for(ll i=1;i<n;i++){
    //         fhash[i]=(fhash[i-1]+(s[i]-'a'+1)*p_pow[i])%mod;
    //     }
    //     for(ll i=n-2;i>=0;i--){
    //         bhash[i]=(bhash[i+1]+(s[i]-'a'+1)*p_pow[n-i-1])%mod;
    //     }
    //     cout<<" ----- \n";
    //     cout<<fhash<<endl;
    //     cout<<bhash<<endl;
    //     cout<<" ----- \n";
    //     while (i<n && j>=0 && s[i]==s[j])
    //     {
    //         i++,j--;
    //     }
    //     cout<<i<< " || "<<j<<endl;
    //     for(int a=i;a<=j;a++){
    //         ll fhv=fhash[a]-fhash[i-1];
    //         ll bhv=bhash[i]-bhash[a+1];
    //         cout<<fhv<<" }}  "<<bhv<<endl;
    //     }
    //     cout<<" ))) "<<endl;
    //     for(int b=i;b<=j;b++){
    //         ll fhv=fhash[j]-fhash[b-1];
    //         ll bhv=bhash[b]-bhash[j+1];
    //         cout<<fhv<<" ^^ "<<bhv<<endl;
    //     }
        
        
    }
    return 0;
}