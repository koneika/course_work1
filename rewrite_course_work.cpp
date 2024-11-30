#include <iostream>	// basic lib
#include <string>	// class string
#include <fstream>	// for work with files
#include <ctime>	// just for real random, without sample - srand(unsigned int(time(NULL)));
#include <iomanip>	// only for setw(), no less, no more
using namespace std;

const int N = 5;	// my program can work with any digits here
string NAME = "example.txt";	// here is not const
fstream f;	// fstream = f


struct data{
	string name_of_student;	// students
	int faculty_num;		// faculty numbers
	float av_balls;			// average balls
	int age;				// ages
	string gender;			// genders
};


void InfoFromFileAboutStudents(data a[N]){
	for(int i = 0; i < N; ++i)
		f >> a[i].name_of_student >> a[i].faculty_num >> a[i].av_balls >> a[i].age >> a[i].gender;

}				// just reading from file example.txt, must be for initialize that info from file, for view info from data file

void InfoStudents(data a[N]){


	cout << "===============================================================" << endl;
	cout << "||" << setw(16) << "Names" << " || " << setw(10) << "F. Numbers" << " || " << setw(7) << "Avg. M." << " || " << setw(3) << "Age" << " || " << setw(6) 
		<< "Gender"  << " ||" << endl;
	cout << "===============================================================" << endl;
	// Graphical thing

	for(int i = 0; i < N ; ++i){
		if(a[i].gender == "Female")
			cout << "||" << setw(16) << a[i].name_of_student << " || " << setw(10) << a[i].faculty_num << " || " << setw(7) << a[i].av_balls << " || " << setw(3) 
			<< a[i].age << " || " << setw(5) << a[i].gender << " ||" << endl;
		else
			cout << "||" << setw(16) << a[i].name_of_student << " || " << setw(10) << a[i].faculty_num << " || " << setw(7) << a[i].av_balls << " || " << setw(3) 
			<< a[i].age << " || " << setw(4) << a[i].gender << "   ||" << endl;
	}

	cout << "===============================================================" << endl;
	// Graphical thing
}				// this is function very useful for just input all of data about students/from struct arrays to DevOption() and Output() function


void GUI(){		// Graphical User Interface

	cout << "MENU" << endl << endl;
	cout << "1. Input Data" << endl;
	cout << "2. Output Data" << endl;
	cout << "3. Average Balls By Man And Woman" << endl;
	cout << "4. Sorting By Age" << endl;
	cout << "5. The Youngest Girl" << endl;
	cout /*<< "6. "*/ << endl;
	cout /*<< "7. "*/ << endl;
	cout /*<< "8. Settings"*/ << endl;
	cout << "9. Developer Option(Random Data)" << endl;
	cout << "0. Exit" << endl;

}				// its for text graphical interface, i use function gui(); for easy to use that

void pause_clear(){
	system("pause");
	system("cls");
}	// its not necessary, but for me its just comfortable to use this


void clear(){
	system("cls");
}	// also comfortable use 


void DevOption(data a[N]){	// this function create a random info about students, and save to the file
	f.open(NAME, ios::out);	// some of explain, ios::out using for delete last data and create new data file
							// so, it is recreate a file every using Developer Option
	
		// input 100 names and after that we will mix this names
	string temp_names[100] = {"Aaron", "Abraham", "Adam", "Adrian", "Aidan", "Alan", "Albert", "Alejandro", "Alex", "Alexander", "Alfred", "Andrew", "Angel", "Anthony", "Antonio", 
		"Ashton", "Austin", "Aaliyah", "Abigail", "Ada", "Adelina", "Agatha", "Alexa", "Alexandra", "Alexis", "Alise", "Allison", "Alyssa", "Amanda", "Amber", "Amelia", "Angelina", 
		"Anita", "Ann", "Ariana", "Arianna", "Ashley", "Audrey", "Autumn", "Ava", "Avery", "Benjamin", "Bernard", "Blake", "Brandon", "Brian", "Bruce", "Bryan", "Bailey", "Barbara", 
		"Beatrice", "Belinda", "Brianna", "Bridjet", "Brooke", "Cameron", "Carl", "Carlos", "Charles", "Christopher", "Cole", "Connor", "Caleb", "Carter", "Chase", "Christian", 
		"Clifford", "Cody", "Colin", "Curtis", "Cyrus", "Caroline", "Catherine", "Cecilia", "Celia", "Chloe", "Christine", "Claire", "Daniel", "David", "Dennis", "Devin", "Diego", 
		"Dominic", "Donald", "Douglas", "Dylan", "Daisy", "Danielle", "Deborah", "Delia", "Destiny", "Diana", "Dorothy", "Edward", "Elijah", "Eric", "Ethan", "Evan", "Eleanor"};
		
		// randomizer algorithm
	for(int i = 0; i < N; ++i) {
		
		// program randomly choose in range 0-99 something names from temp_names[100]
		a[i].name_of_student = temp_names[rand()/501];
		
		// random range 0-1, if 1 = male, if 0 = female
		if(rand()/25000 == 1)						
			a[i].gender = "Male";
		else
			a[i].gender = "Female";
		
		// random range for age, 18-51 years old
		a[i].age = (rand()/1500)+18;
		
		// random range for avarage balls, 50-100 balls
		a[i].av_balls = float((rand()/1000)+50.5);
		
		// range for faculty number, 23221000-23222000 faculty numbers
		a[i].faculty_num = 23221000 + rand()/50;

		// now put this data to my example.txt please
		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl;
	}

	f.close(); 
}


void InputData(data a[N]){// funtion for input data from keyboard
	char b;	// variable for choose M or F
	f.open(NAME);	// we only open that file for view a data from example.txt, no change
					// i will use a change function below, because i do not want lose my data right now, 
					// while i writing an info about students in my file

					// so, must not reacreate a file, it is savety
	
	
	

	for(int i = 0; i < N; ++i) {
		InfoFromFileAboutStudents(a); // it is necessary for reading a data from file, without that you do not have a info from file
		clear();				// just clear text on console 
		InfoStudents(a);	// write graphical user interface data from file, like cout

		cout << endl << "please, write name of student here:" << endl;
		cin >> a[i].name_of_student;	// input from keyboard 5 times a name of student here

	}
	for(int i = 0; i < N; ++i) {
		clear();
		InfoStudents(a);

		cout << endl << "please, write faculty number here:" << endl;
		cin >> a[i].faculty_num;		// input 5 times a faculty number
	}
	for(int i = 0; i < N; ++i) {
		clear();
		InfoStudents(a);

		cout << endl << "please, write average balls here:" << endl;
		cin >> a[i].av_balls;			// input 5 times an average ball
	}						
	for(int i = 0; i < N; ++i) {
		clear();
		InfoStudents(a);

		cout << endl << "please, write age here:" << endl;
		cin >> a[i].age;				// input 5 times an age
	}				


	for(int i = 0; i < N; ++i) {
		clear();
		InfoStudents(a);

		cout << endl << "please, write gender M or F, M - Male, F - Female, here:" << endl;
		cin >> b;						// input 5 times a choise

		if(b == 'M' || b == 'm' || b == 'F' || b == 'f'){	// M or m or F or f
			if(b == 'M' || b == 'm') {						// if M || m
				a[i].gender = "Male";						// write Male to gender array
			}
			else if(b == 'F' || b == 'f'){					// if F or f
				a[i].gender = "Female";						// write Female to gender array
			}
		}
		else {
			cout << "Error: You are not choose M or F" << endl;// if you dont use M, m, F, f = error, go out 
			pause_clear();
			exit(1);
		}
	}
	f.close();
	f.open(NAME, ios::out);
	for(int i = 0; i < N; ++i) {
		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl; // after all of this, we write a data to the file example.txt
	}

	clear();
	InfoStudents(a);

	f.close();
}

void Output(data a[N]){
	f.open(NAME);

	InfoFromFileAboutStudents(a);

	InfoStudents(a);

	f.close();
}

void OverwritingTheDataForManAndWoman(data a[N], data a1_rew[N], data a2_rew[N], int &count, float &sum){
	f.open(NAME);
	InfoFromFileAboutStudents(a); 

	cout << "Male info: " << endl;
	cout << "===============================================================" << endl;
	cout << "||" << setw(16) << "Names" << " || " << setw(10) << "F. Numbers" << " || " << setw(7) << "Avg. M." << " || " << setw(3) << "Age" << " || " << setw(6) 
		<< "Gender"  << " ||" << endl;
	cout << "===============================================================" << endl;

	for(int i = 0; i < N; ++i) {	// recreate new array, as from my task, just a = a1_rew (a = array, a1 = array1, a1_rew = array1 rewrite)
		if (a[i].gender == "Male") { // unknow gender = know gender
				a1_rew[i].name_of_student = a[i].name_of_student;
				a1_rew[i].faculty_num = a[i].faculty_num;
				a1_rew[i].av_balls = a[i].av_balls;
				a1_rew[i].age = a[i].age;
				a1_rew[i].gender = a[i].gender; // we have the new arrays

				
				cout << "||" << setw(16) << a1_rew[i].name_of_student << " || " << setw(10) << a1_rew[i].faculty_num << " || " << setw(7) << a1_rew[i].av_balls << " || " << setw(3) 
			<< a1_rew[i].age << " || " << setw(4) << a1_rew[i].gender << "   ||" << endl;
				// just for Graphics

				++count;
				// must for make an average age
				sum += a1_rew[i].age;
				// add every array.age to summa for make an average age
		}
	}	


	cout << "===============================================================" << endl;
	cout << "average age by Male(s) = " << sum/count << endl;
	
	sum = 0; count = 0;

	cout << endl << endl << endl << "Female info:" << endl;
	cout << "===============================================================" << endl;
	cout << "||" << setw(16) << "Names" << " || " << setw(10) << "F. Numbers" << " || " << setw(7) << "Avg. M." << " || " << setw(3) << "Age" << " || " << setw(6) 
		<< "Gender"  << " ||" << endl;
	cout << "===============================================================" << endl;
	// just for graphical


	for(int i = 0; i < N; ++i) {	// unknow gender to know gender
		if(a[i].gender == "Female") {
			a2_rew[i].name_of_student = a[i].name_of_student;
			a2_rew[i].faculty_num = a[i].faculty_num;
			a2_rew[i].av_balls = a[i].av_balls;
			a2_rew[i].age = a[i].age;
			a2_rew[i].gender = a[i].gender; // rewrite unknown gender to know gender

			cout << "||" << setw(16) << a2_rew[i].name_of_student << " || " << setw(10) << a2_rew[i].faculty_num << " || " << setw(7) << a2_rew[i].av_balls << " || " << setw(3) 
			<< a2_rew[i].age << " || " << setw(5) << a2_rew[i].gender << " ||" << endl;
			// just for graphical

			++count;
			sum += a2_rew[i].age;
		}
	}
	cout << "===============================================================" << endl;
	cout << "average age by Female(s) = " << sum/count << endl; 

	sum = 0; count = 0;

	f.close();
	// we have a 2 arrays, a1_rew[] = Male, a2_rew = Female
	// like my task wanted

	// my opinion, honestly
	// i think it is useless new recreted arrays, because it might works without recreated
	// also it is useless, because nowhere using every where
	// but my task wanted
}

void SortingByAge(data a[N], int &temp, string &temp1, float &temp2){
	f.open(NAME);	
	InfoFromFileAboutStudents(a);

	for(int j = 0; j < N-1; ++j)
		for(int i = 0; i < N-1; ++i)
				if (a[i].age < a[i + 1].age) { // target age, but bubble sorting not only for age, sorting all of info
					temp = a[i].age;
					a[i].age = a[i + 1].age;
					a[i + 1].age = temp;

					temp1 = a[i].name_of_student;
					a[i].name_of_student = a[i + 1].name_of_student;
					a[i + 1].name_of_student = temp1;

					temp = a[i].faculty_num;
					a[i].faculty_num = a[i + 1].faculty_num;
					a[i + 1].faculty_num = temp;

					temp2 = a[i].av_balls;
					a[i].av_balls = a[i + 1].av_balls;
					a[i + 1].av_balls = temp2;
					
					temp1 = a[i].gender;
					a[i].gender = a[i + 1].gender;
					a[i + 1].gender = temp1;
				}
	InfoStudents(a);

	f.close();
}

void TheYoungestGirlByAge(data a[N], int &temp, string &temp1, float &temp2){
	f.open(NAME);	
	InfoFromFileAboutStudents(a);

	for(int j = 0; j < N-1; ++j)
		for(int i = 0; i < N-1; ++i)
				if (a[i].age < a[i + 1].age) {
					temp = a[i].age;
					a[i].age = a[i + 1].age;
					a[i + 1].age = temp;

					temp1 = a[i].name_of_student;
					a[i].name_of_student = a[i + 1].name_of_student;
					a[i + 1].name_of_student = temp1;

					temp = a[i].faculty_num;
					a[i].faculty_num = a[i + 1].faculty_num;
					a[i + 1].faculty_num = temp;

					temp2 = a[i].av_balls;
					a[i].av_balls = a[i + 1].av_balls;
					a[i + 1].av_balls = temp2;
					
					temp1 = a[i].gender;
					a[i].gender = a[i + 1].gender;
					a[i + 1].gender = temp1;
				}
	cout << "===============================================================" << endl;
	cout << "||" << setw(16) << "Names" << " || " << setw(10) << "F. Numbers" << " || " << setw(7) << "Avg. M." << " || " << setw(3) << "Age" << " || " << setw(6) 
		<< "Gender"  << " ||" << endl;
	cout << "===============================================================" << endl;




	int i = -1; // -1
	bool close = false; // 0
	do{
		i++; // start variable i = 0
		if(a[N-1-i].gender == "Female"){ // for example N = 5, 5-1-0 = 4 or array index
			cout << "||" << setw(16) << a[N-1-i].name_of_student << " || " << setw(10) << a[N-1-i].faculty_num << " || " << setw(7) << a[N-1-i].av_balls << " || " << setw(3) 
			<< a[N-1-i].age << " || " << setw(5) << a[N-1-i].gender << " ||" << endl;
			cout << "===============================================================" << endl;


			close = true;
			// if we find, close = 1 or go out
		}
		// for example N = 5, if i = 5 and nothing to work above, we go to below function with "we cant find a girl and close = 1 or go out"
		else if(N-1-i < 1){
			cout << "Error, program cannot find a Female" << endl;
			close = true;
		}
	}while(close == false);

	f.close();
}

int main(){
	srand(unsigned int(time(NULL))); // i use unsigned int from "stack overflow", because my compiler warning that
	int choose, count = 0, temp;
	float sum = 0, temp2; 
	string temp1;
	data a[N], a1_rew[N], a2_rew[N];
	
	do{
		
		GUI();
		cin >> choose;
		
		switch(choose) {
			
			case 1:
				clear();
				InputData(a);

				pause_clear();

				continue;
			case 2:
				clear();
				Output(a);

				pause_clear();

				continue;
			case 3:
				clear();
				OverwritingTheDataForManAndWoman(a, a1_rew, a2_rew, count, sum);
				pause_clear();

				continue;
			case 4:
				clear();
				SortingByAge(a, temp, temp1, temp2);
				
				pause_clear();

				continue;
			case 5:
				clear();
				TheYoungestGirlByAge(a, temp, temp1, temp2);

				pause_clear();
				continue;
			case 9:
				clear();
				DevOption(a);
				InfoStudents(a);

				pause_clear();

				continue;
			case 0:
				clear();

				return 0;
			}

		
	}while(choose > -1 && choose < 6 || choose == 9);

	return 0;
}

		//char name[10];
		//gets(name);
		//int n = strlen(name);
		//cout << n;