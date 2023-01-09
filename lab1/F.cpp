#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if( n == 1){
        cout<<2;
        return 0;
    }
    if(n == 2){
        cout<<3;
        return 0;
    }
    int cnt = 2;
    int num = 5;
    bool res = true;
    while(cnt!=n){
        for(int i = 2;i < (num / 2)+1;i++){
            if(num % i == 0){
                res = false;
            }
        }
        if( res == true){
            cnt++;
        }else{
            res = true;
        }
        if(cnt == n){
        cout<<num;
        }else{
            num += 2;
        }
    }
    return 0;
}