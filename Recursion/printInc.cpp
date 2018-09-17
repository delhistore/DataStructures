
#include <iostream>
using namespace std;

void printInc(int n) {	//O(n)
	if (n <= 0) return ;	//recurrence doesn't hold

	printInc(n - 1);
	cout << n << " ";

}


int main() {
	int n;
	cin >> n;
	printInc(n);
}
