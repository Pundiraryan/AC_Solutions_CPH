class SGTree
{
    vector<int> seg;
 
public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<int> &v, int low, int high, int idx)
    {
        if (low == high)
        {
            seg[idx] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(v, low, mid, 2 * idx);
        build(v, mid + 1, high, 2 * idx + 1);
        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
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
        return max(lft, rght);
    }
};