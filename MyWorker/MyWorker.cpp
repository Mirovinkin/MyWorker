// MyWorker.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

class Worker
{
private:
    string _name;
    string _surname;
    string _position;
    int _year;
    double _sallary;

public:
    Worker() {};
    Worker(const string& Name, const string& Surname, const int& Year, const double& Sallary, const string& Position) :
        _name(Name),
        _surname(Surname),
        _year(Year),
        _sallary(Sallary),
		_position(Position){};

    string GetName()
    {
        return _name != "" ? _name : throw exception("Empty value");
    }

    string GetSurname()
    {
        return _surname != "" ? _surname : throw exception("Empty value");
    }
    string GetPosition()
    {
        return _position != "" ? _position : throw exception("Empty value");
    }

    int GetYear()
    {
        return _year != NULL ? _year : throw exception("Empty value");
    }

    double GetSallary()
    {
        return _sallary != NULL ? _sallary : throw exception("Empty value");
    }

    void SetName(const string& Name)
    {
        _name = Name;
    }

    void SetSurname(const string& Surname)
    {
        _surname = Surname;
    }
    void SetPosition(const string& Position)
    {
        _name = Position;
    }

    void SetYear(const int& Year)
    {
        _year = Year;
    }

    void Sallary(const double& Sallary)
    {
        _sallary = Sallary;
    }

    void PrintWorkerData()
    {
        cout << "Имя: " << _name << "\n Фамилия: " << _surname <<
            "\nЗарплата: " << _sallary<<endl;
    }
};

class WorkerManager
{
private:
    vector<Worker> workers;

    public:
        void GetWorkerByExp(const int& Year )
        {
            time_t t;
            struct tm* ts;
            time(&t);
            ts = localtime(&t);
	        for(auto item : workers)
	        {
		     if(ts->tm_year - item.GetYear() > Year)
		     {
                 item.PrintWorkerData();
		     }
	        }
        }

		void GetWorkerBySallary(const double& Sallary)
        {
	        for(auto item : workers)
	        {
		        if(item.GetSallary()>Sallary)
		        {
                    item.PrintWorkerData();
		        }
	        }
        }

        void GetWorkerByPosition(const string& Position)
        {
            for (auto item : workers)
            {
                if (item.GetPosition() == Position)
                {
                    item.PrintWorkerData();
                }
            }
        }

};
int main()
{
    std::cout << "Hello World!\n";
}
