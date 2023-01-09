#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val; 
        left = right = nullptr;
    }
};

struct BST{
    private:
        Node* root;

        void _inorder(Node* node){
            if(!node) return;
            _inorder(node->left);
            cout << node->val<<" ";
            _inorder(node->right);
        }

        void _preorder(Node* node){
            if(!node) return;
            cout << node->val << " ";
            _preorder(node->left);
            _preorder(node->right);
        }

        void _postorder(Node* node){
            if(!node) return;
            _postorder(node->left);
    		_postorder(node->right);
	    	cout << node->val << " ";
        }

        Node* _insert(Node* cur, int val){
            if(!cur){
                return new Node(val);
            }
            else if(val > cur->val){
                cur->right = _insert(cur->right,val);
            }
            else if(val < cur->val){
                cur->left = _insert(cur->left,val);
            }
            return cur;
        }
        int _rightmost(Node* cur){
            if(!cur) return -1;
            if(!cur->right) return cur->val;
            _rightmost(cur->right); 
        }
        int _leftmost(Node* cur){
            if(!cur) return -1;
            if(!cur->left) return cur->val;
            _leftmost(cur->left); 
        }

        Node* remove(Node* cur , int target){
            if(!cur){
                return nullptr;
            }
            if(cur->val == target){
                if(!cur->right && !cur->left){
                    delete cur;
                    return 0;
                }else if(!cur->right && cur->left){
                    Node* temp = cur->left;
                    delete cur;
                    return temp;
                }
            }
        }
    public:
        BST(){
            root = nullptr;
        }
        void inorder(){
            _inorder(root);
            cout << endl;
        }
        void preorder(){
            _preorder(root);
            cout << endl;
        }
        void postorder(){
            _postorder(root);
            cout << endl;
        }
        void insert(int val){
            Node* newNode = _insert(root,val);
            if(!root) root = newNode;
        }
};

int main(){
    BST bst;
    bst.insert(5);
    bst.insert(14);
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    bst.insert(2);
    bst.insert(42);
    bst.inorder();
}