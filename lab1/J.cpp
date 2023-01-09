#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> d;
    while(true){
        char c;
        int n;
        cin>>c;
        if(c == '!'){
            return 0;
        }
        if(c == '+'){
            cin>>n;
            d.push_front(n);
        }if(c == '-'){
            cin>>n;
            d.push_back(n);
        }if(c == '*'){
            if(d.size()>1){
                cout<<d.front()+d.back()<<endl;
                d.pop_front();
                d.pop_back();
            }else if(d.size()==1){
                cout<<d.front() * 2<<endl;
                d.pop_front();
            }else{
                cout<<"error\n";
            }
        }
    }
    return 0;
}