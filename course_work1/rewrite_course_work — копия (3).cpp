#include <iostream>
#include <string>
//#include <iomanip>
#include <fstream>
#include <ctime>			// подключем библиотеки

using namespace std; 

const int N = 5;			// делаем постоянную переменную N под числом 5, это нужно чтобы прописать постоянное место для массива,
							// и изменить его в данном случае - невозможно
string NAME = "example.txt";// так же задаём переменную NAME для работы с файлами, 

fstream f;					// здесь идёт сокращение fstream, теперь fstream равен f, для дальнейшего обозначения в программе функций 
							// f.open(); или f.close(); и тд.

struct data{
	string name_of_student;
	int faculty_num;
	double av_balls;
	int age;
	string gender;			// курсовая работа требует: создать информацию об имени студентов, факультета, среднего балла, возраста, пола
							// я создал структуру, потому что с ней работать очень удобно чем постоянно очень мно создавать переменных в main
							// создаётся структура данных для того чтобы было легче обозначать массивы, например a[i].name_of_student
							// благодаря этому мы может легко и просто восоздать данные для курсовой работы
};

void gui(){
	cout << "MENU" << endl << endl;
	cout << "1. input data" << endl;
	cout << "2. output data" << endl;
	cout << "3. overwriting the data for man and woman" << endl;
	cout << "4. female youngest and sorting" << endl;
	cout /*<< "5. "*/ << endl;
	cout /*<< "6. "*/ << endl;
	cout /*<< "7. "*/ << endl;
	cout /*<< "8. settings"*/ << endl;
	cout << "9. debug(random data)" << endl;
	cout << "0. exit" << endl;  // функция интерфейса для постоянного написания меню, некая графика работы моей программы которая
								// вдальнейшем будет использоватся постоянно, и постоянно будет переписываться с каждым действием пользователя
								// так же это намного удобнее чем без интерфейса, всёдоступно и понятно на графическом уровне
								// здесь мы можем: 1 . ввести с клавиатуры данные, вас спросят N-ое количество раз ввести имя студента,
								// N-ое количество раз ввести факультет студента, N-ое количество раз ввести средний балл студента, 
								// N-ое количество раз ввести возраст студента, выбрать N-ое количество раз пол, мужчина это или женщина
								// для пола будет предоставленна два варианта, или m или f, m = male f = female. Ниже будет ещё объяснение
}

void output(data a[N]){
	f.open(NAME, ios::in);
	for(int i = 0; i < N ; ++i) {
		f >> a[i].name_of_student;
		f >> a[i].faculty_num;
		f >> a[i].av_balls;
		f >> a[i].age;
		f >> a[i].gender;
		cout << a[i].name_of_student << " " << a[i].faculty_num << " " << a[i].av_balls << " " << a[i].age << " " << a[i].gender << " " << endl; // выводит имеющуюся информацию о студентах на экран: 5 имен студентов 5 факультет номеров, 
										// 5 средних баллов, 5 возрастов, 5 полов нужно чтобы после выполнения задачи, отображалась 
										// информация о студентах на экран
	}
	f.close();
}

void pause_clear(){
	system("pause");
	system("cls");	// обозначать паузу и очистку, посчитал нужным добавить для облегчения работы
}

void clear(){
	system("cls");	// обозначать очистку
}

void clear_output(data a[N]){
	clear();
	output(a);		// так же обозначает очистку и вывод на экран информацию о студентах, можно даже удалить если сбивает с толку при программировании
}

void debug(data a[N]){									// дебаг, помогает разработчику быстро в один клик заполнить информацию об студентах, очень удобно если не хотите вписывать информацию
														// с клавиатуры
	f.open(NAME, ios::out);				
	string temp_names[100] = {"Aaron", "Abraham", "Adam", "Adrian", "Aidan", "Alan", "Albert", "Alejandro", "Alex", "Alexander", "Alfred", "Andrew", "Angel", "Anthony", "Antonio", "Ashton", "Austin", "Aaliyah", "Abigail", "Ada", "Adelina", "Agatha", "Alexa", "Alexandra", "Alexis", "Alise", "Allison", "Alyssa", "Amanda", "Amber", "Amelia", "Angelina", "Anita", "Ann", "Ariana", "Arianna", "Ashley", "Audrey", "Autumn", "Ava", "Avery", "Benjamin", "Bernard", "Blake", "Brandon", "Brian", "Bruce", "Bryan", "Bailey", "Barbara", "Beatrice", "Belinda", "Brianna", "Bridjet", "Brooke", "Cameron", "Carl", "Carlos", "Charles", "Christopher", "Cole", "Connor", "Caleb", "Carter", "Chase", "Christian", "Clifford", "Cody", "Colin", "Curtis", "Cyrus", "Caroline", "Catherine", "Cecilia", "Celia", "Chloe", "Christine", "Claire", "Daniel", "David", "Dennis", "Devin", "Diego", "Dominic", "Donald", "Douglas", "Dylan", "Daisy", "Danielle", "Deborah", "Delia", "Destiny", "Diana", "Dorothy", "Edward", "Elijah", "Eric", "Ethan", "Evan", "Eleanor"};
														// данная строчка кода позволяет забить в массив 100 разных имён, которые позже будут в рандомном порядке заполнять информацию о студентах,
														// другими словами у вас случайным образом в информацию заполняется случайное имя 
	for(int i = 0; i < N; ++i) {

		a[i].name_of_student = temp_names[rand()/501];	// положим N-ое количество случайных имен от 0-99(по индексу массива) вообще тут может выйди 100 разных имён
														// теперь запишим в N-ое количество раз клеток информации разными именами
		if(rand()/25000 == 1)						
			a[i].gender = "Male";
		else
			a[i].gender = "Female";						// рандомно выберает от 0-1, если 1 то мальчик если 0 то девочка

		a[i].age = (rand()/1500)+18;					// от 18 лет + 0-33 рандомное число, точнее на выходе должно быть от 18-48 лет, под требованию университет например да
		a[i].av_balls = ((rand()/1000)+50);				// рандомно средний балл от 50 и до 100
		a[i].faculty_num = 23221000 + rand()/50;		// рандомно факультет от 23221000 до 23222000
		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl;				// закидываем данные в example.txt
														// рандомные числа закинуты в example.txt
	}

	f.close(); 

}

//void pure_data(data a[N]){
//	f.open(NAME, ios::app);
//	for(int i = 0; i < N; ++i) {
//		a[i].name_of_student = "Empty";
//		a[i].age = 0;
//		a[i].faculty_num = 0;
//		a[i].av_balls = 0;
//		a[i].gender = "Female";
//
//		f << a[i].name_of_student << " ";
//		f << a[i].faculty_num << " ";
//		f << a[i].av_balls << " ";
//		f << a[i].age << " ";
//		f << a[i].gender << " " << endl;
//	}
//	f.close();
//}

void input_data(data a[N]){	// функция/блок кода для ввода с клавиатуры данные 

	char b; 
	f.open(NAME, ios::out); // открываем example.txt на чтен........ чтобы в дальнейшем не только отображать имеющуюся информацию, но и
	//for(int i = 0; i < N; ++i) {				// ???
	//	cin >> a[i].name_of_student;
	//	cin >> a[i].faculty_num;
	//	cin >> a[i].av_balls;
	//	cin >> a[i].age;
	//	cin >> a[i].gender;
	//	f << a[i].name_of_student << " ";
	//	f << a[i].faculty_num << " ";
	//	f << a[i].av_balls << " ";
	//	f << a[i].age << " ";
	//	f << a[i].gender << " " << endl;
	//}
	for(int i = 0; i < N; ++i) {
		clear_output(a);	// очистка и отображение информации о студентах

		cout << "please, write name of student here:" << endl;	
		cin >> a[i].name_of_student;						// 5 раз записываем имя студента
/*		f << a[i].name_of_student << " " << endl;	*/				// после записывания с клавиатуры, оно так же записывает в файл
															// no need error post code here because string can works with any char
	}
	for(int i = 0; i < N; ++i) {
		clear_output(a);									// очистка и отображение информации о студентах

		cout << "please, write faculty number here:" << endl;	
		cin >> a[i].faculty_num;							// записываем 5 раз факультетный номер студента

		if(!int(a[i].faculty_num)){								
			cout << "Error: write only numbers" << endl;
			pause_clear();
			exit(1);
		}													// проверка на ошибку, факультет НЕ равен числу
															// выход с кодовым числом процессора 1, то есть выход с ошибкой
		else if(a[i].faculty_num == 0){
			cout << "Error: dont write 0" << endl;
			pause_clear();
			exit(1);
		}													// так же если вы вдруг напишите 0, вы вылетете с программы

		//f << a[i].faculty_num << " ";
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
			exit(1);					// так же само как я уже и писал, проверка является ли числом или дробным числом
										// если же нет - ошибка, если цифра 0 - ошибка
		}
		//f << a[i].av_balls << " ";
		
	}						


	for(int i = 0; i < N; ++i) {
		clear_output(a);
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
		}					// так же само и про возраст, если это не число - ошибка, если цифра 0 - ошибка
		//f << a[i].age << " ";
		
	}				


	for(int i = 0; i < N; ++i) {
		clear_output(a);
		cout << "please, write gender M or F, M - Male, F - Female, here:" << endl;
		cin >> b;

		if(b == 'M' || b == 'm' || b == 'F' || b == 'f'){	// если ты выбрал M или m или F или f
															// срабатывает алгоритм
			if(b == 'M' || b == 'm') {						// если M или m то пол = мужчине
				a[i].gender = "Male";
				//f << a[i].gender << " " << endl;
			}
			else if(b == 'F' || b == 'f'){					// если F или f то пол = женщине
				a[i].gender = "Female";
				//f << a[i].gender << " " << endl;
			}
		}
		else {
			cout << "Error: You are not choose M or F" << endl;	// если не M не m не F не f
			pause_clear();
			exit(1);
		}					// ошибка, вылетаешь
	}
	
	clear_output(a);

	for(int i = 0; i < N; ++i) {				// ???
		//cin >> a[i].name_of_student;
		//cin >> a[i].faculty_num;
		//cin >> a[i].av_balls;
		//cin >> a[i].age;
		//cin >> a[i].gender;
		f << a[i].name_of_student << " ";
		f << a[i].faculty_num << " ";
		f << a[i].av_balls << " ";
		f << a[i].age << " ";
		f << a[i].gender << " " << endl;
	}

	f.close();
}

void owerwriting_the_data_for_man_and_woman(data a[N], data a1_rew[N], data a2_rew[N], int &count, float &sum){
	f.open(NAME, ios::out | ios::in | ios::app);

	cout << "Male info: " << endl;
	for(int i = 0; i < N; ++i) {
		if (a[i].gender == "Male") {
				a1_rew[i].name_of_student = a[i].name_of_student;
				a1_rew[i].faculty_num = a[i].faculty_num;
				a1_rew[i].av_balls = a[i].av_balls;
				a1_rew[i].age = a[i].age;
				a1_rew[i].gender = a[i].gender;

				cout << a1_rew[i].name_of_student << " " << a1_rew[i].faculty_num << " " << a1_rew[i].av_balls << " " << a1_rew[i].age << " " << a1_rew[i].gender << endl;
				++count;
				sum += a1_rew[i].age;
		}
	}	
	cout << "avg age by Male(s) = " << sum/count << endl;
	sum = 0; count = 0;

	cout << "Female info:" << endl;
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
	}
	cout << "avg age by Female(s) = " << sum/count << endl; 
	sum = 0; count = 0;

	f.close();
}

void f_youngest_and_sorting(data a[N], data a1_rew[N], data a2_rew[N], int &count, float &sum, int &temp/*, temp_male[N], temp_female[N]*/){
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
			if (a2_rew[i].age < a2_rew[i + 1].age){
				temp = a2_rew[i].age;
				a2_rew[i].age = a2_rew[i + 1].age;
				a2_rew[i + 1].age = temp;
				count++;
			}
		}
	}
	cout << "the youngest girl" << endl;
	cout << a2_rew[count-1].age << endl;

	for(int j = 0; j < N; j++) {
		for(int i = 0; i < N; i++) {
			if (a[i].age < a[i + 1].age){
				temp = a[i].age;
				a[i].age = a[i + 1].age;
				a[i + 1].age = temp; 
			}
		}
	}
	cout << "sorting" << endl;
	for(int i = 0; i < N; i++)
		cout << a[i+1].age << endl;

	count = 0;
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
				output(a);
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
				clear();		// очистка главного меню
				debug(a);		// вызываем функцию debug, делает рандомную информацию об студентах, и записывает её в файл
				output(a);		// отображения информации о студентов на экран

				pause_clear();	// пауза, после уже очистка консоли

				continue;		// после выполнения кейса, цикл продолжается
			case 0:
				clear();	// очищает всё что было написано до этого

				return 0;	// выход из программы с кодовым числом 0 для процессора, то есть успешно вышел из программы без ошибок
			}			
		}
	}while(true); // бесконечный цикл, пока пользователь сам не выйдет из программы
}











//можно сделать нумерацию в input или вообще везде, чтоб удобнее было понимать под каким номером кто где что какой студент

// да и инпут можно было бы сделать красивее.. но это пипец как сложно и наверное не логично











/*
for(int i = 0; i < N; ++i) {
a[i] = rand();
f << a[i] << endl;
}

*/

//void pure_data(data a[N]){
//	f.open(NAME);
//	for(int i = 0; i < N; ++i) {
//		a[i].name_of_student = "Pure";
//		a[i].age = 0;
//		a[i].faculty_num = 0;
//		a[i].av_balls = 0;
//		a[i].gender = "Female";
//
//		f << a[i].name_of_student << " ";
//		f << a[i].faculty_num << " ";
//		f << a[i].av_balls << " ";
//		f << a[i].age << " ";
//		f << a[i].gender << " " << endl;
//	}
//	f.close();
//} // нужно чтобы отображать... а вообще нафиг оно надо? можно и удалить эти данные