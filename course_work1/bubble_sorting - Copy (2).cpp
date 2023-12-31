#include <ctime>
#include <iostream>
using namespace std;

void main() {
	int arr[50];

	for (int i = 0; i < 50; ++i) {
		arr[i] = rand()%25000;
	}

	for (int i = 0; i < 50; ++i) {
		if (arr[i-1] < arr[i]) {
			cout << "bubble sort" << endl;
		}
		else {
			cout << "no buuble sort" << endl;
		}
	}
	system("pause");
}