﻿#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

const int N = 5; // потом поменять здеся на 30 штук, хотя для презентации и 5 хватит
string NAME = "test.txt"; // а вдруг ты хочешь свой файл сюда запихнуть?

fstream f; // fstream f(NAME);

//void change_settings(string &NAME, bool &d){
//	if(d == true){
//		cin >> NAME;
//	}
//
//
//
//}
//
//void settings(string &NAME, bool &d){
//	cout << "1. ask change file name - " << d << endl;
//	cin >> d;
//
//	if(d == true){
//		cout << "write the name of file for work with that file, must be: example.txt" << endl;
//		cin >> NAME;
//	}
//	cout << NAME << endl;
//
//}








// и у тебя по факту будет выбор, смотри

// программа запускается, тебя спрашивают, название вашего файла?
// будет выбор между enter = by program default choise
// так же будет вкладка настройки, где можно будет отключить постоянное спрашивание, и будет там уже задаваться имя файла которое должна открыть программа по умолчанию
// и многое другое в настройках в будующем, работа с файлами, которую я и сейчас реализовываю

// так же добавить функцию включения отображения developer mode, true или false чтоб было
// так же во вкладке настройки нужно добавить название, и там нужно выбрать, и так же там будет отображатся, работает ли та или иная настройка или не работает



struct data{
	string name_of_student;
	int faculty_num;
	double av_balls;
	int age;
	string gender;
};

void gui(){
	cout << "1. input data" << endl;
	cout << "2. output data" << endl;
	cout << "3. owerwriting the data for man and woman" << endl;
	cout /*<< "4. "*/ << endl;
	cout /*<< "5. "*/ << endl;
	cout /*<< "6. "*/ << endl;
	cout /*<< "7. "*/ << endl;
	cout /*<< "8. settings"*/ << endl;
	cout << "9. debug(random data)" << endl;
	cout << "0. exit" << endl;
}


//lol developer shizo writing
void output(data a[N]){
	for(int i = 0; i < N ; ++i)
		cout << a[i].name_of_student << " " << a[i].faculty_num << " " << a[i].av_balls << " " << a[i].age << " " << a[i].gender << endl;
}

void pause_clear(){
	system("pause");
	system("cls");
}

void clear(){
	system("cls");
}

void clear_output(data a[N]){
	clear();
	output(a);
}









//really useful for developer
void debug(data a[N])
{
	string temp_names[] = {"Aaron", "Abraham", "Adam", "Adrian", "Aidan", "Alan", "Albert", "Alejandro", "Alex", "Alexander", "Alfred", "Andrew", "Angel", "Anthony", "Antonio", "Ashton", "Austin", "Aaliyah", "Abigail", "Ada", "Adelina", "Agatha", "Alexa", "Alexandra", "Alexis", "Alise", "Allison", "Alyssa", "Amanda", "Amber", "Amelia", "Angelina", "Anita", "Ann", "Ariana", "Arianna", "Ashley", "Audrey", "Autumn", "Ava", "Avery", "Benjamin", "Bernard", "Blake", "Brandon", "Brian", "Bruce", "Bryan", "Bailey", "Barbara", "Beatrice", "Belinda", "Brianna", "Bridjet", "Brooke", "Cameron", "Carl", "Carlos", "Charles", "Christopher", "Cole", "Connor", "Caleb", "Carter", "Chase", "Christian", "Clifford", "Cody", "Colin", "Curtis", "Cyrus", "Caroline", "Catherine", "Cecilia", "Celia", "Chloe", "Christine", "Claire", "Daniel", "David", "Dennis", "Devin", "Diego", "Dominic", "Donald", "Douglas", "Dylan", "Daisy", "Danielle", "Deborah", "Delia", "Destiny", "Diana", "Dorothy", "Edward", "Elijah", "Eric", "Ethan", "Evan", "Eleanor", "Elizabeth", "Ella", "Emily", "Emma", "Erin", "Evelyn", "Francis", "Fred", "Faith", "Fiona", "Florence", "Freda", "Gabriel", "Gavin", "Geoffrey", "George", "Gerld", "Gilbert", "Gordon", "Graham", "Gregory", "Gloria", "Gabriella", "Gabrielle", "Gladys", "Grace", "Harold", "Hay", "Hayden", "Henry", "Herbert", "Horace", "Howard", "Hugh", "Hunter", "Hailey", "Haley", "Hannah", "Helen", "Ian", "Isaac", "Isaiah", "Isabel", "Isabella", "Jack", "Jackson", "Jacob", "Jaden", "Jake", "James", "Jason", "Jayden", "Jeffery", "Jeremiah", "Jesse", "Jesus", "John", "Jonathan", "Jordan", "Jose", "Joseph", "Joshua", "Juan", "Julian", "Justin", "Jacqueline", "Jada", "Jane", "Jasmine", "Jenna", "Jennifer", "Jessica", "Jocelyn", "Jordan", "Josephine", "Joyce", "Julia"};

	for(int i = 0; i < N; ++i) {

		a[i].name_of_student = temp_names[rand()/500];
		if(rand()/25000 == 1)
			a[i].gender = "Male";
		else
			a[i].gender = "Female";

		a[i].age = (rand()/1500)+18;
		a[i].av_balls = ((rand()/1000)+50)/0.99;
		a[i].faculty_num = 23221000 + rand()/50;
		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl;
		//ЭХ ВОТ БЫ КТО НИБУДЬ УВИДЕЛ
		//И ДОБАВИЛ БЫ ФИКСИНГ ВЕЗДЕ ГДЕ ТОЛЬКО ЭТО ВОМЗОЖНО ПРИМЕНИТЬ КО ВСЕМ FLOAT

		//кстати что такое unsigned float?◘
	}

	f.close(); 

}

void pure_data(data a[N]){
	f.open(NAME);
	for(int i = 0; i < N; ++i) {
		a[i].name_of_student = "Pure";
		a[i].age = 0;
		a[i].faculty_num = 0;
		a[i].av_balls = 0;
		a[i].gender = "Female";

		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl;
	}
	f.close();
}










void input_data(data a[N]){
	
//вот бы кто нибудь обратил на меня внимание♥
//и сделал бы так, чтобы если бы тип данных не равен типу данных, ♥
//то программа бы ломалась♥
	char b;
	f.open(NAME, ios::app);

	for(int i = 0; i < N; ++i) {
		clear_output(a);

		cout << "please, write name of student here:" << endl;
		cin >> a[i].name_of_student;
		f >> a[i].name_of_student;
		// no need error post code here because string can works with any char
	}
	for(int i = 0; i < N; ++i) {
		clear_output(a);

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

		f >> a[i].faculty_num;
	}
	for(int i = 0; i < N; ++i) {
		clear_output(a);

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
		f >> a[i].av_balls;
		
	}
	for(int i = 0; i < N; ++i) {
		clear_output(a);

		cout << "please, write age here:" << endl;
		
		cin >> a[i].age;
		
		if(!int(a[i].age)){
			cout << "Error: write only numbers" << endl; // НУ ПОЧЕМУ НЕТ ОШИБКИ
			pause_clear();
			exit(1);
		}
		else if(a[i].age == 0){
			cout << "Error: dont write 0" << endl;
			pause_clear();
			exit(1);
		}
		f >> a[i].age;
		
	}
	for(int i = 0; i < N; ++i) {
		clear_output(a);

		cout << "please, write gender M or F, M - Male, F - Female, here:" << endl;

		cin >> b;

		if(b == 'M' || b == 'm' || b == 'F' || b == 'f'){


			if(b == 'M' || b == 'm') {
				a[i].gender = "Male";
				f >> a[i].gender;
			}


			else if(b == 'F' || b == 'f'){
				a[i].gender = "Female";
				f >> a[i].gender;
			}


		}
		else {
			cout << "Error: You are not choose M or F" << endl;
			pause_clear();
			exit(1);
		}


	}
	




	f.close();
}

void output_data(data a[N]){
	//string a;
	//clear();
	for(int i = 0; i < N; ++i) {
		f >> a[i].name_of_student;
		f >> a[i].faculty_num;
		f >> a[i].av_balls;
		f >> a[i].age;
		f >> a[i].gender;
	}
	
	f.close();
	
}
// как же?
// зачем мне два output??


void unknown_gender_is_know(data a[N], data a1_rew[N], data a2_rew[N]){
	for(int i = 0; i < N; ++i) {
		if (a[i].gender == "Male") {
				a1_rew[i].name_of_student = a[i].name_of_student;
				a1_rew[i].faculty_num = a[i].faculty_num;
				a1_rew[i].av_balls = a[i].av_balls;
				a1_rew[i].age = a[i].age;
				a1_rew[i].gender = a[i].gender;
		}
	}
	for(int i = 0; i < N; ++i) {
		if(a[i].gender == "Female") {
			a2_rew[i].name_of_student = a[i].name_of_student;
			a2_rew[i].faculty_num = a[i].faculty_num;
			a2_rew[i].av_balls = a[i].av_balls;
			a2_rew[i].age = a[i].age;
			a2_rew[i].gender = a[i].gender;
		}
	}
}

void owerwriting_the_data_for_man_and_woman(data a[N], data a1_rew[N], data a2_rew[N], int &count, float &sum/*, temp_male[N], temp_female[N]*/){
	f.open(NAME);
	
	//rewrite data arr to new data arr
	/*for(int i = 0; i < N; ++i){
		a_rew[i].name_of_student = a[i].name_of_student;
		a_rew[i].faculty_num = a[i].faculty_num;
		a_rew[i].av_balls = a[i].av_balls;
		a_rew[i].age = a[i].age;
		a_rew[i].gender = a[i].gender;
	}*/



	/////data male_age[N];

	cout << "Male info: " << endl;
	unknown_gender_is_know(a, a1_rew, a2_rew);
	for(int i = 0; i < N; i++) {
		cout << a1_rew[i].name_of_student << " " << a1_rew[i].faculty_num << " " << a1_rew[i].av_balls << " " << a1_rew[i].age << " " << a1_rew[i].gender << endl;
				
		++count;
		sum += a1_rew[i].age;
		cout << "avg age by Male(s) = " << sum/count << endl;
	}
	sum = 0; count = 0;
	//for(int i = 0; i < N ; ++i)
	//	cout << a_rew[i].name_of_student << " " << a_rew[i].faculty_num << " " << a_rew[i].av_balls << " " << a_rew[i].age << " " << a_rew[i].gender << endl;



	cout << "Female info:" << endl;
	
	unknown_gender_is_know(a, a1_rew, a2_rew);
	for(int i = 0; i < N; i++) {
		cout << a2_rew[i].name_of_student << " " << a2_rew[i].faculty_num << " " << a2_rew[i].av_balls << " " << a2_rew[i].age << " " << a2_rew[i].gender << endl;

		++count;
		sum += a2_rew[i].age;

		cout << "avg age by Female(s) = " << sum/count << endl; 
	}
	sum = 0; count = 0;
	//for(int i = 0; i < N ; ++i)
	//	cout << a_rew[i].name_of_student << " " << a_rew[i].faculty_num << " " << a_rew[i].av_balls << " " << a_rew[i].age << " " << a_rew[i].gender << endl;

	f.close();
}

void f_youngest_and_sorting(data a[N], data a1_rew[N], data a2_rew[N], int &count, float &sum, int &temp/*, temp_male[N], temp_female[N]*/){

	for(int i = 0; i < N; ++i) {
		if (a[i].gender == "Male") {
				a1_rew[i].name_of_student = a[i].name_of_student;
				a1_rew[i].faculty_num = a[i].faculty_num;
				a1_rew[i].av_balls = a[i].av_balls;
				a1_rew[i].age = a[i].age;
				a1_rew[i].gender = a[i].gender;	
		}		
	}
	for(int i = 0; i < N; ++i) {
		if(a[i].gender == "Female") {
			a2_rew[i].name_of_student = a[i].name_of_student;
			a2_rew[i].faculty_num = a[i].faculty_num;
			a2_rew[i].av_balls = a[i].av_balls;
			a2_rew[i].age = a[i].age;
			a2_rew[i].gender = a[i].gender;
		}
	}
	for(int j = 0; j < N; j++) {
		for(int i = 0; i < N; i++) {
			if (a[i].age < a[i + 1].age){
				temp = a[i].age;
				a[i].age = a[i + 1].age;
				a[i + 1].age = temp; 
			}
		}
	}
	cout << "the youngest girl" << endl;
	//for(int i = 0; i < N; i++){
		cout << a[N-1].age << endl;
	//}


	/*cout << "female info:" << endl;
	for(int i = 0; i < N; ++i) {
		if(a[i].gender == "Female") {
			a2_rew[i].name_of_student = a[i].name_of_student;
			a2_rew[i].faculty_num = a[i].faculty_num;
			a2_rew[i].av_balls = a[i].av_balls;
			a2_rew[i].age = a[i].age;
			a2_rew[i].gender = a[i].gender;

			cout << a2_rew[i].name_of_student << " " << a2_rew[i].faculty_num << " " << a2_rew[i].av_balls << " " << a2_rew[i].age << " " << a2_rew[i].gender << endl;

			++count;
			sum += a2_rew[i].age;
			
		}
		
	}*/

}







int main(){
	//srand(time(NULL));
	data a[N]; int choose = 0; data a1_rew[N]; data a2_rew[N]; bool d = 1; int count = 0; float sum = 0; int temp;//data new_av_balls[N];
	//new array for data a_rew = a_rewrite//
	//скорее всего это нужно перезаписать так как мы будем делать бабл сортинг, ничего плохого в этом нет


	//pure_data(a); // тут как бы ты сам решаешь, чистить ли тебе дату после всех этих приколов или нет? как нибудь реши потом а пока по дефолту будет очищать
	//по итогу сделать тумблер который будет запоминатся программой, и если true, то создать файл с конфигом где пур дата = тру или пур дата = фалсе
	//если файла нет - создать, если есть, перезапись если человек сам захочет в интерфейсе этого сделать, сделать вкладки
	//settings(NAME, d);

	do{

		

		gui();
		cin >> choose;

		

		if (!int(choose))
			return 0; // for error write

		
		

		else{

			

			switch(choose) {	
			case 1:
				clear();
				input_data(a);
				pause_clear();

				continue;
			case 2:
				clear();
				output_data(a);
				clear_output(a);

				pause_clear();

				continue;
			case 3:
				clear();
				owerwriting_the_data_for_man_and_woman(a, a1_rew, a2_rew, count, sum);
				pause_clear();

				continue;
			case 4:
				clear();
				f_youngest_and_sorting(a, a1_rew, a2_rew, count, sum, temp);
				pause_clear();

				continue;
			
			//case 8:
			//	clear();
			//	settings(NAME, d);
			//	pause_clear();

			//	continue;
			case 9:
				clear();
				debug(a);
				clear_output(a);

				pause_clear();

				continue;
			case 0:
				clear();

				return 0;
			}			
		}
	}while(true);


	return 0;
}











//можно сделать нумерацию в input или вообще везде, чтоб удобнее было понимать под каким номером кто где что какой студент

// да и инпут можно было бы сделать красивее.. но это пипец как сложно и наверное не логично











/*
for(int i = 0; i < N; ++i) {
a[i] = rand();
f << a[i] << endl;
}

*/