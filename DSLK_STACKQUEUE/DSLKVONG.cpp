#include <iostream>
using namespace std;
//dslk vong ( tuong tu nhu dslk don nhung tail tro ve head )
struct Node {
	int info;

	Node* next;
};

//khoi dong danh sach
void init(Node*& head, Node*& tail) {
	head = nullptr;
	tail = nullptr;
}

Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

//them dau
void addFirst(Node*& head, Node*& tail, const int x) {
	Node* tmp = head;
	Node* p = createNode(x);
	p->next = tmp;
	if (tmp == nullptr) {//neu danh sach rong
		
		tail = p;
		
	}
	head = p;
	tail->next = head;


}




//them cuoi
void addLast(Node*& head, Node*& tail,const int x) {
	Node* tmp = head;
	Node* p = createNode(x);
	

	if (tmp == nullptr) {// neu danh sach rong
		head = p;
		
	}
	else{//neu danh sach co >=1 nut
		while (tmp->next != head) {
			tmp = tmp->next;
		}
		tmp->next = p;
		
	}
	tail = p;
	tail->next = head;

}
//xoa dau
int delFirst(Node*& head, Node*& tail) {
	if (head != NULL) {
		Node* tmp = head;
		if (tmp->next != head) { //danh sach co nhieu hon 1 nut
			head = tmp->next;
			
			tail->next = head;
		}
		else {
			head = tail = nullptr;
		}
		tmp->next = nullptr;
		delete tmp;
		return 1; //xoa thanh cong
	}
	return -1;//xoa that bai
}
//xoa cuoi
int delLast(Node*& head, Node*& tail) {
	if (head != NULL) {
		Node* tmp = head;
		Node* prev = nullptr;
		while (tmp->next != head) {
			prev = tmp;
			tmp = tmp->next;
		}
		
			if (prev != nullptr) {
				tail = prev;
				tail->next = head;
				tmp->next = nullptr;
			}
			else { // khi chi co mot phan tu ( khong can phai de tail->next = head nua vi ca 2 da la NULL !)
				tail = prev;
				head = prev;

			}
			delete tmp;
			return 1;//xoa thanh cong
		
	}

	return -1;//xoa khong duoc




}

//xoa tat ca
void clearNode(Node*&head,Node*&tail){
	
	while (head != NULL) {
		delFirst(head, tail); //xoa toi khi head = null thi dung
	}

}




void output(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong \n";
		return;
	}
	Node* tmp = head;
	
	//sai lam 1: kiem tra truoc r moi gan tmp = tmp->next => khong xuat duoc so nao
	/*while (tmp != head) {  
		cout << tmp->info << " ";
		tmp = tmp->next; 
	 }*/
	//sai lam 2: kiem tra truong next => mat so cuoi
	/*while (tmp->next != head) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	 }*/ 

	//xuat truoc r moi gan va kiem tra
	do
	{
		cout << tmp->info << " ";
		tmp = tmp->next;

	} while (tmp!=head);

	cout << endl;

}


int  main() {
	Node* head, * tail;
	init(head, tail);


	
	
	output(head);

	cout << "==========kq xoa=============\n";

	if (delLast(head,tail) != -1) {
		cout << "Xoa thanh cong !\n";
		output(head);
	}
	else {
		cout << "Xoa that bai\n";
	}


	//clear nut
	/*clearNode(head, tail);*/
	
	
	
	
	
	return 0;
}