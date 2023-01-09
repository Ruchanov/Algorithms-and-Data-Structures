#include <iostream>
using namespace std;

struct ListNode
{
	string val;
	ListNode *next;
	ListNode *prev;

	ListNode()
	{
		this->val = "";
		this->next = nullptr; // or type NUll instead of nullptr
		this->prev = nullptr; // or type NUll instead of nullptr
	}

	ListNode(string val)
	{
		this->val = val;
		this->next = nullptr;
		this->prev = nullptr;
	}

	ListNode(string val, ListNode *prev, ListNode *next)
	{
		this->val = val;
		this->next = next;
		this->prev = prev;
	}
};

struct DoublyLinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	DoublyLinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void addFront(string val)
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
			this->head->prev = temp;
			this->head = temp;
		}
	}

	void addBack(string val)
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
			temp->prev = this->tail;
			this->tail = temp;
		}
	}
    void deleteFront(){
		if(size>1){
        	cout<<head->val<<endl;
        	this->head = this->head->next;
			// delete (this->head->prev);
			this->head->prev = nullptr;
			this->size--;
		}else if(size ==1){
			cout<<head->val<<endl;
			clear();
		}else{
			cout<<"error"<<endl;
		}
    }
    void deleteBack(){
		if(size > 1){
        	cout<<tail->val<<endl;
        	this->tail = this->tail->prev;
			this->tail->next = nullptr;
			this->size--;
		}else if(size ==1){
			cout<<head->val<<endl;
			clear();
		}else{
			cout<<"error"<<endl;
		}
    }
	
    // void front(){
    //     cout<<head->val<<endl;
    // }
    // void back(){
    //     cout<<tail->val<<endl;
    // }
	void clear(){
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
};


int main()
{
	//freopen("input.txt","r",stdin);
    DoublyLinkedList *dl = new DoublyLinkedList;
    while(true){
        string s;
        cin>>s;
        if(s=="add_front"){
            string s2;
            cin>>s2;
            dl->addFront(s2);
            cout<<"ok"<<endl;
        }
        if(s=="add_back"){
            string s2;
            cin>>s2;
            dl->addBack(s2);
            cout<<"ok"<<endl;
        }
        if(s=="erase_front"){
            dl->deleteFront();
        }
		if(s=="erase_back"){
            dl->deleteBack();
        }
		
		if(s=="front"){
			if(dl->size>0){
            	cout<<dl->head->val<<endl;
			}else{
				cout<<"error"<<endl;
			}
            //dl->front();
        }
		if(s=="back"){
			if(dl->size>0){
            	cout<<dl->tail->val<<endl;
			}else{
				cout<<"error"<<endl;
			}
            //dl->back();
        }
		if(s == "clear"){
			dl->clear();
            cout<<"ok"<<endl;
		}
		if(s == "exit"){
			cout<<"goodbye";
			return 0;
		}

    }
	return 0;
}