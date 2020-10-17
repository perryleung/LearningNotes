#include <iostream>
using namespace std;

typedef struct node{
	int age;
	struct node *next;	
}ListNode;

ListNode* create(int n){
	ListNode *head = new ListNode;//!!!!very important new
	ListNode *curr = head;
	curr = head;
	for(int i=0;i<n;i++){
		ListNode *p = new ListNode;
		p->age = i*2;
		//p->next = NULL;
		curr->next = p;
		curr = p;
		p->next = NULL;
	}
	return head;
}
ListNode* create_new(int n, int a[]){
	ListNode *head = NULL;
	ListNode *p = NULL;
	for(int i = 0; i < n; i++){
		if(head == NULL){
			head = p = new ListNode(a[i]);
		}else{
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head; 
} 

void display(ListNode *head){
	ListNode *p = head->next;
	while(p!=NULL){
		cout<<p->age<<endl;
		p = p->next;
	}
}


int main()
{
	const int n = 16;
	ListNode *p = create(n);
	display(p);
	return 0;
}
