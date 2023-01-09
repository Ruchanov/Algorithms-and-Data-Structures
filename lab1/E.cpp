#include<iostream>
#include<queue>
using namespace std;

int main(){
    //int n,m = 5;
    queue <int> b,c;
    // while(n--){
    //     int x;
    //     cin>>x;
    //     b.push(x);
    // }
    // // n = 5;
    // while(m--){
    //     int x;
    //     cin>>x;
    //     c.push(x);
    // }
    for(int i = 0;i < 5;i++){
        int x;
        cin>>x;
        b.push(x);
    }
    for(int i = 0;i < 5;i++){
        int y;
        cin>>y;
        c.push(y);
    }
    int cnt = 0;
    while(true){
        cnt++;
        if(cnt == 1000000){
            cout<<"blin nichya";
            return 0;
        }
        int m = b.front();
        int k = c.front();
        b.pop();
        c.pop();
        if(m == 0 && k == 9){
            b.push(m);
            b.push(k);
        }
        else if(m == 9 && k == 0){
            c.push(m);
            c.push(k);
        }else if(m>k){
            b.push(m);
            b.push(k);
        }
        else if(m<k){
            c.push(m);
            c.push(k);
        }
        if(b.size() == 0){
            cout<<"Nursik "<<cnt;
            return 0;
        }
        if(c.size() == 0){
            cout<<"Boris "<<cnt;
            return 0;
        }
    }
    // if(b.empty()){
    //     cout<<"Nursik "<<cnt;
    // }
    // if(c.empty()){
    //     cout<<"Boris "<<cnt;
    // }

    return 0;

}
