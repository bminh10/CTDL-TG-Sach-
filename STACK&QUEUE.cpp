#include <iostream>
#include <string>
#include <stack>
#include <queue>
#define MAX 100
using namespace std;
//Stack (Ngan xep)

//co the dung ds dac hoac ds lien ket de cai dat stack

//stack la array + luat ( luat: LAST IN FIRST OUT -> Them cuoi cung thi se lay ra dau tien)
struct Stack {
	int a[MAX];
	//dinh cua stack
	int top;
};


//khoi dong stack
void init(Stack& s) {
	s.top = -1;
}

//kiem tra stack rong hay khong
bool isEmpty(const Stack s) {
	return s.top == -1;
}
//kiem tra stack day hay chua
bool isFull(const Stack s) {
	return s.top == MAX - 1;
}


//cac thao tac voi stack

//them dinh stack
void push(Stack& s,const int x) {
	s.a[++s.top] = x;
}

//xoa dinh stack
void pop(Stack& s) {
	if (!isEmpty(s)) {
		s.top--;
	}
}

//lay dinh stack
int get(const Stack s) { //peek/top/get
	return s.a[s.top];
}


//chuyen doi so nguyen duong n tu he 10 sang co so 2, 8 , 16
void convert(int n,int radix=2) {
	Stack s;
	init(s);
	while (n != 0) {
		push(s, n % radix);
		n /= radix;
	}

	char letters[] = { 'A','B','C','D','E','F' };
	while (!isEmpty(s)) {
		int t = get(s);
		if (t<10) {
			cout << t;
		}
		else {
			cout << letters[t-10];
		}
		pop(s);
	}
	cout << endl;

}

//tinh cac so hang co 1 chu so 
void cal(stack<int>&a, char op) {
	//do thuc hien tinh tu trai sang phai nen lay tu dinh truoc
	int y = a.top();
	a.pop();
	int x = a.top();
	a.pop();
	switch (op)
	{
	case '+': {
		a.push(x + y);
		break;
	}
	case '-': {
		a.push(x - y);
		break;
	}
	case '*': {
		a.push(x * y);
		break;
	}
	case '/': {
		a.push(x / y);
		break;
	}
	default:
		break;
	}


}

int priority(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '*' || c == '/') {
		return 2;
	}
	return 0; //neu gap dau ( hoac dau khong thuoc 4 phep toan tren o dieu kien else
}



int main() {
	
	cout << "===============STACK=============\n";

	/*Stack s;
	init(s);*/
	/*push(s, 3);
	push(s, 4);
	push(s, 5);

	while (!isEmpty(s)) {
		cout << get(s) << " ";
		pop(s);
	}*/

	stack<int>a; //stack so hang
	stack<char>b; //stack phep toan
	convert(10, 16);
	
	string chuoi = "200+(25-2+50)*10/100";

	for(int i = 0; i <chuoi.length() ; i++) {
		if (chuoi[i] >= '0' && chuoi[i] <= '9') { // neu gap ky tu so
			int num = 0;
			while (chuoi[i] >= '0' && chuoi[i] <= '9') {
				num = num * 10 + (chuoi[i] - '0'); //luu cac so >=10
				i++;
			}
			i--;
			a.push(num);
		}

		else if (chuoi[i] == '(') { //gap dau ( thi push vo de tinh uu tien
			b.push(chuoi[i]);
		}

		else if (chuoi[i] == ')') {
			while (!b.empty() && b.top() != '(') { //tinh den khi gap lai dau (
				char ope = b.top();
				b.pop();
				cal(a, ope);
			}
			b.pop(); //xoa dau (

		}
		else {
			while (!b.empty() && priority(b.top()) >= priority(chuoi[i])) {
				char op = b.top();
				b.pop();
				cal(a, op);

			}
			b.push(chuoi[i]);
			

		}
	}

	//phep tinh cuoi cung

	//TH neu stack b luu chi 1 phep toan cong || tru ||  nhan || chia 
	/*if (!b.empty()) {
		char oper= b.top();
		b.pop();
		cal(a, oper);

	}*/
	//TH Tong quat: stack b luu 2 phep toan (* hoac / o dau va duoi cung la + hoac tru) hoac ( ca 2 phep toan duoc luu la * hoac /)

	while (!b.empty()) {
		char operat = b.top();
		b.pop();
		cal(a, operat);
	}

	cout <<a.top() << endl;

	cout << "================QUEUE=================\n";
	//mac dinh gia tri lon thi do uu tien cao
	priority_queue<int>c;
	c.push(35);
	c.push(23);
	c.push(33);
	c.push(22); //queue theo do uu tien : 1) 35 | 2) 33 | 3) 23 | 4) 22 

	//duyet hang doi
	//lay do uu tien tu lon -> nho

	//xoa theo do uu tien tu lon -> nho
	c.pop();
	if (c.top() != 35) {
		cout << "Da xoa so 35\n";
	}
	

	
	
	
	
	


	return 0;
}