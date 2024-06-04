vector<vector<bool>> preprocess_substr_palindrome(string &s){
        int n=s.length();
        vector<vector<bool>> pal(n, vector<bool>(n, 0));
    for(int i = 0;i<n;i++) pal[i][i] = 1;
    for(int i = 0;i<n-1;i++){
        if(s[i] == s[i+1]) pal[i][i+1] = 1;
    }
    for(int i = 3;i<=n;i++){
        for(int j = 0;j<n-(i-1);j++){
            if(s[j] == s[j + i-1] && pal[j+1][j+i-2]){
                pal[j][j+i-1] = 1;
            }
        }
    }
        return pal;
    }