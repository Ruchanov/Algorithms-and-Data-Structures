#include <iostream>
using namespace std;

int partition(string& s, int left, int right) {
	int pivot = s[right];
	int index = left - 1;
	for (int i = left; i < right; i++) {
        if (s[i] < pivot) {
			index++;
			swap(s[i], s[index]);
		}
	}
	swap(s[index + 1], s[right]);
	return index + 1;
}


void quick_sort(string& s, int left, int right) {
	if (left < right) {
		int p = partition(s, left, right);
		quick_sort(s, left, p - 1);
		quick_sort(s, p + 1, right);
	}
}

int main() {
	string s;
    cin >> s;
    quick_sort(s, 0, s.size() - 1);
    cout << s;
	return 0;
}