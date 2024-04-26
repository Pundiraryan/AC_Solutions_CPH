class Solution {
public:
bool check2(pair<int, int> fp, pair<int, int> sp) {
    return fp.first <= sp.first && fp.second >= sp.second;
}
bool check(pair<int, int> point, pair<int, int> fp, pair<int, int> sp) {
    int x = point.first;
    int y = point.second;
    int cx1 = fp.first;
    int cy1 = fp.second;
    int cx2 = sp.first;
    int cy2 = sp.second;
    if (!check2(fp, sp)) return false;
    if (cx1 <= x && x <= cx2 && cy1 >= y && y >= cy2)return true;
    return false;
}
    int numberOfPairs(vector<vector<int>>& coords) {
        int n=coords.size();
        vector<pair<int,int>> pts;
        for(auto &x:coords){
            pts.push_back({x[0],x[1]});
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                     if(check2(pts[i],pts[j])){
                    bool valid=true;
                    for(int k=0;k<n;k++){
                        if(k==i or k==j){continue;}
                        if(check(pts[k],pts[i],pts[j])){
                            valid=false;
                            break;
                        }
                    }
                    if(valid)res++;
                }
                }
               
            }
        }
        return res;
    }
};