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

	void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->left);
		cout << node->val << " ";
		_inorder(node->right);
	}

	void _preorder(Node* node) {
		if (!node) return;
		cout << node->val << " ";
		_preorder(node->left);
		_preorder(node->right);
	}

	void _postorder(Node* node) {
		if (!node) return;
		_postorder(node->left);
		_postorder(node->right);
		cout << node->val << " ";
	}

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

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		if (cur->val < target) return _search(cur->right, target);
	}

public:
	BST() {
		this->root = nullptr;
	}

	void inorder() {
		_inorder(root);
		cout << endl;
	}
	
	void preorder(Node*cur) {
		_preorder(cur);
		cout << endl;
	}
	
	void postorder(Node* cur) {
		_postorder(cur);
		cout << endl;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}
	Node* search(int target) {
		return _search(root, target);
	}
};

int main() {
	BST bst;
	int n;
    cin>>n;
    for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		bst.insert(x);
	}
	int k;
	cin >> k;
	Node* target = bst.search(k);
	bst.preorder(target);
	return 0;
}