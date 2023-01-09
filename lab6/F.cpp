#include <bits/stdc++.h>

using namespace std;

double getGPA(string s){
    if(s == "A+") return 4;
    if(s == "A") return 3.75;
    if(s == "B+") return 3.5;
    if(s == "B") return 3;
    if(s == "C+") return 2.5;
    if(s == "C") return 2;
    if(s == "D+") return 1.5;
    if(s == "D") return 1;
    if(s == "F") return 0;
}
bool comp(pair<pair<string, string>, double>& a, pair<pair<string, string>, double>& b){
    if(a.second == b.second && a.first.first == b.first.first) return a.first.second < b.first.second;
    if(a.second == b.second) return a.first.first < b.first.first;
    return a.second < b.second;
}
int partition(vector<pair<pair<string, string>, double>>& a, int l, int r){
    int i = l - 1;
    int pivot = r;
    for(int j = l; j < r; j++){
        if(comp(a[j],a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(vector<pair<pair<string, string>, double>>&  a, int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<pair<string, string>, double>> v;
    while(n--){
        string surname, name;
        int subNums;
        cin >> surname >> name >> subNums;
        double sum = 0;
        double totalCredits = 0;
        while(subNums--){
            string gr;
            int credit;
            cin >> gr >> credit;
            totalCredits += credit;
            sum += getGPA(gr) * credit; 
        }
        double res = sum / totalCredits;
        v.push_back(make_pair(make_pair(surname,name),res));
    }
    qsort(v, 0, v.size() - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first.first << " " << v[i].first.second << " " << fixed << setprecision(3) << v[i].second << endl;
    }

    return 0;
}