#include <iostream>
using namespace std;

bool vowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		return true;
	}
	return false;
}
bool comp(char c1, char c2){
    if(vowel(c1) && vowel(c2)) return c1 < c2;
    if((vowel(c1) && !vowel(c2))) return true;
    if((!vowel(c1) && vowel(c2))) return false;
    return c1 < c2;

}
int partition(char a[], int l, int r){
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


void qsort(char a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}



int main() {
	int n;
    cin >> n;
    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    qsort(a, 0, n-1);
    for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	return 0;
}