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
	bool flag = true;
	if (l.n != 0) {
		for (int i = 0; i < l.n - 1; i++) {
			for (int j = l.n - 1; j > i; j--) {
				if (func(l.a[j], l.a[j - 1])) { //2 phan tu ke nhau ma nghich the thi doi cho
					swap(l.a[j], l.a[j - 1]);
					flag = false;
				}
				
			}
			if (flag == true) {
				return;
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

//sap xep tang dan
bool Max(int a, int b) {
	return a > b;
}
bool Min(int a, int b) {
	return a < b;
}

//tang dan < >
//giam dan > <


void quickSort(DSDac& l, int left, int right, bool func1(int, int)=Max) {
	int pivot = l.a[(left + right) / 2];
	int i = left, j = right;
	do
	{
		while (func1(l.a[i], pivot)) {
			i++;
		}
		while (!func1(l.a[j], pivot) && l.a[j]!=pivot ) {
			j--;
		}
		if (i <= j) {
			swap(l.a[i], l.a[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i < right) {
		quickSort(l, i, right,Max);
	}
	if (j > left) {
		quickSort(l, left, j,Max);
	}


}


//tang dan
//max giam dan
//min tang dan

void heapify(DSDac& l,const int n ,int i,bool func(int,int)) {
	int jmax = 2 * i + 1;
	if (jmax < n) {
		if (2 * i + 2 < n && func(l.a[jmax] , l.a[2 * i + 2])) {
			jmax = 2 * i + 2;
		
		}
		if (func(l.a[i] , l.a[jmax])) {
			swap(l. a[i], l.a[jmax]);
			heapify(l, n,jmax,Max);
		}
	}
}

void buildMaxHeap(DSDac& l,const int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(l,n,i,Max);
	}
}

void heapSort(DSDac& l) {
	for (int i = 0; i < l.n - 1; i++) {
		buildMaxHeap(l,l.n-i);
		swap(l.a[0], l.a[l.n - i - 1]);
	}
}



int main() {
	DSDac a;
	init(a);

	input(a);

	output(a);

	cout << "===================KQ SAU KHI SAP XEP==================\n";
	//sap tang dan
	
	//sap giam dan
	/*quickSort(a, 0, a.n - 1, Max);*/
	heapSort(a);
	output(a);

	return 0;
}