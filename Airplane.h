#pragma once
using namespace std; //������ ������������ ���� std
class Airplane { //������� ����� Airport
public:
	void Set(string,string,string,string); //��������� �������� ������ ������ - ������
	Airplane() {}; //����������� ������
	Airplane(Airplane&); //����������� �����������
	~Airplane() {}; //���������� ������
	friend bool operator>(const Airplane& a1, const Airplane& a2) { //������������� ������� - ���������� ��������� > ��� ��������� �������� ������
		if (a1.time > a2.time) { //� ������ ������� ���������� �� ���� "����� ��������"
			return true;
		}
		else if ((a1.time == a2.time) and (a1.name > a2.name)) { //����� ���������� �� "�������� ������������"
			return true;
		}
		return false;
	}
	friend const bool operator<(const Airplane& a1, const Airplane& a2) { //������������� ������� - ���������� ��������� < ��� ��������� �������� ������
		if (a1.time < a2.time) { //� ������ ������� ���������� �� ���� "����� ��������"
			return true;
		}
		else if ((a1.time == a2.time) and (a1.name < a2.name)) { //����� ���������� �� "�������� ������������"
			return true;
		}
		return false;
	}
private:
	string number_of_race; //���� ������, ���������� �� ����� �����
	string name; //���� ������, ���������� �� �������� ������������
	string time; //���� ������, ���������� �� ����� ��������
	string number_of_passengers; //���� ������, ���������� �� ���-�� ����������
};

void Airplane::Set(string number_of_race,string name,string time,string number_of_passengers) { //������, ������������� �������� � ���� ������ ��� �������� ������� �������� ������ 
	this->number_of_race = number_of_race; //this - ��������� �� ����� ������� ������. �� ���������� ������ ������ � ������ ������ ������.
	this->name = name;
	this->time = time;
	this->number_of_passengers = number_of_passengers;
}

Airplane::Airplane(Airplane& a) { //����������� �����������. �������� ���������� ����� ������� ������, ����������� �� ������, � ���� ������� �������� ������
	this->number_of_race = a.number_of_race;
	this->name = a.name;
	this->number_of_passengers = a.number_of_passengers;
	this->time = a.time;
}

