#include <bits/stdc++.h>
using namespace std;
queue<pair<int,pair<int, vector<int>>>> q;
set<int> s;
int x, y;
void findd(int v, int u){
	q.push({v, {0, {}}});
	while(!q.empty()){
		int a = q.front().first;
		int step = q.front().second.first;
		vector<int> temp = q.front().second.second;
		temp.push_back(a);
		if(a == u){
			cout << step << endl;
			for(int i = 1; i < temp.size(); i++){
				cout << temp[i] << " ";
			}
			return;
		}
		q.pop();
		if(s.count(a - 1> 0 && a - 1) != 1){
			q.push({a - 1,{ step + 1, temp}}); 
			s.insert(a - 1);
		}if(s.count(2 * a > 0 && 2 * a) != 1){
			q.push({2 * a, {step + 1, temp}});
			s.insert( 2 * a);	
		}

	}

}

int main() {
	int x, y;
	cin >> x >> y;
	if(x > y){
		cout << x - y << endl;
		while(x != y){
			x--;
			cout << x << " ";
		}
		return 0;
	}
	findd(x, y);
	return 0;
}