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
    int _getLeaves(Node* node){
        if(!node){
            return 0;
        }
        if(!node->left && !node->right){
            return 1;
        }
        return _getLeaves(node->left) + _getLeaves(node->right);
    }
	
public:
	Node* root;
	BST() {
		this->root = nullptr;
	}
	void insert(int val) {
		root = _insert(root, val);
	}
    void getLeaves(){
        cout << _getLeaves(root);
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
    bst.getLeaves();
	return 0;
}