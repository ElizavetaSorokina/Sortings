#include <iostream> //подключаем библиотеку для ввода-вывода
#include <string> //подключаем библиотеку для работа с классом string
#include <fstream> //подключаем библиотеку для чтения/записи данных из/в файл
#include "Airplane.h" //подключаем заголовочный файл Airplane.h, в котором хранится описание класса
#include <ctime> //подключаем библиотеку для работы со временем

using namespace std; //импорт пространства имен std
void ReadAirplane(string, Airplane*); //объявляем прототип функции ReadAirplane
void sortShaker(Airplane*,int, int);  //объявляем прототип функции sortShaker
void quickSort(Airplane*, int, int);  //объявляем прототип функции quickSort
void qSort(Airplane*, int, int);  //объявляем прототип функции qSort
const bool operator<(const Airplane&, const Airplane&);  //объявляем прототип перегрузки оператора <
const bool operator<(const Airplane&, const Airplane&);  //объявляем прототип перегрузки оператора >

int main() {
	const int n = 8000; //максимальный объем данных для сортировки
	Airplane a[n]; //объявляем массив объектов класса Airplane 
	string path = "rybov_pokazyvaete.txt"; //в переменной string храним адрес данных
	ReadAirplane(path, a); //вызов функции считывания данных и передачи в массив объектов класса
	int num,st,s;
	cout << "Enter number of lines: "; 
	cin >> num; //считываем кол-во строк данных,которые будем сортировать
	while (num > 8000 or num<=0) { // в случае неверного ввода, когда введенное количество превышает максимальную длину массива, просим ввести другое число
		cout << "Enter the number less than or equal to 8000 and more than 0"<<endl;
		cin >> num;
	}
	cout << "Start with: ";
	cin >> st; //считываем номер строки, с которой начинаем сортировать
	while (st > 8000 or st<0) { // в случае неверного ввода, когда введенное число превышает максимальную длину массива, просим ввести другое число
		cout << "Enter the number less than 8000 and more than or equal to 0" << endl;
		cin >> st;
	}
	while ((num + st) > 8000) { //в случае неверного ввода, когда число сортируемых элементов выходит за границы массива, просим ввести другое число
		cout << "The number of lines to sort is more than 8000. Choose another starting position:" << endl;
		cin >> st;
	}
	double start1, start2, stop1, stop2, t1, t2;
	cout << "Sort(0 - Shaker sort, 1 - Quick sort): ";
	cin >> s;
	while (s != 0 and s != 1) {
		cout << "Enter 0 or 1"<<endl;
		cin >> s;
	}//выбираем сортировку
	switch (s) {  //оператор выбора
	case 0: //если выбрана шейкер сортировка
		start1 = clock(); //фиксируем время начала сортировки
		sortShaker(a, st, num); //вызов функции шейкер сортировки 
		stop1 = clock(); //фиксируем время конца сортировки
		t1 = (stop1-start1)/ (double)CLOCKS_PER_SEC; //считаем время сортировки,вычитая из времени конца время начала и возвращаем значение в секундах
		cout << "Time:" << t1;
		break;
	case 1:  //если выбрана быстрая сортировка
		start2 = clock(); //фиксируем время начала сортировки
		quickSort(a, num, st); //вызов функции бытсрой сортировки
		stop2 = clock(); //фиксируем время конца сортировки
		t2 = (stop2 - start2) / (double)CLOCKS_PER_SEC; //считаем время сортировки,вычитая из времени конца время начала и возвращаем значение в секундах
		cout << "Time:" << t2;
	}
}

void ReadAirplane(string path, Airplane* a) { //функция считывания данных и передачи в массив объектов класса
	ifstream fin; // переменная типа ifstream для чтения из файла
	fin.open(path); //открываем файл
	if (!fin.is_open()) { 
		cout << "Error" << endl; //если файл не был открыт выводим ошибку
	}
	else {
		int i = 0; //переменная-счетчик номера элемента массива
		string name1, name2, name3, name4;
		while (!fin.eof()) { //считываем пока не конец файла
			getline(fin, name1, ' '); //считываем первую строку до пробела
			getline(fin, name2, ' '); //считываем вторую строку до пробела
			getline(fin, name3, ' '); //считываем третью строку до пробела
			getline(fin, name4); //считываем четвертую строку до конца строки
			a[i].Set(name1, name2, name3, name4); //с помощью метода Set класса Airplane устанавливаем значения объектам класса с i-м индексом в массиве
			i++; //увеличиваем счетчик
		}


	}
	fin.close(); //закрываем файл

}



void sortShaker(Airplane* mass, const int st, const int count) { //реализация Шейкер-сортировки, передаем массив объектов класса по указателю, стартовый номер строки, кол-во элементов
	int left = st, right = count - 1 + st; // левая и правая границы сортируемой области массива
	int flag = 1; // флаг наличия перемещений, если 1 - были перемещения, 0 - не было
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)//двигаемся слева направо
		{
			if (mass[i] > mass[i + 1])// если следующий элемент меньше текущего, меняем их местами
			{
				Airplane t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1; // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу
		for (int i = right; i > left; i--) //двигаемся справа налево
		{
			if (mass[i - 1] > mass[i])  // если предыдущий элемент больше текущего,меняем их местами
			{
				Airplane t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1; // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу
	}

}


void qSort(Airplane* a, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last; //левая и правая границы
		Airplane middle = a[(left + right) / 2]; //выбираем в качестве осевого элемента элемент в середине массива
		do
		{
			while (a[left] < middle) left++; //сдвигаем левую границу пока элемент left меньше осевого
			while (a[right] > middle) right--; //сдвигаем правую границу пока элемент right больше осевого
			if (left <= right)
			{
				Airplane tmp = a[left];
				a[left] = a[right];
				a[right] = tmp; //перемещаем элемент left на место right
				left++; //сдвигаем левую границу вправо
				right--; //сдвигаем правую границу вправо
			}
		} while (left <= right); //пока границы не сомкнутся
		qSort(a, first, right); // Рекурсивно вызываем сортировку для левой и правой части массива
		qSort(a, left, last);
	}
}
void quickSort(Airplane* a, const int n, const int st) //реализация быстрой сортировки, передаем массив объектов класса по указателю, кол-во элементов, стартовый номер строки
{
	qSort(a, st, n - 1 + st); //вызываем функцию сортировки первый раз
}