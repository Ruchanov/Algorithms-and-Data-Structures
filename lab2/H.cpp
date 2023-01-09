#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode()
	{
		this->val = 0;
		this->next = nullptr; 
	}

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}

	ListNode(int val, ListNode *next)
	{
		this->val = val;
		this->next = next;
	}
};

struct LinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	LinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push_front(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			temp->next = this->head;
			this->head = temp;
		}
	}

	void push_back(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			this->tail->next = temp;
			this->tail = temp;
		}
	}

	void addAtIndex(int index, int val)
	{
	    if (index == 0)
	    {
		    this->push_front(val);
	    }
	    else if (index == this->size)
	    {
		    this->push_back(val);
	    }
	    else
	    {
		    ListNode *temp = new ListNode(val);
		    ListNode *cur = this->head;
    		for (int i = 1; i < index; i++)
	    	{
		    	cur = cur->next;
    		}
	    	temp->next = cur->next;
		    cur->next = temp;
    		this->size++;
    	}
	}

	int get(int index)
	{
		if (index < 0 || index >= this->size)
		{
			return -1;
		}
		ListNode *cur = this->head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		return cur->val;
	}

	void deleteAtIndex(int index)
	{
		if (index == 0)
		{
			this->head = this->head->next;
			this->size--;
		}
		else if (index == this->size - 1)
		{
			ListNode *cur = this->head;
			while (cur->next != this->tail)
			{
				cur = cur->next;
			}
			this->tail = cur;
			this->tail->next = nullptr;
			this->size--;
		} else if (index > 0 && index < this->size-1) {
			ListNode *cur = this->head;
			for (int i = 0; i < index - 1; i++) {
				cur = cur->next;
			}
			ListNode *toDel = cur->next;
			cur->next = cur->next->next;
			this->size--;
			delete (toDel);
		}
	}
    void cyclic_left(int x){
        ListNode *cur = head;
		tail->next = head;
		while(x--){
        	// while(cur->next!=nullptr){
            // 	cur->val = cur->next->val;
            // 	cur = cur->next;
        	// }
			head = head->next;
			tail = tail->next;
		}
		tail->next = nullptr; 
    }
	void cyclic_right(int x){
        ListNode *cur = head;
		tail->next = head;
		while(x--){
        	// while(cur->next!=nullptr){
            // 	cur->val = cur->next->val;
            // 	cur = cur->next;
        	// }
			head = head->next;
			tail = tail->next;
		}
		tail->next = nullptr; 
    }


	void replace(int p1,int p2){
		int y = get(p1);
		deleteAtIndex(p1);
		addAtIndex(p2,y);
	}
	void print() {
		if(size == 0){
			cout<<-1;
			return;
		}
		ListNode *cur = this->head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
	}

	void reverse(){
        ListNode * next = nullptr;
        ListNode * prev = nullptr;
        ListNode * cur = head;
        while(cur != nullptr){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList *l =new LinkedList;
    while(true){
		int x;
		cin>>x;
		if(x==0){
			return 0;
		}
		if(x==1){
			int y,z;
			cin>>y>>z;
			l->addAtIndex(z,y);
		}
		if(x==2){
			int y;
			cin>>y;
			l->deleteAtIndex(y);
		}
		if(x == 3){
			l->print();
			cout<<endl;
		}
		if(x == 4){
			int y,z;
			cin>>y>>z;
			l->replace(y,z);
		}
		if(x == 5){
			l->reverse();
		}
		if( x == 6){
			int y;
			cin>>y;
			l->cyclic_left(y);
		}
		if(x == 7){
			int y;
			cin>>y;
			l->cyclic_right(l->size-y);
		}
	}
	return 0;
}