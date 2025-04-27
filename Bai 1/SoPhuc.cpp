#include "SoPhuc.h"

SoPhuc::SoPhuc()
{
	ao = 0;
}
SoPhuc::SoPhuc(double thuc, double ao)
{
	this->thuc = thuc;
	this->ao = ao;
}
double SoPhuc::getThuc()
{
	return thuc;
}
double SoPhuc::getAo()
{
	return ao;
}
istream& operator>>(istream& is, SoPhuc& x)
{
	cout << "Nhap phan thuc: ";
	is >> x.thuc;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap phan thuc: ";
		is >> x.thuc;
	}
	cout << "Nhap phan ao: ";
	is >> x.ao;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap phan ao: ";
		is >> x.ao;
	}
	return is;
}
ostream& operator<<(ostream& os, SoPhuc x)
{
	if (x.thuc == 0)
	{
		cout << "";
		if (x.ao == 0)
		{
			cout << 0;
			return os;
		}
		cout << x.ao << "i";
		return os;
	}
	else
	{
		cout << x.thuc;
		if (x.ao < 0) cout << " - " << -x.ao << "i";
		else if (x.ao > 0) cout << " + " << x.ao << "i";
		else return os;
	}
	return os;
}
SoPhuc operator+(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = a.thuc + b.thuc;
	kq.ao = a.ao + b.ao;
	return kq;
}
SoPhuc operator+(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc + x;
	kq.ao = a.ao;
	return kq;
}
SoPhuc operator+(double x, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = x + b.thuc;
	kq.ao = b.ao;
	return kq;
}
SoPhuc operator-(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = a.thuc - b.thuc;
	kq.ao = a.ao - b.ao;
	return kq;
}
SoPhuc operator-(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc - x;
	kq.ao = a.ao;
	return kq;
}
SoPhuc operator-(double x, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = x + b.thuc;
	kq.ao = b.ao;
	return kq;
}
SoPhuc operator*(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = a.thuc * b.thuc;
	kq.ao = a.thuc * b.ao + a.ao * b.thuc;
	return kq;
}
SoPhuc operator*(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc * x;
	kq.ao = a.thuc + a.ao * x;
	return kq;
}
SoPhuc operator*(double x, SoPhuc a)
{
	SoPhuc kq;
	kq.thuc = a.thuc * x;
	kq.ao = a.thuc + a.ao * x;
	return kq;
}
SoPhuc operator/(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = (a.thuc * b.thuc) + (a.ao * b.ao) / (b.thuc * b.thuc) + (b.ao * b.ao);
	kq.ao = (a.ao * b.thuc) - (a.thuc * b.ao) / (b.thuc * b.thuc) + (b.ao * b.ao);
	return kq;
}
SoPhuc operator/(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc / x;
	kq.ao = a.ao / x;
	return kq;
}
SoPhuc operator/(double x, SoPhuc a)
{
	SoPhuc kq;
	kq.thuc = a.thuc / x;
	kq.ao = a.ao / x;
	return kq;
}
bool operator==(SoPhuc a, SoPhuc b)
{
	return ((a.thuc == b.thuc) && (a.ao == b.ao));
}
bool operator!=(SoPhuc a, SoPhuc b)
{
	return ((a.thuc != b.thuc) && (a.ao != b.ao));
}