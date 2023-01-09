#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, double> p1, pair<int, double> p2) { // hint, which data structure you should use
	if (p1.first * p1.second == p2.first * p2.second) {
		return p1.first < p2.first;
	}
	return p1.first * p1.second < p2.first * p2.second;
}
int binarySearch(vector<pair<int,double>> v, int target, int size) {
	int left = 0, right = size - 1;
    int diff = INT_MAX;
    int in = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target < v[mid].first * v[mid].second) {
            if(diff>abs(target-v[mid].first * v[mid].second)){
                diff = abs(target-v[mid].first * v[mid].second);
                in = mid;
            }
			right = mid - 1;
		} else if (target > v[mid].first * v[mid].second) {
            if(diff>abs(target-v[mid].first * v[mid].second)){
                diff = abs(target-v[mid].first * v[mid].second);
                in = mid;
            }
			left = mid + 1;
		} else {
			return mid;
		}
	}
	return in;
}

int main() {
    vector<pair<int,double>> v;
    int n,k;
    cin >> n >> k;
    while(n--){
        int x;
        double y;
        cin >> x >> y;
        //pair<x,y>
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),comp);
    int x = binarySearch(v,k,v.size());
    cout<<v[x].first<<" "<<v[x].second;
	return 0;
}