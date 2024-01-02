#include <iostream>
#include <string>
using namespace std;

const int N = 5;

void information(string names_of_students[], int faculty_num[], double av_balls[], int ages[], string gender[]) {
	system("cls");

	for (int i = 0; i < N; ++i) {
			cout << names_of_students[i] << endl;
			cout << "faculty number " << faculty_num[i] << endl;
			cout << "avg ball " << av_balls[i] << endl;
			cout << "age " << ages[i] << endl;
			cout << gender[i] << endl;
			cout << endl;
		}

	system("pause");
	system("cls");
}

void male_and_female(string names_of_students[], string gender[], string male_gender[], string female_gender[], int male_age[], int female_age[], 
					 int ages[], double sum, double index, double sum2, double index2) {
	system("cls");
	//rewrite unknown gender to known gender like male/female_array
	for (int i = 0; i < N; ++i){
		if (gender[i] == "Male") {
			male_gender[i] = gender[i]; // перезаписываем как в задании, по индексу у нас гендер_мейл и гендей_фимейл = тому полу который надо, 1- девка 2 -муж 3 муж 4 муж 5 девка
			//теперь присвоим к каждому полу возраст
			male_age[i] = ages[i];
		}
		else {
			female_gender[i] = gender[i];
			//теперь присвоим к каждому полу возраст
			female_age[i] = ages[i];
		}
	}

	cout << "data" << endl;
	cout << endl;

	for (int i = 0; i < N; ++i) {
		if (male_age[i] == -858993460); // fix(2)
		else {
			cout << names_of_students[i] << " - " ;
			sum += male_age[i]; // for average
			cout << male_age[i] << " y.o. ";
			++index; // for average
			cout << male_gender[i] << endl;
		}
	}

	cout << sum/index << " avarage age of male`s students " << endl;
	cout << endl;

	for (int i = 0; i < N; ++i) {
		if (female_age[i] == -858993460); // fix(2)
		else {
			cout << names_of_students[i] << " - " ;
			sum2 += female_age[i]; // for average
			cout << female_age[i] << " y.o. ";
			++index2; // for average
			cout << female_gender[i] << endl;
		}
	}

	cout  << sum2/index2 << " avarage age of female`s students " << endl;
	cout << endl;

	system("pause");
	system("cls");
}

void female_minimal_age_is(int female_age[], int temp, string names_of_students[], string female_gender[]) {
	system("cls");

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			if (female_age[i] != -858993460) {
				if (female_age[i] < female_age[i + 1]) {
					temp = female_age[i];
					female_age[i] = female_age[i + 1];
					female_age[i + 1] = temp;
				}
			}
		}
	}

	cout << "this is " << names_of_students[N - 1] << " minimal age is " << female_age[N - 1] << " she is " << female_gender[N - 1] << endl;

	system("pause");
	system("cls");
}

void age_order(int ages[], int temp, string names_of_students[]) {
	system("cls");

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			if (ages[i] < ages[i - 1]) {

				temp = ages[i];
				ages[i] = ages[i - 1];
				ages[i - 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << ages[i] << " " /* в войде тоже добавь тогда, но это нереализованный код из за string array << names_of_students[i] << " " << gender[i]*/ << endl;
	}
	

	system("pause");
	system("cls");
} //вот тут нам надо сделать бабл сорт

void main() {
	// я понял, но второй файл с данными я создавать пока не буду, всё пока что будет здесь с переменными и данными и тд
	int male_age[N], female_age[N]; string male_gender[N], female_gender[N];
	int temp = 0, chose, index = 0, index2 = 0; double sum = 0.0, sum2 = 0.0;

	string names_of_students[] = {"Masha", "Sasha", "Grisha", "Pasha", "Vika"};
	int faculty_num[] = {2324, 2012, 2003, 2041, 2213};
	double av_balls[] = {58.5, 59.7, 76.2, 92.0, 47.2};
	int ages[] = {25, 40, 23, 74, 2};
	string gender[] = {"Female", "Male", "Male", "Male", "Female"};
	//menu
	do {

	cout << "MENU" << endl << endl;
	cout << "1. show whole information about of students" << endl;
	cout << "2. age and gender" << endl;
	cout << "3. female minimal ages" << endl;
	cout << "4. ages order" << endl;
	cout << "6. clear" << endl;
	cout << "7. exit" << endl;
	cout << endl;
	
	cin >> chose;

	switch (chose) {
		case 1:
			information(names_of_students, faculty_num, av_balls, ages, gender);
			continue;
		case 2:
			male_and_female(names_of_students, gender, male_gender, female_gender, male_age, female_age, ages, sum, index, sum2, index2);
			continue;
		case 3:
			female_minimal_age_is(female_age, temp, names_of_students, female_gender);
			continue;
		case 4:
			age_order(ages, temp, names_of_students);
			continue;
		case 6:
			system("cls");
			continue;
		case 7:
			break;
	}

	}while(chose == 1 || chose == 2 || chose == 3 || chose == 4 || chose == 6);
	system("pause");

}

// мысли
// исправить баг когда программа выходит и указывает на ages ♥
// добавить fix(2)
// сделать переменные в ряд, не в столбик ♥
// доделать проект уже, поработать с файлом, понять что это за нафиг вообще
// удалить ненужные комментарии ♥