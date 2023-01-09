#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if( n == 1){
        cout<<3;
        return 0;
    }
    int cnt = 2;
    int cnt2 = 1;
    int num = 5;
    bool res = true;
    bool res2 = true;
    while(cnt2!=n){
        for(int i = 2;i < (num / 2)+1;i++){
            if(num % i == 0){
                res = false;
            }
        }
        if( res == true){
            cnt++;
            for(int i = 2;i < cnt/2 + 1; i++){
                if(cnt%i == 0){
                    res2 =false;
                }
            }
            if(res2 == true){
                cnt2++;
                if(cnt2 == n){
                    cout<<num;
                }
            }else{
                res2 = true;
            }
        }else{
            res = true;
        }
        // if(cnt2 == n){
        // cout<<num;
        // }else{
        num += 2;
        // }
    }
    // if(cnt == n){
    //     cout<<num;
    // }
    return 0;
}