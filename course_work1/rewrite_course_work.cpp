#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

const int N = 5;

fstream f("test.txt");

struct info{
	string name_of_student;
	int faculty_num;
	double av_balls;
	int age;
	string gender;
};

void gui(){
	cout << "1. input data" << endl;
	cout << "2. output data" << endl;
	cout << "5. exit" << endl;
}

void clear(){
	system("cls");
}

void pause_clear(){
	system("pause");
	system("cls");
}

void debug(info arr[N])
{
	string temp_names[] = {"Aaron", "Abraham", "Adam", "Adrian", "Aidan", "Alan", "Albert", "Alejandro", "Alex", "Alexander", "Alfred", "Andrew", "Angel", "Anthony", "Antonio", "Ashton", "Austin", "Aaliyah", "Abigail", "Ada", "Adelina", "Agatha", "Alexa", "Alexandra", "Alexis", "Alise", "Allison", "Alyssa", "Amanda", "Amber", "Amelia", "Angelina", "Anita", "Ann", "Ariana", "Arianna", "Ashley", "Audrey", "Autumn", "Ava", "Avery", "Benjamin", "Bernard", "Blake", "Brandon", "Brian", "Bruce", "Bryan", "Bailey", "Barbara", "Beatrice", "Belinda", "Brianna", "Bridjet", "Brooke", "Cameron", "Carl", "Carlos", "Charles", "Christopher", "Cole", "Connor", "Caleb", "Carter", "Chase", "Christian", "Clifford", "Cody", "Colin", "Curtis", "Cyrus", "Caroline", "Catherine", "Cecilia", "Celia", "Chloe", "Christine", "Claire", "Daniel", "David", "Dennis", "Devin", "Diego", "Dominic", "Donald", "Douglas", "Dylan", "Daisy", "Danielle", "Deborah", "Delia", "Destiny", "Diana", "Dorothy", "Edward", "Elijah", "Eric", "Ethan", "Evan", "Eleanor", "Elizabeth", "Ella", "Emily", "Emma", "Erin", "Evelyn", "Francis", "Fred", "Faith", "Fiona", "Florence", "Freda", "Gabriel", "Gavin", "Geoffrey", "George", "Gerld", "Gilbert", "Gordon", "Graham", "Gregory", "Gloria", "Gabriella", "Gabrielle", "Gladys", "Grace", "Harold", "Harry", "Hayden", "Henry", "Herbert", "Horace", "Howard", "Hugh", "Hunter", "Hailey", "Haley", "Hannah", "Helen", "Ian", "Isaac", "Isaiah", "Isabel", "Isabella", "Jack", "Jackson", "Jacob", "Jaden", "Jake", "James", "Jason", "Jayden", "Jeffery", "Jeremiah", "Jesse", "Jesus", "John", "Jonathan", "Jordan", "Jose", "Joseph", "Joshua", "Juan", "Julian", "Justin", "Jacqueline", "Jada", "Jane", "Jasmine", "Jenna", "Jennifer", "Jessica", "Jocelyn", "Jordan", "Josephine", "Joyce", "Julia"};

	fstream f2("random_names.txt", ios::out | ios::in | ios::app);

	for(int i = 0; i < 100; ++i) {
		f2 >> temp_names[i];
	}

	for(int i = 0; i < N; ++i) {

		arr[i].name_of_student = temp_names[rand()/500];
		if(rand()/25000 == 1)
			arr[i].gender = "Male";
		else
			arr[i].gender = "Female";

		arr[i].age = (rand()/1500)+18;
		arr[i].av_balls = ((rand()/1000)+50)/0.99;
		arr[i].faculty_num = 23221000 + rand()/50;
		f << arr[i].name_of_student << " ";
		f << arr[i].faculty_num << " ";
		f << arr[i].av_balls << " ";
		f << arr[i].age << " ";
		f << arr[i].gender << " " << endl;
	}

	f2.close();
	f.close(); 
	clear();
}

void pure_data(info arr[N]){
	f.open("test.txt");
	for(int i = 0; i < N; ++i) {
		arr[i].name_of_student = "Pure";
		arr[i].age = 0;
		arr[i].faculty_num = 0;
		arr[i].av_balls = 0;
		arr[i].gender = "Female";

		f << arr[i].name_of_student << " ";
		f << arr[i].faculty_num << " ";
		f << arr[i].av_balls << " ";
		f << arr[i].age << " ";
		f << arr[i].gender << " " << endl;
	}
	f.close();
}


void output(info arr[N]){
	for(int i = 0; i < N ; ++i)
		cout << arr[i].name_of_student << " " << arr[i].faculty_num << " " << arr[i].av_balls << " " << arr[i].age << " " << arr[i].gender << endl;
}

void input_data(info arr[N]){
	char a;
	f.open("test.txt", ios::app);

	for(int i = 0; i < N; ++i) {
		clear();
		output(arr);

		cout << "please, write name of student here:" << endl;
		cin >> arr[i].name_of_student;
		f >> arr[i].name_of_student;
		
	}
	for(int j = 0; j < N; ++j) {
		clear();
		output(arr);
		cout << "please, write faculty number here:" << endl;
		cin >> arr[j].faculty_num;
		f >> arr[j].faculty_num;
	}
	for(int k = 0; k < N; ++k) {
		clear();
		output(arr);
		cout << "please, write average balls here:" << endl;
		cin >> arr[k].av_balls;
		f >> arr[k].av_balls;
	}
	for(int l = 0; l < N; ++l) {
		clear();
		output(arr);
		cout << "please, write age here:" << endl;
		cin >> arr[l].age;
		f >> arr[l].age;
	}
	for(int m = 0; m < N; ++m) {
		clear();
		output(arr);
		cout << "please, write gender M or F, M - Male, F - Female, here:" << endl;

		cin >> a;
		if(a == 'M' || a == 'm' || a == 'F' || a == 'f'){
			if(a == 'M' || a == 'm') {
				cout << "Male" << endl;
				arr[m].gender = "Male";
				f >> arr[m].gender;
			}
			else if(a == 'F' || a == 'f'){
				cout << "Female" << endl;
				arr[m].gender = "Female";
				f >> arr[m].gender;
			}
		}
		else {
			cout << "You are not choose M or F, try again" << endl;
			pause_clear();
			break;
		}
	}
	




	clear();
	output(arr);
	f.close();
}

void input_random_data(){
	//future
}

void output_data(info arr[N]){
	string a;
	clear();
	for(int i = 0; i < N; ++i) {
		f >> arr[i].name_of_student;
		f >> arr[i].faculty_num;
		f >> arr[i].av_balls;
		f >> arr[i].age;
		f >> arr[i].gender;
	}
	output(arr);
	f.close();
}


int main(){
	//srand(time(NULL));
	info arr[N]; int choose = 0;

	pure_data(arr);

	do{

		gui();
		cin >> choose;

		if (!int(choose))
			return 0; // for error write

		switch(choose) {	
		case 1:
			input_data(arr);
			//pause_clear();
			continue;
		case 2:
			output_data(arr);
			//pause_clear();
			continue;
		case 5:
			return 0;
		case 9:
			debug(arr);
			continue;
		}

	}while(true);


	return 0;
}























/*
for(int i = 0; i < N; ++i) {
arr[i] = rand();
f << arr[i] << endl;
}

*/