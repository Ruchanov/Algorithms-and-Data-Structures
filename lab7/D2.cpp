#include <iostream>
#include<vector>
#include<iomanip>

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

vector<pair<pair<string, string>, double>> merge(vector<pair<pair<string, string>, double>>& a, vector<pair<pair<string, string>, double>>& a1){
    int i = 0, j = 0;
    vector<pair<pair<string, string>, double>> ans;
    while(i < a.size() && j < a1.size()){
        if(comp(a[i],a1[j])){
            ans.push_back(a[i++]);
        }else{
            ans.push_back(a1[j++]);
        }
    }
    while(i < a.size()){
        ans.push_back(a[i++]);
    }
    while(j < a1.size()){
        ans.push_back(a1[j++]);
    }
    return ans;
}

vector<pair<pair<string, string>, double>> mergeSort(vector<pair<pair<string, string>, double>>& a, int l, int r){
    if (l == r) {
		return { a[l] };
	}
    if(l < r){
        int mid = l + (r - l) / 2;
        vector<pair<pair<string, string>, double>> l1 = mergeSort(a, l, mid);
        vector<pair<pair<string, string>, double>> r1 = mergeSort(a, mid + 1, r);
        return merge(l1, r1);
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
    vector<pair<pair<string, string>, double>> ans = mergeSort(v, 0, v.size() - 1);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first.first << " " << ans[i].first.second << " " << fixed << setprecision(3) << ans[i].second << endl;
    }

    return 0;
}