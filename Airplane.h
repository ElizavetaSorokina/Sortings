#pragma once
using namespace std; //импорт пространства имен std
class Airplane { //создаем класс Airport
public:
	void Set(string,string,string,string); //объявляем прототип метода класса - сеттер
	Airplane() {}; //конструктор класса
	Airplane(Airplane&); //конструктор копирования
	~Airplane() {}; //деструктор класса
	friend bool operator>(const Airplane& a1, const Airplane& a2) { //дружественная функция - перегрузка оператора > для сравнения объектов класса
		if (a1.time > a2.time) { //в первую очередь сравниваем по полю "время прибытия"
			return true;
		}
		else if ((a1.time == a2.time) and (a1.name > a2.name)) { //далее сравниваем по "название авиакомпании"
			return true;
		}
		return false;
	}
	friend const bool operator<(const Airplane& a1, const Airplane& a2) { //дружественная функция - перегрузка оператора < для сравнения объектов класса
		if (a1.time < a2.time) { //в первую очередь сравниваем по полю "время прибытия"
			return true;
		}
		else if ((a1.time == a2.time) and (a1.name < a2.name)) { //далее сравниваем по "название авиакомпании"
			return true;
		}
		return false;
	}
private:
	string number_of_race; //поле класса, отвечающее за номер рейса
	string name; //поле класса, отвечающее за название авиакомпании
	string time; //поле класса, отвечающее за время прибытия
	string number_of_passengers; //поле класса, отвечающее за кол-во пассажиров
};

void Airplane::Set(string number_of_race,string name,string time,string number_of_passengers) { //сеттер, устанавливаем значения в поля класса для элемента массива объектов класса 
	this->number_of_race = number_of_race; //this - указатель на адрес объекта класса. Мы обращаемся внутри класса к членам нашего класса.
	this->name = name;
	this->time = time;
	this->number_of_passengers = number_of_passengers;
}

Airplane::Airplane(Airplane& a) { //конструктор копирования. Копируем содержимое полей объекта класса, переданного по ссылке, в поля другого элемента класса
	this->number_of_race = a.number_of_race;
	this->name = a.name;
	this->number_of_passengers = a.number_of_passengers;
	this->time = a.time;
}

