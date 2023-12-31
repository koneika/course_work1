#include <ctime>
#include <iostream>
using namespace std;

void main() {
	int arr[50];
	int temp;

	for (int i = 0; i < 50; ++i) {
		arr[i] = rand()%25000;
	}
	for (int i = 0; i < 50; ++i) {
		cout << arr[i] << endl;
	}
	for (int i = 0; i < 50; ++i) {
		if (arr[i-1] < arr[i]) {
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
		else {
		}
	}
	for (int i = 0; i < 50; ++i) {
		cout << arr[i] << endl;
	}
	system("pause");
}