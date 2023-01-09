#include<iostream>
#include<deque>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        deque<int> d;
        // d.push_back(x);
        for(int i = x;i>0;i--){
            d.push_front(i);
            for(int j = 1; j <= i;j++){
                d.push_front(d.back());
                d.pop_back();
            }
        }
        while(!d.empty()){
            int x = d.front();
            d.pop_front();
            cout<<x<<" ";

        }
        cout<<endl;
    }
    return 0;
}