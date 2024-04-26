  ll even=2;
    cout<<1<<" ";
    ll odd=3;
    ll currnum = odd;
    ll cnt = 0;
    while(cnt<k-1){
        if(currnum%2===0){
            cout<<odd<<" ";
            currnum = odd;
            odd+=2;
          
        }
        else{
              cout<<even<<" ";
            even+=2;
            currnum = even;
        }
        cnt++;
    }

    // cout<<currnum<<endl;
    // cout<<odd<<endl;
    if(currnum%2==1){
        while(odd<=n){
            cout<<odd<<" ";
            odd+=2;
        }
        while(even<=n){
            cout<<even<<" ";
            even+=2;
        }
    }
    else{
        while(even<=n){
            cout<<even<<" ";
            even+=2;
        }
         while(odd<=n){
            cout<<odd<<" ";
            odd+=2;
        }
        
    }
    cout<<endl;