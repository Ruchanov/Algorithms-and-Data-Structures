#include<iostream>
#include<stack>

using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    stack<char> st,st2;
    for(int i = 0; i < s1.size();i++){
        if(s1[i]=='#'){
            st.pop();
        }else{
            st.push(s1[i]);
        }
    }
    for(int i = 0; i < s2.size();i++){
        if(s2[i]=='#'){
            st2.pop();
        }else{
            st2.push(s2[i]);
        }
    }
    if(st.empty() && st2.empty()){
        cout<<"Yes";
        return 0;
    }else if(st.empty() || st2.empty()){
        cout<<"No";
        return 0;
    }
    while(!st.empty() && !st2.empty()){
        char x = st.top();
        char y = st2.top();
        st.pop();
        st2.pop();
        if(x!=y){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
    
}