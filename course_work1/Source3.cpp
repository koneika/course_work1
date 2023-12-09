#include <iostream>
#include <ctime>

using namespace std;

const int N = 15;

void main() {
	int arr[N], newarray[N];
	int newcount = 0; double av = 0.0;

	create_arr(arr);
	print(arr, N);
	transfer(arr, newarr, newcount);

	if (count != 0) {
		print(newarr,newcount);
		av = ave(newarr, newcount);
		cout << endl << "Average = " << av;
	}
	else
		cout << endl << "There are no elements div 3 or 7";
}

void create_arr(int num[]);
void print(int num[], int size);
void transfer(int num[], int num2[], int &counter);
void ave(int num[], int counter);

void create_arr(int num[]) {
	for (int i = 0; i < N; ++i)
		num[i] = rand();
}

void print(int num[], int size) {
	for (int i = 0; i < N; ++i) 
		cout << num[i] << endl;
}

void transfer(int num[], int num2, int &counter) {
	for (int i = 0; i < N; ++i) {
		if ((num[i]%3 == 0) || (num[i]%7))
			num2[count++] = num[i];
	}
}

void ave(int num[], int counter) {
	double sum = 0.0;
	for (int i = 0; i < N; ++i)
		sum += num[i];
	return sum/counter;
}