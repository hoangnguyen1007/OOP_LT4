#include "CMatrix.h"
CMatrix::CMatrix() {}
CMatrix::CMatrix(const vector<vector<double>> x)
{
	dong = x.size();
	cot = (dong > 0) ? x[0].size() : 0;

	a.resize(dong, vector<double>(cot)); 

	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			a[i][j] = x[i][j];
		}
	}
}
int CMatrix::getDong()
{
	return dong;
}
int CMatrix::getCot()
{
	return cot;
}
istream& operator >>(istream& is, CMatrix& x)
{
	cout << "Nhap kich thuoc cua ma tran: ";
	cin >> x.dong >> x.cot;
	while (x.dong < 0 || x.cot < 0 || cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap kich thuoc cua ma tran: ";
		cin >> x.dong >> x.cot;
	}
	x.a.resize(x.dong, vector<double>(x.cot));
	for (int i = 0; i < x.dong; i++)
	{
		for (int j = 0; j < x.cot; j++)
		{
			cout << "a[" << i << "]" << "[" << j << "] = ";
			cin >> x.a[i][j];
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Vui long nhap lai!" << endl;
				cout << "a[" << i << "]" << "[" << j << "] = ";
				cin >> x.a[i][j];
			}
		}
	}
	return is;
}
ostream& operator <<(ostream& os, CMatrix x)
{
	for (int i = 0; i < x.dong; i++)
	{
		for (int j = 0; j < x.cot; j++)
		{
			os << x.a[i][j];
			if (j < x.cot - 1) os << " ";
		}
		os << endl;
	}
	return os;
}
CMatrix CMatrix::operator+(CMatrix x)
{
	CMatrix kq;
	kq.dong = dong;
	kq.cot = cot;
	kq.a.resize(dong, vector<double>(cot));
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			kq.a[i][j] = this->a[i][j] + x.a[i][j];
		}
	}
	return kq;
}
CMatrix CMatrix::operator-(CMatrix x)
{
	CMatrix kq;
	kq.dong = dong;
	kq.cot = cot;
	kq.a.resize(dong, vector<double>(cot));
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			kq.a[i][j] = this->a[i][j] - x.a[i][j];
		}
	}
	return kq;
}
CMatrix CMatrix::operator*(CMatrix x)
{
	vector<vector<double>> result(dong, vector<double>(x.cot, 0.0));
	for (int i = 0; i < dong; ++i)
	{
		for (int j = 0; j < x.cot; ++j)
		{
			for (int k = 0; k < cot; ++k)
			{
				result[i][j] += a[i][k] * x.a[k][j];
			}
		}
	}
	return CMatrix(result);
}
CMatrix CMatrix::operator*(double x)
{
	CMatrix kq;
	kq.a.resize(dong, vector<double>(cot));
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			kq.a[i][j] = this->a[i][j] * x;
		}
	}
	return kq;
}
CMatrix CMatrix::operator*(CVector x)
{
	CMatrix kq;
	kq.dong = dong;
	kq.cot = 1;
	kq.a.resize(dong, vector<double>(1, 0.0));
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			kq.a[i][0] += a[i][j] * x[j];
		}
	}

	return kq;
}