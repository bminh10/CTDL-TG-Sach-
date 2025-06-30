#include <iostream>
#define MAX 10
using namespace std;

struct DSDac {
	int a[MAX];
	int n;
};

void init(DSDac &a) {
	a.n = 0;
}

void input(DSDac &a) {
	do {
		cout << "Nhap so luong(1-20): ";
		cin >> a.n;
	} while (a.n<0 ||a.n>MAX);
	for (int i = 0; i < a.n; i++) {
		cout << "a[" << i << "]= ";
		cin >> a.a[i];
	}

}


void printList(DSDac a) {
	if (a.n == 0) {
		cout << "DS Rong \n";
		return;
	}
	for (int i = 0; i < a.n; i++) {
		cout << a.a[i] << " ";
	}

	cout << endl;
}


//tim kiem nhi phan ( dam bao danh sach phai co thu tu)

bool Max(int a, int b) {
	return a > b; //ham Max dung cho truong hop DS giam dan( chi co tinh tuong doi )
}
bool Min(int a, int b) {
	return a < b; //ham Min dung cho truong hop DS tang dan( chi co tinh tuong doi )
}
//tim kiem nhi phan linh dong
int BinarySearch(DSDac a, const int x, bool func(int, int)) {
	int l = 0, r = a.n;
	while (l < r) {
		int p = (l + r) / 2;
		if (x == a.a[p]) {
			return p;
		}
		else if (func(x, a.a[p]) == true) {
			l = p + 1;
		}
		else {
			r = p;
		}
	}
	return -1;
}





//th danh sach tang dan
int BinarySearchASC(DSDac a, const int x,bool func(int,int)) {
	int l = 0, r = a.n-1; 
	//l va r dung de kiem soat khoang con
	while (l <= r) {
		int p = (l + r) / 2; //luu vi tri giua khoang con ( hay la giua danh sach )
		if (x == a.a[p]) {
			return p; // vi tri xuat hien x trong danh sach
		}
		else if (func(x,a.a[p])==true) { // x co xuat hien trong mien gia tri a[p,n-1]
			l = p + 1;
		}
		else { //x co xuat hien trong mien gia tri a[0,p-1] 
			r = p-1;
		}
	}
	return -1;//tim khong thanh cong
}

////th danh sach giam dan
//int BinarySearchDESC(DSDac a, const int x) {
//	int l = 0,r=a.n;
//	while (l < r) {
//		int p = (l + r) / 2;
//		if (x == a.a[p]) {
//			return p;
//		}
//		else if (x > a.a[p]) {
//			r = p;
//		}
//		else {
//			l = p + 1;
//		}
//
//	}
//	return -1;
//}




int main() {
	DSDac a;
	init(a);

	input(a);

	printList(a);
	int x;
	cout << "Nhap phan tu can tim: ";
	cin >> x;
	cout << "================KQ TIM KIEM================\n";
	if (BinarySearch(a,x,Max) != -1) {
		cout << "Tim thanh cong ! \n";
		cout << BinarySearch(a, x,Max) << endl;
	}
	else {
		cout << "Tim khong thanh cong ! \n";
	}



	


	return 0;
}