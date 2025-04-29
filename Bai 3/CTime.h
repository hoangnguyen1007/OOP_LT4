#pragma once
#include <iostream>
using namespace std;
class CTime
{
private:
	int iGio, iPhut, iGiay;
public:
	friend istream& operator >>(istream&, CTime&);
	friend ostream& operator<<(ostream&, CTime);
	CTime operator+(int);
	CTime operator-(int);
	CTime operator++();
	CTime operator++(int);
	CTime operator--();
	CTime operator--(int);
};

