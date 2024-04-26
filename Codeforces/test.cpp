 vector<int>spf;
 void sieve(int n)
{
    spf[1] = 1;
    for (int i = 2; i < n; i++)spf[i] = i;
    for (int i = 4; i < n; i += 2)spf[i] = 2;
    for (int i = 3; i * i < n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < n; j += i){
                if (spf[j] == j)spf[j] = i;
            }
        }
    }
}

vector<int> factorise(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    while(ret.size()>1){
    
        
    }
    return ret;
}