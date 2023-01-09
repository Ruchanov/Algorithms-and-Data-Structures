#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string,string>& a, pair<string,string>& b){
    return a.first < b.first;
}

int partition(vector<pair<string,string>>& a, int l, int r){
    int i = l - 1;
    int pivot = r;
    for(int j = l; j < r; j++){
        if(comp(a[j], a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(vector<pair<string,string>>& a, int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<string,string>> v;
    string first,last;
    bool res = true;
    for(int i = 0; i < n; i++){
        cin >> first >> last;
        for(int j = 0; j < v.size(); j++){
            if(v[j].second == first){
                v[j].second = last;
                res = false;
            }
        }
        if(res == true){
            v.push_back(make_pair(first,last));
        }else{
            res = true;
        }
    }
    qsort(v, 0, v.size() - 1);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}