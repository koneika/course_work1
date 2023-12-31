#include <iostream>
#include <string>
#include <fstream>
//#include <ctime> // возможно наверное не нужен

using namespace std; 
const int N = 5;
string NAME = "example.txt";
fstream f;					

struct data{
	string name_of_student;
	int faculty_num;
	double av_balls;
	int age;
	string gender;
};

void info_from_file_about_students(data a[N]){	
		f >> a[0].name_of_student >> a[0].faculty_num >> a[0].av_balls >> a[0].age >> a[0].gender;
		f >> a[1].name_of_student >> a[1].faculty_num >> a[1].av_balls >> a[1].age >> a[1].gender;
		f >> a[2].name_of_student >> a[2].faculty_num >> a[2].av_balls >> a[2].age >> a[2].gender; 
		f >> a[3].name_of_student >> a[3].faculty_num >> a[3].av_balls >> a[3].age >> a[3].gender;
		f >> a[4].name_of_student >> a[4].faculty_num >> a[4].av_balls >> a[4].age >> a[4].gender;  // я не понимаю почему через for(int i...) нельзя
}

void info_student(data a[N]){	
		for(int i = 0; i < N ; ++i)
			cout << a[i].name_of_student << " " << a[i].faculty_num << " " << a[i].av_balls << " " << a[i].age << " " << a[i].gender << " " << endl;
}

void gui(){
	cout << "MENU" << endl << endl;
	cout << "1. input data" << endl;
	cout << "2. output data" << endl;
	cout << "3. overwriting the data for man and woman" << endl;
	cout << "4. sorting by age" << endl;
	cout << "5. the youngest girl" << endl;
	cout /*<< "6. "*/ << endl;
	cout /*<< "7. "*/ << endl;
	cout /*<< "8. settings"*/ << endl;
	cout << "9. debug(random data)" << endl;
	cout << "0. exit" << endl;
}

//void example_for_empty_data_for_input(){
//}

void pause_clear(){
	system("pause");
	system("cls");
}

void clear(){
	system("cls");
}

void debug(data a[N]){
	f.open(NAME, ios::out);				
	string temp_names[100] = {"Aaron", "Abraham", "Adam", "Adrian", "Aidan", "Alan", "Albert", "Alejandro", "Alex", "Alexander", "Alfred", "Andrew", "Angel", "Anthony", "Antonio", "Ashton", "Austin", "Aaliyah", "Abigail", "Ada", "Adelina", "Agatha", "Alexa", "Alexandra", "Alexis", "Alise", "Allison", "Alyssa", "Amanda", "Amber", "Amelia", "Angelina", "Anita", "Ann", "Ariana", "Arianna", "Ashley", "Audrey", "Autumn", "Ava", "Avery", "Benjamin", "Bernard", "Blake", "Brandon", "Brian", "Bruce", "Bryan", "Bailey", "Barbara", "Beatrice", "Belinda", "Brianna", "Bridjet", "Brooke", "Cameron", "Carl", "Carlos", "Charles", "Christopher", "Cole", "Connor", "Caleb", "Carter", "Chase", "Christian", "Clifford", "Cody", "Colin", "Curtis", "Cyrus", "Caroline", "Catherine", "Cecilia", "Celia", "Chloe", "Christine", "Claire", "Daniel", "David", "Dennis", "Devin", "Diego", "Dominic", "Donald", "Douglas", "Dylan", "Daisy", "Danielle", "Deborah", "Delia", "Destiny", "Diana", "Dorothy", "Edward", "Elijah", "Eric", "Ethan", "Evan", "Eleanor"};
	for(int i = 0; i < N; ++i) {
		a[i].name_of_student = temp_names[rand()/501];
		if(rand()/25000 == 1)						
			a[i].gender = "Male";
		else
			a[i].gender = "Female";
		a[i].age = (rand()/1500)+18;
		a[i].av_balls = ((rand()/1000)+50);
		a[i].faculty_num = 23221000 + rand()/50;
		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl;
	}
	f.close(); 
}

void input_data(data a[N]){
	char b; 
	f.open(NAME, ios::out);
	for(int i = 0; i < N; ++i) {
		info_student(a);

		cout << "please, write name of student here:" << endl;	
		cin >> a[i].name_of_student;
		
	}
	for(int i = 0; i < N; ++i) {
		info_student(a);

		cout << "please, write faculty number here:" << endl;	
		cin >> a[i].faculty_num;
		if(!int(a[i].faculty_num)){								
			cout << "Error: write only numbers" << endl;
			pause_clear();
			exit(1);
		}													
		else if(a[i].faculty_num == 0){
			cout << "Error: dont write 0" << endl;
			pause_clear();
			exit(1);
		}
		
	}
	for(int i = 0; i < N; ++i) {
		info_student(a);

		cout << "please, write average balls here:" << endl;
		cin >> a[i].av_balls;
		if(!double(a[i].av_balls)){
			cout << "Error: write only numbers or number with comma" << endl;
			pause_clear();
			exit(1);
		}
		else if(a[i].av_balls == 0){
			cout << "Error: dont write 0" << endl;
			pause_clear();
			exit(1);
		}
	}						
	for(int i = 0; i < N; ++i) {
		info_student(a);

		cout << "please, write age here:" << endl;
		cin >> a[i].age;
		if(!int(a[i].age)){
			cout << "Error: write only numbers" << endl;
			pause_clear();
			exit(1);
		}
		else if(a[i].age == 0){
			cout << "Error: dont write 0" << endl;
			pause_clear();
			exit(1);
		}
	}				


	for(int i = 0; i < N; ++i) {
		info_student(a);

		cout << "please, write gender M or F, M - Male, F - Female, here:" << endl;
		cin >> b;
		if(b == 'M' || b == 'm' || b == 'F' || b == 'f'){
			if(b == 'M' || b == 'm') {						
				a[i].gender = "Male";
			}
			else if(b == 'F' || b == 'f'){
				a[i].gender = "Female";
			}
		}
		else {
			cout << "Error: You are not choose M or F" << endl;
			pause_clear();
			exit(1);
		}
	}

	for(int i = 0; i < N; ++i) {
		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl; // ???
	}

	info_student(a);

	f.close();
}

void output(data a[N]){
	f.open(NAME); 
	info_from_file_about_students(a); 

	info_student(a);
	f.close();
}

void sorting_by_age(data a[N], data a1_rew[N], data a2_rew[N], int &temp){
	f.open(NAME, ios::out | ios::in | ios::app);	
	info_from_file_about_students(a);

	//for(int i = 0; i < N; ++i) {
	//	if(a[i].gender == "Male") {
	//		a1_rew[i].name_of_student = a[i].name_of_student;
	//		a1_rew[i].faculty_num = a[i].faculty_num;
	//		a1_rew[i].av_balls = a[i].av_balls;
	//		a1_rew[i].age = a[i].age;
	//		a1_rew[i].gender = a[i].gender;

	//		++count;
	//	}
	//}
	//for(int i = 0; i < N; ++i) {
	//	if(a[i].gender == "Female") {
	//		a2_rew[i].name_of_student = a[i].name_of_student;
	//		a2_rew[i].faculty_num = a[i].faculty_num;
	//		a2_rew[i].av_balls = a[i].av_balls;
	//		a2_rew[i].age = a[i].age;
	//		a2_rew[i].gender = a[i].gender;

	//		++count;
	//	}
	//}

	for(int j = 0; j < N-1; ++j)
		for(int i = 0; i < N-1; ++i)
			/*if (a2_rew[i].gender == "Female")*/
				if (a[i].age < a[i + 1].age) {
					temp = a[i].age;
					a[i].age = a[i + 1].age;
					a[i + 1].age = temp;
				}
				// сюда стоит добавить по индексу что нибудь, и тогда когда по индексу уже отсортируется, написать по этому же индексу всех и всё как посортировало
				// индекс = возрасту, от индекса будет выводиться инфа в своём порядке, точнее не в своём, а уже в отсортированном
	for(int i = 0; i < N; i++)
		cout << a[i].age << " " << a[i].faculty_num << endl;
	//MAYBE HERE INPORTANT
	//bug cout << a2_rew[count-1].name_of_student << " " << a2_rew[count-1].faculty_num << " " << a2_rew[count-1].av_balls << " " << a2_rew[count-1].age << " " << a2_rew[count-1].gender << endl;
	//for(int i = 0; i < N; i++)
	//	cout << a2_rew[i].name_of_student << " " << a2_rew[i].faculty_num << " " << a2_rew[i].av_balls << " " << a2_rew[i].age << " " << a2_rew[i].gender << endl;
	//count = 0;
	f.close();
	
}
void the_youngest_girl_by_age(data a[N], data a1_rew[N], data a2_rew[N], int &temp, int &count){
	f.open(NAME, ios::out | ios::in | ios::app);
	
	info_from_file_about_students(a);

	//for(int j = 0; j < N; ++j)
	//	for(int i = 0; i < N; ++i)
	//		/*if (a[i].gender == "Female") */
	//			if (a[i].age < a[i + 1].age) {
	//				temp = a[i].age;
	//				a[i].age = a[i + 1].age;
	//				a[i + 1].age = temp;
	//			}


	//for(int i = 0; i < N; ++i) {
	//	if (a[i].gender == "Male") {
	//			a1_rew[i].name_of_student = a[i].name_of_student;
	//			a1_rew[i].faculty_num = a[i].faculty_num;
	//			a1_rew[i].av_balls = a[i].av_balls;
	//			a1_rew[i].age = a[i].age;
	//			a1_rew[i].gender = a[i].gender;

	//			cout << a1_rew[i].name_of_student << " " << a1_rew[i].faculty_num << " " << a1_rew[i].av_balls << " " << a1_rew[i].age << " " << a1_rew[i].gender << endl;
	//			
	//	}
	//}
	////count = 0; sum = 0;
	//for(int i = 0; i < N; ++i) {
	//		a2_rew[i].name_of_student = a[i].name_of_student;
	//		a2_rew[i].faculty_num = a[i].faculty_num;
	//		a2_rew[i].av_balls = a[i].av_balls;
	//		a2_rew[i].age = a[i].age;
	//		a2_rew[i].gender = a[i].gender;
	//}
	//		//++count;
	//for(int j = 0; j < N; ++j)
	//	for(int i = 0; i < N; ++i)
	//		if (a2_rew[i].gender == "Female") 
	//			if (a2_rew[i].age < a2_rew[i + 1].age) {
	//				temp = a2_rew[i].age;
	//				a2_rew[i].age = a2_rew[i + 1].age;
	//				a2_rew[i + 1].age = temp;
	//			}
	//for(int i = 0; i < N; i++)
	//	if(a2_rew[i].gender == "Female")
	//		cout << a2_rew[i].name_of_student << " " << a2_rew[i].faculty_num << " " << a2_rew[i].av_balls << " " << a2_rew[i].age << " " << a2_rew[i].gender << endl;
	//count = 0; sum = 0;
	f.close();
}
//void owerwriting_the_data_for_man_and_woman(data a[N], data a1_rew[N], data a2_rew[N], int &count, float &sum){
//	f.open(NAME, ios::out | ios::in | ios::app);
//
//	output_from_file_info_about_students(a);
//
//	cout << "Male info: " << endl;
//	for(int i = 0; i < N; ++i) {
//		if (a[i].gender == "Male") {
//				a1_rew[i].name_of_student = a[i].name_of_student;
//				a1_rew[i].faculty_num = a[i].faculty_num;
//				a1_rew[i].av_balls = a[i].av_balls;
//				a1_rew[i].age = a[i].age;
//				a1_rew[i].gender = a[i].gender;
//
//				cout << a1_rew[i].name_of_student << " " << a1_rew[i].faculty_num << " " << a1_rew[i].av_balls << " " << a1_rew[i].age << " " << a1_rew[i].gender << endl;
//				++count;
//				sum += a1_rew[i].age;
//		}
//	}	
//	cout << "avg age by Male(s) = " << sum/count << endl;
//	sum = 0; count = 0;
//
//	cout << "Female info:" << endl;
//	for(int i = 0; i < N; ++i) {
//		if(a[i].gender == "Female") {
//			a2_rew[i].name_of_student = a[i].name_of_student;
//			a2_rew[i].faculty_num = a[i].faculty_num;
//			a2_rew[i].av_balls = a[i].av_balls;
//			a2_rew[i].age = a[i].age;
//			a2_rew[i].gender = a[i].gender;
//
//			cout << a2_rew[i].name_of_student << " " << a2_rew[i].faculty_num << " " << a2_rew[i].av_balls << " " << a2_rew[i].age << " " << a2_rew[i].gender << endl;
//			++count;
//			sum += a2_rew[i].age;
//		}
//	}
//	cout << "avg age by Female(s) = " << sum/count << endl; 
//	sum = 0; count = 0;
//
//	f.close();
//}





int main(){
	data a[N]; int choose = 0; data a1_rew[N]; data a2_rew[N]; bool d = 1; int count = 0; float sum = 0; int temp;//data new_av_balls[N];

	do{
		gui();
		cin >> choose;

		if (!int(choose))
			return 0;
		else{
			switch(choose) {	
			case 1:
				clear();
				input_data(a);

				pause_clear();

				continue;
			case 2:
				clear();
				output(a);

				pause_clear();

				continue;
			case 3:
				clear();
				info_from_file_about_students(a);
				pause_clear();

				continue;
			case 4:
				clear();
				sorting_by_age(a, a1_rew, a2_rew, temp);
				
				pause_clear();

				continue;
			case 5:
				clear();

				the_youngest_girl_by_age(a, a1_rew, a2_rew, temp, count);

				pause_clear();
				continue;
			case 9:
				clear();
				debug(a);

				pause_clear();

				continue;
			case 0:
				clear();

				return 0;
			}			
		}
	}while(true);
}