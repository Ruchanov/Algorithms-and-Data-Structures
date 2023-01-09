#include<iostream>
#include<vector>
#include<queue>
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
	Node* getRoot() {
		return root;
	}
};

void countTriangles(Node* node, vector<int>& ans) {
	Node* left = node->left;
	Node* right = node->right;
	int i = 0;
	while (left != nullptr && right != nullptr) {
		ans[i]++;
		left = left->left;
		right = right->right;
		i++;
	}
}

int main() {
	BST bst;
	int n, node;
	cin >> n;
	vector<int> ans(n - 1);
	while (n--) {
		cin >> node;
		bst.insert(node);
	}
	queue<Node*> q;
	q.push(bst.getRoot());
	while (!q.empty()) {
		Node* node = q.front();
		q.pop();
		countTriangles(node, ans);
		if (node->left) q.push(node->left);
		if (node->right) q.push(node->right);
	}

	for (auto i : ans) {
		cout << i << " ";
	}

	return 0;
}