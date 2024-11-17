#include<iostream>
using namespace std;

typedef struct Node{
	int data;
	struct Node* next; 
}Node; 
Node* createnode(int a){
 Node* newnode= new Node;
	newnode->data = a;
	newnode->next = NULL;
	return newnode; 
} 

//Ham in danh sach
void printlist(Node* head){
	Node* current = head;
	while(current!= NULL){
		cout << current->data <<" ";
		current = current->next; 
	} 
} 

//Ham them vao dau danh sach
void inserthead(Node*& head, int a){
	Node* newnode = new Node;
	newnode->data = a;
	newnode->next = head;
	head = newnode; 
} 

//Ham xoa node o dau danh sach
void deletehead(Node*& head){
	if(!head){
		cout <<" danh sach rong, khong the xoa!"<<endl;
		return; 
	} 
	Node* temp = head;
	head= head->next; 
	delete temp; 
} 
//Ham xoa node o cuoi danh sach
void deletetail(Node*& head){
	if(!head){
		cout <<"Danh sach rong, khong the xoa!"<<endl;
		return; 
	} 
	if(!head->next){
		delete head;
		head = NULL;
		return; 
	} 
	Node* current = head;
	while(current->next->next!= NULL){
		current= current->next; 
	} 
	delete current->next;
	current->next = NULL; 
} 

//Ham xoa node sau mot node duoc cho truoc
void deleteafter(Node* prev){
	Node* temp = prev->next;
	prev->next=temp->next;
	delete temp; 
} 

int main() {
    Node* head = NULL;
    inserthead(head, 4);
    inserthead(head, 3);
    inserthead(head, 2);
    inserthead(head, 1);

    cout << "Danh sach ban dau: ";
    printlist(head);

    // Xóa node o dau danh sach
    deletehead(head);
    cout << "Sau khi xoa dau: ";
    printlist(head);

    // Xóa node o cuoi 
    deletetail(head);
    cout << "Sau khi xoa cuoi: ";
    printlist(head);

    // Xóa node sau node 
    deleteafter(head);
    cout << "Sau khi xóa node sau node dau tien: ";
    printlist(head);

    return 0;
}


















