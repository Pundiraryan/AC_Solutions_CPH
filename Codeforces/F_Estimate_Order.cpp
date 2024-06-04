class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3)return false;
        unordered_set<char>allv={'a','e','i','o','u','A','E','I','O','U'};
        bool check1=false,check2=false;
        for(auto &x:word){
            if(allv.find(x)!=allv.end()){
                check1=true;
            }else{
                if(isalpha(x))check2=true;
            }
        }
        if(!check1)return false;
        if(!check2)return false;
        for(auto &x:word){
            if(!isdigit(x) && !isupper(x) && !islower(x))return false;
        }
        return true;
    }
    
};