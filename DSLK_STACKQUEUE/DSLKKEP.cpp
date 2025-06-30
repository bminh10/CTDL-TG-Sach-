#include <iostream>
using namespace std;


//DS Lk Kep
struct Node {
	//noi dung nut
	int info;
	//tro toi nut truoc
	Node* next;
	//tro toi nut sau
	Node* prev;//previous
};

void init(Node*& head, Node*& tail) {
	head = nullptr;
	tail = nullptr;
}

Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	p->prev = nullptr;
	return p;
}

//them dau danh sach
void addFirst(Node*& head, Node*& tail,const int x) {
	Node* p = createNode(x);
	p->next = head;
	if (head == nullptr) {
		tail = p;
	}
	else {
		head->prev = p;
	}
	head = p; 
}

//them cuoi ds
void addLast(Node*& head, Node*& tail,const int x) {
	Node* p = createNode(x);
	p->prev = tail;
	if (tail == nullptr) {
		
		head = p;
	}
	else {
		tail->next = p;
		
	}
	tail = p;
}
void addSauChiDinh(Node*& head, Node*& tail, const int x,const int y) {
	Node* tmp = head;
	
	while (tmp != NULL && tmp->info != x) {
		
		tmp = tmp->next;
	}
	//khi tim thay
	if (tmp != NULL) {
		Node* p = createNode(y);	
		
		if (tmp->next == NULL) { //neu nut tim thay la tail hoac ds chi co 1 nut duoc tim thay
			
			tail = p;

		}
		else {
			
			tmp->next->prev = p;
			

		}
		p->next = tmp->next;
		p->prev = tmp;
		tmp->next = p;
		
		
	}

}
//them nut truoc chi dinh
void addTruocChiDinh(Node*& head, Node*& tail, const int x, const int y) {
	Node* tmp = head;
	while (tmp != NULL && tmp->info != x) {
		tmp = tmp->next;
	}
	//neu tim duoc
	if (tmp != NULL) {
		Node* p = createNode(y);
		if (tmp->prev != NULL) { //neu nut tim thay la head hoac ds chi co 1 nut duoc tim thay
			
			tmp->prev->next = p;
			
		}
		else {
			head=p;
			
		}
		p->next = tmp;
		p->prev = tmp->prev;
		tmp->prev = p;
	}
}

//xoa dau
int delFirst(Node* &head,Node*&tail) {
	
	if (head != NULL) {//neu head khong phai null
		Node* p = head;
		head = p->next;
		if (head != nullptr) { //neu nut ke tiep khong phai null
			p->next = nullptr;
			head->prev = nullptr;
			
			
		}
		else { //neu nut ke tiep la null
			tail = nullptr;  
			
		}
		delete p;
		return 1;//xoa thanh cong
	}

	return -1; //xoa that bai


}
//xoa cuoi
int delLast(Node*& head, Node*& tail) {
	if(tail!=NULL){ //neu ds khong rong
		Node* tmp = tail;
		tail = tmp->prev;//doi nut tail ra sau tmp
		tmp->prev = nullptr; 
		if (tail != nullptr) { //neu ds co nhieu hon 1 nut
			tail->next = nullptr;
		}
		else { //neu ds chi co 1 nut
			head = nullptr; //vi ko con nut nen head cung la null
		}
		delete tmp;
		return 1;//xoa thanh cong
	}
	return -1; //xoa khong thanh cong

}

//xoa tat ca
void clearNode(Node*& head, Node*& tail) {
	while (head != NULL) {
		delFirst(head, tail);
	}
}

//xoa nut chi dinh
int delChiDinh(Node*& head, Node*& tail, const int x) {
	Node* tmp = head;
	while (tmp != NULL && tmp->info != x) {
		tmp = tmp->next;
	}
	//neu tim thay
	if (tmp != NULL) {
		if (tmp->prev == nullptr) { //nut can xoa la nut dau tien
			head = tmp->next; 
			
		}
		else {
			tmp->prev->next = tmp->next;
			
		}

		if (tmp->next == nullptr) { // nut can xoa la nut cuoi cung
			tail = tmp->prev;
		}
		else {
			tmp->next->prev = tmp->prev;
			
		}
		tmp->next = nullptr;
		tmp->prev = nullptr;


		delete tmp;
		return 1;
	}
	return -1;
}



//duyet tu head toi tail
void print1(Node* head) {
	if (head == nullptr) {
		cout << "DS Rong\n";
		return;
	}

	Node* tmp = head;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

//duyet tu tail toi head
void print2(Node* tail) {
	if (tail == nullptr) {
		cout << "DS Rong\n";
		return;
	}
	Node* tmp = tail;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->prev;
	}
	cout << endl;
}


int main() {
	Node* tail, * head;
	init(head, tail);

	addLast(head,tail,3);
	addLast(head,tail,6);
	addLast(head,tail,2);
	

	print1(head);

	/*cout << "=========kq sau khi xoa============\n";
	if (delFirst(head,tail) != -1) {
		cout << "xoa thanh cong !\n";
		print2(tail);
	}
	else {
		cout << "danh sach rong nen xoa khong thanh cong";
		
	}*/

	/*if (delLast(head, tail) != -1) {
		cout << "Xoa thanh cong !\n";
		print1(head);
	}
	else {
		cout << "Danh sach rong nen khong xoa duoc \n";
	}*/
	
	/*clearNode(head, tail);

	cout << "======kq sau khi clear==============\n";
	print1(head);*/


	cout << "=============KQ SAU KHI XOA=========\n";
	if (delChiDinh(head, tail, 2) != -1) {
		cout << "Xoa thanh cong \n";
		print1(head);
	}
	else {
		cout << "Xoa khong thanh cong \n";
	}



	


	

	return 0;
}