/*класс Date (дата)
	Проверка на равенство двух дат(операция = =)
	Изменение даты на указанное число дней (операции +=, -=)
	Сложение и вычитание двух дат (операции +, -)
*/

#pragma once
#include<iostream>
using namespace std;
class Date {
private:
	int dd;
	int mm;
	int yy;

public:
	Date() = default;
	Date(int dd, int mm, int yy) /*: dd(dd), mm(mm), yy(yy) */ {
		if (dd > 0 && dd < 31)
			this->dd = dd;
		if (mm > 0 && mm <= 12)
			this->mm = mm;
		if (yy > 0 && yy < 9999)
			this->yy = yy;
	};

	int getDd() { return dd; }
	int getMm() { return mm; }
	int getYy() { return yy; }

	bool operator == (Date obj);

	Date operator+=(int count);
	/*Date operator-=(int count);

	Date operator+(Date obj);
	Date operator-(Date obj);*/

	friend istream& operator >> (istream & is, Date& d);
	friend ostream& operator<<(ostream& os, Date& d);
};