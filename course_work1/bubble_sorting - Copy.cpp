#include <iostream>
#include <ctime>
using namespace std;

const int N  = 5;

struct data{
	string name_of_student;
	int faculty_num;
	double av_balls;
	int age;
	string gender;
};

int main() {
	srand(time(NULL));
	data a[N]; data a2_rew[N]; int temp;

	for(int i = 0; i < N; i++)
		a2_rew[i].age = rand();

	for(int j = 0; j < N-1; ++j)
				for(int i = 0; i < N-1; ++i)
					/*if (a2_rew[i].gender == "Female") */
						if (a2_rew[i].age < a2_rew[i + 1].age) {
							temp = a2_rew[i].age;
							a2_rew[i].age = a2_rew[i + 1].age;
							a2_rew[i + 1].age = temp;
						}

	for(int i = 0; i < N; i++)
		cout << a2_rew[i].age << endl;
	system("pause");
	return 0;
}