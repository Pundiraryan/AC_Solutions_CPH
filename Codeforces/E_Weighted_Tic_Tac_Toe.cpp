long long pie(vector<int> &nums, long long x,long long k)
    {
        int n = nums.size();
        long long cnt = 0;
        for (int mask=1;mask<(1<<n);mask++)
        {
            long long lv=1;
            for (int bit=0;bit<n;bit++)
            {
                if (mask&(1<<bit))
                {
                    lv=lcm(lv,nums[bit]);
                }
            }
            if (__builtin_popcount(mask) & 1)cnt += x/lv;
            else cnt -= x/lv;
        }
        return cnt;
    }