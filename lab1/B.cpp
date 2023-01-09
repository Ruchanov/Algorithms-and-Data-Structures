#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n; i++ ){
        cin>>a[i];
    }
    bool res = true;
    for(int i = 0;i < n; i++ ){
        for(int j = i-1; j >= 0; j-- ){
            if(a[j]<=a[i]){
                cout<<a[j]<<" ";
                res = false;
                break;
            }
        }
        if( res == true){
            cout<<-1<<" ";
        }
        res = true;
    }
    return 0;
}