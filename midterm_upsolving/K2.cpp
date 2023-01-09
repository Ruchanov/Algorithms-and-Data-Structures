#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node* prev;

	Node() {
		val = 0;
		next = nullptr; 
		prev = nullptr;
	}

	Node(int val) {
		this->val = val;
		next = nullptr;
		prev = nullptr;
	}
};

struct DoublyLinkedList
{
	int size = 0;
	Node* head = nullptr;
    Node* tail = nullptr;
	void addAtTail(int val) {
		size++;
		Node* temp = new Node(val);
		if (head == nullptr) {
			head = temp;
			tail = temp;
		} else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			
		}
	}
    void addAtHead(int val) {
		size++;
		Node* temp = new Node(val);
		if (!head) {
			head = temp;
			tail = temp;
		} else {
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void print() {
		Node* cur = head;
		while (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
	}
	void printReverse() {
		Node* cur = this->tail;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->prev;
		}
		cout << endl;
	}
};
int main() {
	DoublyLinkedList d;
    int n;
    cin >> n;
    bool res = true;
	int cnt = 0;
    while(n--){
        int x;
        cin >> x;
        if(x == 1){
            int y;
            cin >> y;
            if(res == true){    
                d.addAtTail(y);
            }else{
                d.addAtHead(y);
            }
        }if(x == 2){
			cnt++;
            if(res == true){
                res = false;
            }else{
                res = true;
            }
        }
    }
	if(cnt % 2 == 0){
		d.print();
	}else{
    	d.printReverse();
	}
    return 0;
}