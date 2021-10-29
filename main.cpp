#include <iostream> //���������� ���������� ��� �����-������
#include <string> //���������� ���������� ��� ������ � ������� string
#include <fstream> //���������� ���������� ��� ������/������ ������ ��/� ����
#include "Airplane.h" //���������� ������������ ���� Airplane.h, � ������� �������� �������� ������
#include <ctime> //���������� ���������� ��� ������ �� ��������

using namespace std; //������ ������������ ���� std
void ReadAirplane(string, Airplane*); //��������� �������� ������� ReadAirplane
void sortShaker(Airplane*,int, int);  //��������� �������� ������� sortShaker
void quickSort(Airplane*, int, int);  //��������� �������� ������� quickSort
void qSort(Airplane*, int, int);  //��������� �������� ������� qSort
const bool operator<(const Airplane&, const Airplane&);  //��������� �������� ���������� ��������� <
const bool operator<(const Airplane&, const Airplane&);  //��������� �������� ���������� ��������� >

int main() {
	const int n = 8000; //������������ ����� ������ ��� ����������
	Airplane a[n]; //��������� ������ �������� ������ Airplane 
	string path = "rybov_pokazyvaete.txt"; //� ���������� string ������ ����� ������
	ReadAirplane(path, a); //����� ������� ���������� ������ � �������� � ������ �������� ������
	int num,st,s;
	cout << "Enter number of lines: "; 
	cin >> num; //��������� ���-�� ����� ������,������� ����� �����������
	while (num > 8000 or num<=0) { // � ������ ��������� �����, ����� ��������� ���������� ��������� ������������ ����� �������, ������ ������ ������ �����
		cout << "Enter the number less than or equal to 8000 and more than 0"<<endl;
		cin >> num;
	}
	cout << "Start with: ";
	cin >> st; //��������� ����� ������, � ������� �������� �����������
	while (st > 8000 or st<0) { // � ������ ��������� �����, ����� ��������� ����� ��������� ������������ ����� �������, ������ ������ ������ �����
		cout << "Enter the number less than 8000 and more than or equal to 0" << endl;
		cin >> st;
	}
	while ((num + st) > 8000) { //� ������ ��������� �����, ����� ����� ����������� ��������� ������� �� ������� �������, ������ ������ ������ �����
		cout << "The number of lines to sort is more than 8000. Choose another starting position:" << endl;
		cin >> st;
	}
	double start1, start2, stop1, stop2, t1, t2;
	cout << "Sort(0 - Shaker sort, 1 - Quick sort): ";
	cin >> s;
	while (s != 0 and s != 1) {
		cout << "Enter 0 or 1"<<endl;
		cin >> s;
	}//�������� ����������
	switch (s) {  //�������� ������
	case 0: //���� ������� ������ ����������
		start1 = clock(); //��������� ����� ������ ����������
		sortShaker(a, st, num); //����� ������� ������ ���������� 
		stop1 = clock(); //��������� ����� ����� ����������
		t1 = (stop1-start1)/ (double)CLOCKS_PER_SEC; //������� ����� ����������,������� �� ������� ����� ����� ������ � ���������� �������� � ��������
		cout << "Time:" << t1;
		break;
	case 1:  //���� ������� ������� ����������
		start2 = clock(); //��������� ����� ������ ����������
		quickSort(a, num, st); //����� ������� ������� ����������
		stop2 = clock(); //��������� ����� ����� ����������
		t2 = (stop2 - start2) / (double)CLOCKS_PER_SEC; //������� ����� ����������,������� �� ������� ����� ����� ������ � ���������� �������� � ��������
		cout << "Time:" << t2;
	}
}

void ReadAirplane(string path, Airplane* a) { //������� ���������� ������ � �������� � ������ �������� ������
	ifstream fin; // ���������� ���� ifstream ��� ������ �� �����
	fin.open(path); //��������� ����
	if (!fin.is_open()) { 
		cout << "Error" << endl; //���� ���� �� ��� ������ ������� ������
	}
	else {
		int i = 0; //����������-������� ������ �������� �������
		string name1, name2, name3, name4;
		while (!fin.eof()) { //��������� ���� �� ����� �����
			getline(fin, name1, ' '); //��������� ������ ������ �� �������
			getline(fin, name2, ' '); //��������� ������ ������ �� �������
			getline(fin, name3, ' '); //��������� ������ ������ �� �������
			getline(fin, name4); //��������� ��������� ������ �� ����� ������
			a[i].Set(name1, name2, name3, name4); //� ������� ������ Set ������ Airplane ������������� �������� �������� ������ � i-� �������� � �������
			i++; //����������� �������
		}


	}
	fin.close(); //��������� ����

}



void sortShaker(Airplane* mass, const int st, const int count) { //���������� ������-����������, �������� ������ �������� ������ �� ���������, ��������� ����� ������, ���-�� ���������
	int left = st, right = count - 1 + st; // ����� � ������ ������� ����������� ������� �������
	int flag = 1; // ���� ������� �����������, ���� 1 - ���� �����������, 0 - �� ����
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)//��������� ����� �������
		{
			if (mass[i] > mass[i + 1])// ���� ��������� ������� ������ ��������, ������ �� �������
			{
				Airplane t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1; // ����������� � ���� ����� ����
			}
		}
		right--; // �������� ������ �������
		for (int i = right; i > left; i--) //��������� ������ ������
		{
			if (mass[i - 1] > mass[i])  // ���� ���������� ������� ������ ��������,������ �� �������
			{
				Airplane t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1; // ����������� � ���� ����� ����
			}
		}
		left++; // �������� ����� �������
	}

}


void qSort(Airplane* a, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last; //����� � ������ �������
		Airplane middle = a[(left + right) / 2]; //�������� � �������� ������� �������� ������� � �������� �������
		do
		{
			while (a[left] < middle) left++; //�������� ����� ������� ���� ������� left ������ �������
			while (a[right] > middle) right--; //�������� ������ ������� ���� ������� right ������ �������
			if (left <= right)
			{
				Airplane tmp = a[left];
				a[left] = a[right];
				a[right] = tmp; //���������� ������� left �� ����� right
				left++; //�������� ����� ������� ������
				right--; //�������� ������ ������� ������
			}
		} while (left <= right); //���� ������� �� ���������
		qSort(a, first, right); // ���������� �������� ���������� ��� ����� � ������ ����� �������
		qSort(a, left, last);
	}
}
void quickSort(Airplane* a, const int n, const int st) //���������� ������� ����������, �������� ������ �������� ������ �� ���������, ���-�� ���������, ��������� ����� ������
{
	qSort(a, st, n - 1 + st); //�������� ������� ���������� ������ ���
}