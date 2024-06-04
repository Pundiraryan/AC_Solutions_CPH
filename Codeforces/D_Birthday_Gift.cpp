class SGTree
{
    vector<long long> seg;
 
public:
    SGTree(long long n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<long long> &v, long long low, long long high, long long idx)
    {
        if (low == high)
        {
            seg[idx] = v[low];
            return;
        }
        long long mid = (low + high) / 2;
        build(v, low, mid, 2 * idx);
        build(v, mid + 1, high, 2 * idx + 1);
        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
    }
    long long maxi(int index, int l, int r, int start, int end)
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
        return max(lft, rght);
    }
    void update(int index,int l,int r,int pos,int x){
        if(l==r){
            seg[index]+=x;
            return;
        }
        int tm=(l+r)/2;
        if(pos<=tm){
            update(2*index,l,tm,pos,x);
        }
        else update(2*index+1,tm+1,r,pos,x);
        seg[index]=max(seg[2*index],seg[2*index+1]);
        }
};
