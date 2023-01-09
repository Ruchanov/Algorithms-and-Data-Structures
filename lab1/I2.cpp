#include<iostream>
#include<deque>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0; i < s.size();i++){
        for(int j = i+1; j < s.size();j++){
            if(s[i] != s[j]){
                s.erase(j);
                break;
            }
        }
    }
    bool res = true;
    char test = s[0];
    for(int i = 0;i < s.size();i++){
        if(test != s[i]){
            res = false;
        }
    }
    if(res == true and test == 'K'){
        cout<<"KATSURAGI";
    }else if( res == true and test == 'S'){
        cout<<"SAKAYANAGI";
    }
    return 0;
}