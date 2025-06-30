#include <iostream>
#define MAX 20
using namespace std;

struct DSDac {
	int a[MAX];
	int n;

};
//khoi dong danh sach
void init(DSDac& l) {
	l.n = 0;
}

void input(DSDac& l) {
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> l.n;
	} while (l.n <= 0 && l.n > 20);
	for (int i = 0; i < l.n; i++) {
		cout << "a[" << i << "]= ";
		cin >> l.a[i];
	}

}
void output(DSDac l) {
	if (l.n == 0) {
		cout << "Danh sach rong \n";
		return;
	}
	for (int i = 0; i < l.n; i++) {
		cout << l.a[i] << " ";
	}
	cout << endl;
}





//sap xep noi bot
bool ASC(int a, int b) {
	return a < b; //theo thu tu tang dan ( tuong doi )
}
bool DESC(int a, int b) {
	return a > b;// theo thu tu giam dan ( tuong doi )
}


void bubbleSort(DSDac& l,bool func(int,int)=DESC) {
	if (l.n != 0) {
		for (int i = 0; i < l.n - 1; i++) {
			for (int j = l.n - 1; j > i; j--) {
				if (func(l.a[j], l.a[j - 1])==true) { //2 phan tu ke nhau ma nghich the thi doi cho
					swap(l.a[j], l.a[j - 1]);
				}
			}
		}
	}
}


//Sap xep chen truc tiep
void insertionSort(DSDac& l,bool func(int,int)=ASC) {
	for (int i = 1; i < l.n; i++) {
		int x = l.a[i];
		//luu vi tri can chen
		int p = i - 1;
		while (p >= 0 && func(x,l.a[p])) {
			l.a[p + 1] = l.a[p];
			p--;
		}
		//them x vao vi tri pos+1
		l.a[p + 1] = x;
	}
}





int main() {
	DSDac a;
	init(a);

	input(a);

	output(a);

	cout << "===================KQ SAU KHI SAP XEP==================\n";
	insertionSort(a,ASC);
	output(a);

	return 0;
}