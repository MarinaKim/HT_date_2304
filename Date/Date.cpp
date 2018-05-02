#include"Date.h"
bool visokGod(int yy) {
	return (yy % 4 == 0 && yy % 100 != 0 && yy % 400 == 0);
}

bool Date::operator == (Date obj) {
	return ((this->dd = obj.dd) && (this->mm = obj.mm) && (this->yy = obj.yy));
}

istream& operator >> (istream & is, Date& d) {
	is >> d.dd >>d.mm >> d.yy;
	return is;
}

ostream& operator<<(ostream& os, Date& d) {
	os << d.dd << "\t" << d.mm <<"\t"<< d.yy << endl;
	return os;
}

Date Date:: operator+=(int count) {
	
	if (this->dd >= 1 && this->dd <= 31&&this->mm>=1&&this->mm<=12&&this->yy>=1900&&this->yy<=9999) {
		int maxDd;
		if (this->mm == 1 || this->mm == 3 || this->mm == 5 || this->mm == 7 || this->mm == 8 || this->mm == 10 || this->mm == 12) {
			maxDd = 31;
			this->dd += count;
			if (this->mm != 12) {
				do {
					if (this->dd > maxDd) {
						this->dd -= maxDd;
						this->mm++;
						if (this->mm > 12) {
							this->mm -= 12;
							this->yy++;
						}
					}
				} while (this->dd > maxDd);
			}
			else {
				do {
					if (this->dd > maxDd) {
						this->dd -= maxDd;
						this->mm++;
						if (this->mm > 12) {
							this->mm -= 12;
							this->yy++;
						}
					}
			} while (this->dd > maxDd);
			}
		}
		else if (this->mm == 4 || this->mm == 6 || this->mm == 9 || this->mm == 11) {
			maxDd = 30;
			this->dd += count;
			do {
				if (this->dd > maxDd) {
					this->dd -= maxDd;
					this->mm++;
				}
			} while (this->dd > maxDd);
		}
		else if (this->mm == 2) {
			if (visokGod(this->yy)) {
				maxDd = 29;
				this->dd += count;
				if (this->dd > maxDd) {
					this->dd -= maxDd;
					this->mm++;
				}
			}
			else {
				maxDd = 28;
				this->dd += count;
				if (this->dd > maxDd) {
					this->dd -= maxDd;
					this->mm++;
				}
			}
		}
	}
	else {
		cout << "Incorrect dste." << endl;
	}
	return *this;
}
//
//Date Date:: operator-=(int count) {
//}
//
//Date Date::operator+(Date obj) {
//
//}
//
//Date Date::operator-(Date obj) {
//
//}