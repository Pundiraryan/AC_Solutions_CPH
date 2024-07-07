int segt[2*maxn];
void build(int v,int tl,int tr,vi&arr){
    if(tl==tr){
        segt[v]=arr[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm,arr);
    build(2*v+1,tm+1,tr,arr);
    segt[v]=segt[2*v]+segt[2*v+1];
}
void update(int v,int tl,int tr,int pos,int x,vi&arr){
    if(tl==tr){
        segt[v]=x;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm){
        update(2*v,tl,tm,pos,x,arr);
    }
    else update(2*v+1,tm+1,tr,pos,x,arr);
    segt[v]=segt[2*v]+segt[2*v+1];
}
int sum(int v,int tl,int tr,int l,int r,vi &arr){
    if(l>r)return 0;
    if(l==tl&&r==tr){
        return segt[v];
    }
    int tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm),arr)+sum(2*v+1,tm+1,tr,max(tm+1,l),r,arr);
}