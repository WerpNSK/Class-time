#include <iostream>
using namespace std;

class timeT {
private:
	int h;
	int m;
	int s;
public:
	timeT(int hh = 0, int mm = 0, int ss = 0) {
		setH(hh);
		setM(mm);
		setS(ss);
	}
	~timeT() {

	}
	void printTime() {
		if (h < 10)
			cout << 0;
		cout << h << ":";
		if (m < 10)
			cout << 0;
		cout << m << ":";
		if (s < 10)
			cout << 0;
		cout << s << endl;
	}
	void setH(int x) {
		if (x > 23 || x < 0)
			x = 0;
		h = x;
	}
	void setM(int x) {
		if (x > 59 || x < 0)
			x = 0;
		m = x;
	}
	void setS(int x) {
		if (x > 59 || x < 0)
			x = 0;
		s = x;
	}
	void input() {
		cout << "\nH: ";
		int hh;
		cin >> hh;
		setH(hh);
		cout << "M: ";
		int mm;
		cin >> mm;
		setM(mm);
		cout << "S: ";
		int ss;
		cin >> ss;
		setS(ss);
	}

	void plusSec(int sec) {

		plusMin((sec + s) / 60);
		s = (sec + s) % 60;
	}

	void plusMin(int min) {

		plusHr((m + min) / 60);
		m = (m + min) % 60;
	}

	void plusHr(int hr) {
		h = (h + hr) % 24;
	}
	int getH() { return this->h; }
	int getM() { return this->m; }
	int getS() { return this->s; }

	//_____________________________________________________________________________
	void operator+=(timeT t) {
		plusHr(t.h);
		plusMin(t.m);
		plusSec(t.s);
	}

	timeT operator+=(const timeT& t) {
		setH(this->h + t.h);
		setM(this->m + t.m);
		setS(this->s + t.s);
		return *this;
	}

	timeT operator-=(const timeT& t) {
		if (this->h - t.h < 0)
			this->h = 24 - (this->h - t.h);
		else
		{
			this->h = this->h - t.h;
		}
		if (this->m - t.m < 0)
		{
			this->m = 60 - (this->m - t.m);
			this->h = this->h - 1;
		}
		else
		{
			this->m = this->m - t.m;
		}
		if (this->s - t.s < 0)
		{
			this->s = 60 - (this->s - t.s);
			this->m = this->m - 1;
			if (this->m < 0)
			{
				this->m = 60 - this->m;
				this->h = this->h - 1;
			}
		}
		else
		{
			this->s = this->s - t.s;
		}
		return *this;
	}

	timeT operator+ (const timeT& t) {
		int tH, tM, tS;
		setH(this->h + t.h);
		tH = getH();
		setM(this->m + t.m);
		tM = getM();
		setS(this->s + t.s);
		tS = getS();
		return tH, tM, tS;
	}

	timeT operator- (const timeT& t) {
		int tH, tM, tS;
		tH = this->h - t.h;
		if (tH < 0)
			tH = 24 - tH;
		tM = this->m - t.m;
		if (tM < 0)
			tM = 60 - tM;
		tS = this->s - t.s;
		if (tS < 60)
			tS = 60 - tS;
	}

	int getTimeT() const {
		return this->h * 3600 + this->m * 60 + this->s;
	}
};

bool operator>(const timeT& a, const timeT& b) {
	return a.getTimeT() > b.getTimeT();
}
bool operator<(const timeT& a, const timeT& b) {
	return a.getTimeT() < b.getTimeT();
}
bool operator==(const timeT& a, const timeT& b) {
	return a.getTimeT() == b.getTimeT();
}
bool operator>=(const timeT& a, const timeT& b) {
	return a.getTimeT() >= b.getTimeT();
}
bool operator<=(const timeT& a, const timeT& b) {
	return a.getTimeT() <= b.getTimeT();
}
bool operator!=(const timeT& a, const timeT& b) {
	return a.getTimeT() != b.getTimeT();
}


timeT t;
timeT t2;
void main() {
	//temp
	
}