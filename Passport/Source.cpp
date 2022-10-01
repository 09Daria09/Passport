#include<iostream>
#include <locale>
#include "windows.h"
using namespace std;

class Passport
{
protected:
	string name;
	string surname;
	string patronymic;
	bool sex;
	string Date_of_birth;
	string Nationality;
	unsigned int DocumentNo;
	string Place_of_birth;
public:
	Passport();
	Passport(string name, string surname, string patronymic, bool sex, string Date_of_birth,
		string Nationality, unsigned int DocumentNo, string Place_of_birth);
	void Input();
	void Print();
};

Passport::Passport()
{
	name = "Olga";
	surname = "Ivanova";
	patronymic = "Sergeevna";
	sex = 1;
	Date_of_birth = "13.09.2000";
	Nationality = "UKR";
	DocumentNo = 002434653;
	Place_of_birth = "Nikolaev";
}

Passport::Passport(string name, string surname, string patronymic, bool sex, string Date_of_birth, 
	string Nationality, unsigned int DocumentNo, string Place_of_birth)
{
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->sex = sex;
	this->Date_of_birth = Date_of_birth;
	this->Nationality = Nationality;
	this->DocumentNo = DocumentNo;
	this->Place_of_birth = Place_of_birth;
}

void Passport::Input()
{
	cout << "Enter your name -> ";
	cin >> name;
	cout << "Enter your last name -> ";
	cin >> surname;
	cout << "Enter your middle name -> ";
	cin >> patronymic;
	cout << "Enter your gender (1-F, 0-M) -> ";
	cin >> sex;
	cout << "Enter your date of birth -> ";
	cin >> Date_of_birth;
	cout << "Enter your nationality -> ";
	cin >> Nationality;
	cout << "Enter document number (9 characters) -> ";
	cin >> DocumentNo;
	cout << "Enter place of birth -> ";
	cin >> Place_of_birth;
}

void Passport::Print()
{
	cout << "Ім'я/ Name: " << name << endl;
	cout << "Прізвище/ Surname: " << surname << endl;
	cout << "По батькові/ Patronymic: " << patronymic << endl;
	if (sex)
	{
		cout << "Стать/ Sex: F" << endl;
	}
	else
	{
		cout << "Стать/ Sex: M" << endl;
	}
	cout << "Дата народження/  Date of birth: " << Date_of_birth << endl;
	cout << "Громодянство/ Nationality:" << Nationality << endl;
	cout << "Документ №/ Document No.: " << DocumentNo << endl;
	cout << "Місце народження/ Place of birth: " << Place_of_birth << endl;
}
class ForeignPassport : public Passport
{
	string Number_ForeignP;
	string country;
	string date_arrival;
	string date_departure;
public:
	ForeignPassport() :Passport()
	{
		Number_ForeignP = "FT094678";
		country = "Poland";
		date_arrival = "12.03.2021";
		date_departure = "14.07.2021";
	}
	ForeignPassport(string Number_ForeinP, string country, string date_arrival, string date_departure, string name, string surname, string patronymic, bool sex, string Date_of_birth,
		string Nationality, unsigned int DocumentNo, string Place_of_birth)
		:Passport(name, surname, patronymic, sex, Date_of_birth, Nationality, DocumentNo, Place_of_birth)
	{
		this->name = name;
		this->surname = surname;
		this->patronymic = patronymic;
		this->sex = sex;
		this->Date_of_birth = Date_of_birth;
		this->Nationality = Nationality;
		this->DocumentNo = DocumentNo;
		this->Place_of_birth = Place_of_birth;
		this->Number_ForeignP = Number_ForeignP;
		this->country = country;
		this->date_arrival = date_arrival;
		this->date_departure = date_departure;
	}
	void Print_Foreign();
	void Input_Foreign();
};

void ForeignPassport::Print_Foreign()
{
	Print();
	cout << "Foreign passport number: " << Number_ForeignP << endl;
	cout << "Country of entry: " << country << endl;
	cout << "Arrival date: " << date_arrival << endl;
	cout << "Date of departure: " << date_departure << endl;
}

void ForeignPassport::Input_Foreign()
{
	int count_country;
	Input();
	cout << "Enter your foreign passport number -> ";
	cin >> Number_ForeignP;
	cout << "Enter how many countries you have visited -> ";
	cin >> count_country;
	for (int i = 1; i <= count_country; i++)
	{
		cout << "Enter country name -> ";
		cin >> country;
		cout << "Enter date of entry -> ";
		cin >> date_arrival;
		cout << "Enter departure date -> ";
		cin >> date_departure;
	}
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Sex : 1-Female  0-Male" << endl;
	Passport per;
	per.Print();
	per.Input();
	per.Print();
	cout << "********************************************" << endl;
	ForeignPassport prs;
	prs.Print_Foreign();
	prs.Input_Foreign();
	prs.Print_Foreign();
}