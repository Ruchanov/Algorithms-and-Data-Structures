#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

struct BST{
    private:
        Node* root;
        Node* _insert(Node* cur,int val){
            if(!cur) return new Node(val);
            if(val < cur->val){
                cur->left =_insert(cur->left,val);
            }else if (val > cur->val) {
			    cur->right = _insert(cur->right, val);
		    }
            return cur;
        }
        int _getSize(Node* node) {
		    if (!node) return 0;
		    return _getSize(node->left) + _getSize(node->right) + 1;
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
	    void insert(int val) {
		    Node* newNode = _insert(root, val);
		    if (!root) root = newNode;
	    }
	    Node* search(int target) {
		    return _search(root, target);
	    }

	    int getSize(Node* cur) {
		    return _getSize(cur);
	    }
};

int main(){
    BST bst;
    int n,k;
    cin >> n;
    for( int i = 0; i < n; i++){
        int x;
        cin >> x;
        bst.insert(x);
    }
   
    cin >> k;
    
    //Node* target = bst.search(k);
    //cout << bst.getSize(target);
    cout << bst.getSize(bst.search(k));
}
