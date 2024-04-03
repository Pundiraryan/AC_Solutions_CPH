
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>t;
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}
signed main()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int nums[n];
    t.resize(4*n+5);
    for(int i=0;i<n;i++)cin>>nums[i];
	for (int i = 0; i < q; i++) {
        int tp;cin>>tp;
		if (tp == 1) {
            int a,b,u;cin>>a>>b>>u;
			update(1,0,n-1,a,b,u);
		}
		else {
            int a;cin>>a;
            cout<<nums[a-1]+get(1,0,n-1,a)<<endl;
		}
	}
  return 0;
}
  