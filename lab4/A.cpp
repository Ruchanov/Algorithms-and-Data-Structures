#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
private:
	Node* root;
	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}
public:
	BST() {
		this->root = nullptr;
	}
	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}
	bool routeFound(string route) {
		Node* cur = root;
		for (auto c : route) {
			if (c == 'L') cur = cur->left;
			else cur = cur->right;
			if (!cur) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	BST bst;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bst.insert(x);
	}
	while (k--) {
		string s;
		cin >> s;
		if (bst.routeFound(s)) {
			cout << "YES"<<endl;
		} else {
			cout << "NO"<<endl;
		}
	}

	return 0;
}