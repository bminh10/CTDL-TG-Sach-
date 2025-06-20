#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int>Task; //khai bao cap so nguyen
int main() {
	auto compare = [](auto a, auto b) {
		if (a.first == b.first) {
			return a.second > b.second; //a lon hon thi xep sau => uu tien so nho hon
		}
		return a.first > b.first; //a lon hon thi xep sau => uu tien so nho hon
	};
	priority_queue<Task, vector<Task>, decltype(compare)> a(compare); //khai bao bien

	a.push({ 3,4 });
	a.push({ 1,2 });
	a.push({ 6,7 });
	a.push({ 2,3 });
	a.push({ 2,4 });
	
	while (!a.empty()) {
		Task t = a.top();
		cout << "Thu tu hang doi cong viec: " << endl;
		cout << t.first << ": " << t.second << endl;
		a.pop();
	}



	return 0;
}