#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;

	Node(int val) {
		this->val = val;
	}
};

struct Queue
{
	Node* head;
	Node* tail;
	int size;

	Queue() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void pop() {
		Node* toDel = head;
		head = head->next;
		delete (toDel);
		size--;	
	}
	void push(int val) {
		if (!head) {
			Node* newNode = new Node(val);
			head = newNode;
			tail = newNode;
		} else {
			Node* newNode = new Node(val);
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
};

int main() {
	Queue q;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        q.push(x);
        while(q.head->val < x - 3000){
			q.pop();
		}
        cout << q.size << " ";
    }
	return 0;
}