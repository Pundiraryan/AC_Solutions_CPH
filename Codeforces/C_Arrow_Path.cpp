class Solution {
public:
    string minimizeStringValue(string s) { 
        map<char,int> fre;  
        int ptr=0;  
        int n=s.size();       
        vector<int> qps;
        for(auto &x:s){
            if(x!='?')fre[x]++;
        }
    
        for(int i=0;i<n;i++){  
            if(s[i]=='?'){
                qps.push_back(i);
            }
        }  
        int qmc=qps.size();
        vector<char> res;          
        for(int i=0;i<qps.size();i++){  
            int freq=2e9;  
            for(char c='a';c<='z';c++){  
                freq=min(fre[c],freq);  
            }    
            for(char c='a';c<='z';c++){  
                if(freq==fre[c]){  
                    res.push_back(c);  
                    fre[c]++;  
                    break;  
                }  
            }  
        }  
        sort(res.begin(),res.end());  
        for(int i=0;i<qps.size();i++){  
            s[qps[i]]=res[ptr];  
            ptr++;  
        }  
        return s;  
          
    }
};