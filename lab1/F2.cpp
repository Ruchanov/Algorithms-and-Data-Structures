#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    // if( n == 1){
    //     cout<<2;
    //     return 0;
    // }
    // if(n == 2){
    //     cout<<3;
    //     return 0;
    // }
    stack<int>  st;
    st.push(2);
    st.push(3);
    int cnt = 2;
    int num = 5;
    bool res = true;
    while(cnt!=n){
        for(int i = 2;i <= sqrt(num);i++){
            if(num % i == 0){
                res = false;
            }
        }
        if( res == true){
            st.push(num);
        }else{
            res = true;
        }
        if(st.size() == n){
        cout<< st.top();
        }else{
            num += 2;
        }
    }
    return 0;
}