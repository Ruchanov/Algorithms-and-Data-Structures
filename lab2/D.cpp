#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};
struct LinkedList{
    int size;
    ListNode* head;
    ListNode* tail;
    LinkedList(){
        this-> size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    void push_back(int x){
		ListNode *temp = new ListNode(x);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
            this->size++;
		}
		else
		{
			this->tail->next = temp;
            this->tail = temp;
            this->size++;
		}
    }
    void print() {
		ListNode *cur = this->head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
    int mode(){
        ListNode *cur = this->head;
        map<int,int> m;
        map<int,int> :: iterator it;
        for(int i = 0;i<this->size;i++){
            m[cur->val]++;
            cur = cur->next;
        }
        int max = 0;
        vector<int> v;
        for(it = m.begin();it!=m.end();it++){
            if((*it).second>max){
                max = (*it).second;
            }
        }
        for(it = m.begin();it!=m.end();it++){
            if((*it).second == max){
                v.push_back((*it).first);
            }
        }
        sort(v.begin(),v.end());
        for(int i = v.size()-1;i >= 0;i--){
            cout<<v[i]<<" ";
        }
    }  
};
int main(){
    LinkedList *l = new LinkedList();
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        l->push_back(x);
    }
    l->mode();
}
