#include <iostream>
using namespace std;


struct Node
{
	int info; //noi dung phan tu(nut)
	Node* next; //tro den phan tu tiep theo
};

//ham dung khoi dong ds lien ket don
void init(Node*& head) {
	head = NULL;
}


//ham tao mot nut 
Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

//them nut vao dau danh sach

void addHead(Node*& head, const int x) {
	Node* p = createNode(x);
	p->next = head;
	head = p;
}

//them nut vao cuoi danh sach
void addTail(Node*& head, const int x) {
	Node* p = createNode(x);

	//neu head bang rong thi head  = p
	if (head == NULL) {
		head = p;
	}
	else {
		//xac dinh nut tail
		Node* tail = head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//chen p vao cuoi
		tail->next = p;
	}

}

//them nut sau nut chi dinh
void addAfter(Node* head, const int x, const int y) {
	//xac dinh vi tri nut q co gia tri y
	Node* q = head;
	while (q != NULL && q->info != y) {
		q = q->next;
	}
	//khi tim thay q
	if (q != NULL) {
		Node* p = createNode(x);
		p->next = q->next;
		q->next = p;
	}
}

//them nut truoc nut chi dinh

void addBefore(Node*& head, const int x, const int y) {
	//tim nut q co gia tri y
	Node* q = head;
	Node* prev = nullptr;
	while (q != NULL && q->info != y) {
		prev = q;
		q = q->next;
	}
	//neu tim thay q
	if (q != NULL) {
		Node* p = createNode(x);
		p->next = q;
		if (prev == NULL) {
			head = p; //truong hop p la head
		}
		else {
			prev->next = p; //truong hop p khong phai head
		}

	}

}

//ham duyet danh sach xuat thong tin cac nut
void output(Node* head) {
	Node* p = head;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->next;
	}

	cout << endl;
}

//xoa nut dau danh sach
void delHead(Node*& head) {
	if (head != NULL) {
		Node* p = head;
		head = p->next;
		p->next = NULL;
		delete p;
	}
}

//xoa nut cuoi danh sach
void delTail(Node*& head) {
	Node* tail = head;
	Node* prev = NULL;
	while (tail->next != NULL) {
		prev = tail;
		tail = tail->next;
	}

	if (prev == NULL) {
		head = NULL;

	}
	else {
		prev->next = NULL;
		
	}
	delete tail;


}


//xoa nut chi dinh
void deleteX(Node*& head, const int x) {
	Node* q = head;
	Node* prev = nullptr;
	while (q != NULL && q->info != x) {
		prev = q;
		q = q->next;
	}
	//neu tim thay x
	if (q != NULL) {
		//neu nut can xoa la head
		if (prev == nullptr) {
			head = q->next;
		}
		//nut can xoa khac head
		else {
			prev->next = q->next;
		}
		delete q;
	}

}






int main() {
	


	return 0;
}