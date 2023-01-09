#include <bits/stdc++.h>
using namespace std;
int sum = 0;

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
	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (cur->val > val) {
			cur->left = _insert(cur->left, val);
		} else if (cur->val < val) {
			cur->right = _insert(cur->right, val);
		}
		return cur;
	}
	void hero(Node* node, int level){
		if(!node) return;
		hero(node->left,level + 1);
		hero(node->right,level + 1);
		sum += node->val - level;
	}
public:
	Node* root;
	BST() {
		this->root = nullptr;
	}
	void insert(int val) {
		root = _insert(root, val);
	}
	void answer(){
		hero(root,0);
	}

};
int main() {
    BST bst;
	int n;
    cin >> n;
    for(int i = 0; i < n; i++){
		int x;
		cin >> x;
        bst.insert(x);
    }
	bst.answer();
	cout <<sum;
	return 0;
}