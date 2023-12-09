#include <iostream> // based
#include <string> // c-string
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std; // no need write std::cout, std::endl, etc.

const int N = 5;

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
	//variabels and arrays
	string temp_names[100];

	//open file
	fstream f("test.txt", ios::out); 
	fstream f2("random_names.txt", ios::out | ios::in | ios::app);

	//from file go to array 100 times 100 patern names
	for(int i = 0; i < 100; ++i) {
		f2 >> temp_names[i]; // temp_names[0], ... temp_names[99] = patern_names
	}

	//hard alforithm for create the names, 
	//from random_names.txt we take a patern of names and then 
	//we mixed it and see random names, 
	//then put it on file
	for(int i = 0; i < N; ++i) {
		//suka null i time naxui // kak eta blyaty rabotaet?
		//cout << temp_names[rand()/500] << " " << rand()/500 << endl;
		arr[i].name_of_student = temp_names[rand()/500];
		if(rand()/25000 == 1)
			arr[i].gender = "Male";
		else
			arr[i].gender = "Female";

		arr[i].age = (rand()/1500)+18;
		arr[i].av_balls = ((rand()/1000)+50)/0.99;
		arr[i].faculty_num = 23221000 + rand()/50;
		/*cout << arr[i].name_of_student << endl;*/
		//arr[i].name_of_student = temp_names[i];
		f << arr[i].name_of_student << " ";
		f << arr[i].faculty_num << " ";
		f << arr[i].av_balls << " ";
		f << arr[i].age << " ";
		f << arr[i].gender << " " << endl;
	}

	//for(int i = 0; i < N; ++i) {
	//	if (arr[i].name_of_student == "")
	//		arr[formula].name_of_student = temp_names[i];
	//	else 
	//		cout << arr[i].name_of_student << endl;
	//}

	f2.close();
	f.close(); 

}



void input_data(info arr[N]){
	//string write;
	 // because in file we have a space
	//getline(cin, arr[0].gender);
	//fstream f("test.txt", ios::out); // create the file for writing
	//for(int i = 0; i < N; ++i) {
		cin.ignore();
		getline(cin, arr[0].name_of_student);
		//f << arr[i].name_of_student << endl;
	//}
	
	//cout << "name " << "faculty number " << "average balls " << "age " << "gender " << endl;
	//getline(cin, arr[0].name_of_student);
	//if(write == " ")
		//return;
	//for(int i = 0; i < N; ++i) {
	//	cout << "name of student" << endl;
	//	cin >> arr[i].name_of_student;

	//	f << arr[i].name_of_student << endl;

	//	cout << "faculty" << endl;
	//	cin >> arr[i].faculty_num;
	//	f << arr[i].faculty_num << endl;


	//	cout << "av_balls" << endl;
	//	cin >> arr[i].av_balls;
	//	f << arr[i].av_balls << endl;


	//	cout << "age" << endl;
	//	cin >> arr[i].age;
	//	f << arr[i].age << endl;



	//	cout << "gender" << endl << endl;
	//	cout << "1. Male" << endl;
	//	cout << "2. Female" << endl;

	//	int choose = 0;
	//	cin >> choose;

	//	if(choose == 1 || choose == 2) {
	//		if (choose == 1) {
	//			arr[i].gender = "Male";
	//			f << arr[i].gender << endl;
	//		}
	//		else {
	//			arr[i].gender = "Female";
	//			f << arr[i].gender << endl;
	//		}
	//	}
	//	else {
	//		arr[i].gender = "Mutant(Error)";
	//		f << arr[i].gender << endl;
	//		exit(1);//protect for infinity loop
	//	}
	//	
	//	f << endl;


	//}


	//f.close(); // close file
}

void input_random_data(){
	//future
}

void output_data(info arr[N]){
	string a;

	fstream f("test.txt");
	// put from file our arrays
	for(int i = 0; i < N; ++i) {
		f >> arr[i].name_of_student;
		f >> arr[i].faculty_num;
		f >> arr[i].av_balls;
		f >> arr[i].age;
		f >> arr[i].gender;
		cout << arr[i].name_of_student << " " << arr[i].faculty_num << " " << arr[i].av_balls << " " << arr[i].age << " " << arr[i].gender << endl;
	}

	f.close();
}


int main(){
	//srand(time(NULL));
	info arr[N]; int choose = 0;





	do{

		gui();
		cin >> choose;

		if (!int(choose))
			return 0; // for error write

		switch(choose) {	
		case 1:
			input_data(arr);
			pause_clear();
			continue;
		case 2:
			output_data(arr);
			pause_clear();
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