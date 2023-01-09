#include <iostream>
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

	Node* _search(Node* cur, int target) {
		if (!cur)
			return nullptr;
		if (cur->val == target)
			return cur;
		if (cur->val > target)
			return _search(cur->left, target);
		return _search(cur->right, target);
	}

public:
	BST() {
		this->root = nullptr;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root)
			root = newNode;
	}

	Node* search(int target) {
		return _search(root, target);
	}
    int getHeight(Node *node) {
		if (!node) return 0;
		int left = getHeight(node->left);
		int right = getHeight(node->right);
		return max(left, right) + 1;
	}
  	
};


int main() {
    BST bst;
	int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        bst.insert(x);
    }
    int k;
    cin >> k;
    cout << bst.getHeight(bst.search(k)); 
	return 0;
}