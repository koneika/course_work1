#include <iostream>
#include <string>

//курсовая блять

using namespace std;

const int N = 5;

void information(string names_of_students[], int faculty_num[], double av_balls[], int ages[], string gender[]) {

	for (int i = 0; i < N; ++i) {
			cout << names_of_students[i] << endl;
			cout << "faculty number " << faculty_num[i] << endl;
			cout << "avg ball " << av_balls[i] << endl;
			cout << "age " << ages[i] << endl;
			cout << gender[i] << endl;
			cout << endl;
		}
}

void main() {
	// я понял, но второй файл с данными я создавать пока не буду, всё пока что будет здесь с переменными и данными и тд

	int chose;

	string names_of_students[] = {"Masha", "Sasha", "Grisha", "Pasha", "Vika"};
	int faculty_num[] = {2324,2012,2003,2041,2213};
	double av_balls[] = {58.5, 59.7, 76.2, 92.0, 47.2};
	int ages[] = {25, 40, 23, 74, 2};
	string gender[] = {"Female", "Male", "Male", "Male", "Female"};

	

	// я думаю позже
	/*
	for (int i = 0; i < N; ++i){
		if (gender[i] == "Male") {
			male_gender[i] = gender[i];
			cout << male_gender[i] << endl;
			male_index++;
		}
		else {
			female_gender[i] = gender[i];
			cout << female_gender[i] << endl;
			female_index++;

		}
	}
	// new double avg number;
	cout << female_index << " " << male_index << endl;
	avg_ages = (ages[0]+ages[1]+ages[2]+ages[3]+ages[4])/(N);

	cout << avg_ages << endl;
	*/

	//menu
	do {

	cout << "MENU" << endl;
	cout << "1. show whole information about of students" << endl;
	cout << "6. clear" << endl;
	cout << "7. exit" << endl;
	cout << endl;
	
	cin >> chose;

	//system("cls");	//хз пусть тут побудет

	switch (chose) {
		case 1: // правильнее
			information(names_of_students, faculty_num, av_balls, ages, gender);
			continue;
		case 6:
			system("cls"); // почему оно блять работает вместе? схуяли
			continue; // теперь дошло почему оно не работало как надо, потому что надо ставить эти хуйни, без них пиши пропало
		case 7:
			break;
	}

	}while(chose == 1 || chose == 6);
	system("pause");
}