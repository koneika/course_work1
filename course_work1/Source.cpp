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

/*
void male_and_female() {
	
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
}
*/

void main() {
	// я понял, но второй файл с данными я создавать пока не буду, всё пока что будет здесь с переменными и данными и тд

	string male_gender[N];
	string female_gender[N];
	int male_index = 0; // мне кажется это не надо
	int female_index = 0; // мне кажется это не надо
	int male_age[N];
	int female_age[N];

	int chose;

	int index = 0;
	int index2 = 0;
	double sum = 0.0;
	double sum2 = 0.0;

	string names_of_students[] = {"Masha", "Sasha", "Grisha", "Pasha", "Vika"};
	int faculty_num[] = {2324,2012,2003,2041,2213};
	double av_balls[] = {58.5, 59.7, 76.2, 92.0, 47.2};
	int ages[] = {25, 40, 23, 74, 2};
	string gender[] = {"Female", "Male", "Male", "Male", "Female"};

	

	// я думаю позже
	// теперь это надо в блок кинуть, как здесь
	for (int i = 0; i < N; ++i){
		if (gender[i] == "Male") {
			male_gender[i] = gender[i];
			//cout << male_gender[i] << endl;
			//теперь присвоим к каждому полу возраст
			male_age[i] = ages[i];

		}
		else {
			female_gender[i] = gender[i];
			//cout << female_gender[i] << endl;
			//теперь присвоим к каждому полу возраст
			female_age[i] = ages[i];


		}
	}

	cout << endl;

	cout << "data" << endl;
	for (int i = 0; i < N; ++i) {
		if (male_age[i] == -858993460) {
		}
		else {
			sum += male_age[i];
			cout << male_age[i] << endl;
			++index;
			
		}
	}
	sum = sum/index;
	cout << sum << endl;

	cout << endl;
	
	for (int i = 0; i < N; ++i) {
		if (female_age[i] == -858993460) {
		}
		else {
			sum2 += female_age[i];
			cout << female_age[i] << endl;
			++index2;
		}
	}

	sum2 = sum2/index2;
	cout << sum2 << endl;
	
	cout << endl;

	cout << "count" << endl;
	// new double avg number;
	cout << "females " << female_index << " " << "males " << male_index << endl;

	
	cout << endl;

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