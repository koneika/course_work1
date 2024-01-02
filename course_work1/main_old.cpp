#include <iostream>
#include <string>

//курсовая блять

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
					 int male_index[], int female_index[], int ages[], double sum, double index, double sum2, double index2,
					 string in_block_male_gender[], string in_block_female_gender[]) {
	system("cls");
	// я думаю позже
	// теперь это надо в блок кинуть, как здесь
	for (int i = 0; i < N; ++i){
		if (gender[i] == "Male") {
			male_gender[i] = gender[i];
			//cout << male_gender[i] << endl;
			//теперь присвоим к каждому полу возраст
			male_age[i] = ages[i];
			male_index[i] = 1;
		}
		else {
			female_gender[i] = gender[i];
			//cout << female_gender[i] << endl;
			//теперь присвоим к каждому полу возраст
			female_age[i] = ages[i];
			female_index[i] = 2;
		}
	}
	//ну допустим мы сделали всё верно, потом добавим fix
	//типо 1 это мужчина а 2 это женщина, так сделал, можно поменять теперь на желаемое male/female
	cout << "data" << endl;
	cout << endl;
	
	for (int i = 0; i < N; ++i) {
		if (male_age[i] == -858993460);//hhhhhhhhhhhhh так же самое так же самое, просто пишу меньше чтоб учительница милена не закопала меня в гроб увидев такое.
		else {
			cout << names_of_students[i] << " - " ;
			sum += male_age[i]; // for average
			cout << male_age[i] << " y.o. ";
			++index; // for index
			in_block_male_gender[i] = "Male";
			
			cout << in_block_male_gender[i] << endl;
			
		}
	}

	sum = sum/index; // так это вообще то средний возраст а не балс, про балс ни слова здесь
	cout << sum << " avarage age of male`s students " << endl;

	cout << endl;
	
	for (int i = 0; i < N; ++i) {
		if (female_age[i] == -858993460);//also hhhhhhhhhhh тут так же поменял скобки на двоеточие, я бы написал фиксацию в 45.6 то есть два знака fix(2)...
		else {
			cout << names_of_students[i] << " - " ;
			sum2 += female_age[i]; // for average
			cout << female_age[i] << " y.o. ";
			++index2; // for index
			in_block_female_gender[i] = "Female";
			
			cout << in_block_female_gender[i] << endl;
		}
	}

	sum2 = sum2/index2;// и тут так же
	cout  << sum2 << " avarage age of female`s students " << endl;
	
	cout << endl;

	//cout << "count" << endl;
	// new double avg number;
	//cout << "females " << female_index[i] << " " << "males " << male_index << endl;
	system("pause");
	system("cls");
}

void minimal_age_is(int female_age[], int temp, string names_of_students[], string female_gender[]) {
	system("cls");
	/*
	for(int i = 0; i < N; ++i) {
		cout << female_age[i] << endl;
	}
	*/

	cout << endl;
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
} // вот тут нам надо сделать с первого курса задание, вроде бы не сложно?
void age_order(int ages[], int temp, string names_of_students[], string female_gender[], string male_gender[], int block_index[], int index, 
			   int k, string gender[]) {
	
	system("cls");

	cout << endl;

	for(int i = 0; i < N; ++i) {
		block_index[i] = ++index;
	}

	for(int j = 0; j < N; ++j) { // мдех
		for(int i = 0; i < N; ++i) {
			/*
			if (block_index[i] > block_index[i + 1]) {
				temp = block_index[i];
				block_index[i] = block_index[i + 1];
				block_index[i + 1] = temp;
			}
			*/
			if (ages[i] > ages[i + 1]) {

				temp = ages[i];
				ages[i] = ages[i + 1];
				ages[i + 1] = temp;
				
				/*
				s_temp = names_of_students[i];
				names_of_students[i] = names_of_students[i + 1];
				names_of_students[i + 1] = s_temp;

				s_temp = female_gender[i];
				female_gender[i] = female_gender[i + 1];
				female_gender[i + 1] = s_temp;

				s_temp = male_gender[i];
				male_gender[i] = male_gender[i + 1];
				male_gender[i + 1] = s_temp;
				*/
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << ages[i + 1] << " " /*<< names_of_students[i] << " " << gender[i]*/ << endl;
	}
	

	system("pause");
	system("cls");
} //вот тут нам надо сделать бабл сорт

void main() {
	// я понял, но второй файл с данными я создавать пока не буду, всё пока что будет здесь с переменными и данными и тд
	int k = 0;

	int block_index[N];

	string in_block_male_gender[N];
	string in_block_female_gender[N];

	int temp = 0;

	string male_gender[N];
	string female_gender[N];

	int male_index[N]; // мне кажется это не надо
	int female_index[N]; // мне кажется это не надо
	//int male_index=0;
	//int female_index=0;

	int male_age[N];
	int female_age[N];

	int chose;

	int index = 0;
	int index2 = 0;
	double sum = 0.0;
	double sum2 = 0.0;

	string names_of_students[] = {"Masha", "Sasha", "Grisha", "Pasha", "Vika"};
	int faculty_num[] = {2324, 2012, 2003, 2041, 2213};
	double av_balls[] = {58.5, 59.7, 76.2, 92.0, 47.2};
	int ages[] = {25, 40, 23, 74, 2};
	string gender[] = {"Female", "Male", "Male", "Male", "Female"};
	// попробу написать что то типо значит, миша 12 лет - мужчина, закиним в переменную, и что там ещё? выведем эту переменную конечнож
	//menu
	do {

	cout << "MENU" << endl << endl;
	cout << "1. show whole information about of students" << endl;
	cout << "2. age and gender" << endl;
	cout << "3. minimal ages" << endl;
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
			male_and_female(names_of_students, gender, male_gender, female_gender, male_age, female_age, male_index, 
				female_index, ages, sum, index, sum2, index2, in_block_male_gender, in_block_female_gender);
			continue;
		case 3:
			minimal_age_is(female_age, temp, names_of_students, female_gender);
			continue;
		case 4:
			age_order(ages, temp, names_of_students, female_gender, male_gender, block_index, index, k, gender);
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
// исправить баг когда программа выходит и указывает на ages
// добавить fix(2)
// сделать переменные в ряд, не в столбик
// доделать проект уже, поработать с файлом, понять что это за нафиг вообще
// удалить ненужные комментарии