#include "CDate.h"
bool nam_nhuan(int nam)
{
	return(nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
int so_ngay_trong_thang(int thang, int nam)
{
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (nam_nhuan(nam)) return 29;
		else return 28;
	}
}
bool CDate::ktra_hop_le()
{
	return ngay > 0 && thang > 0 && nam > 0 && thang <= 12 && ngay <= so_ngay_trong_thang(thang, nam);
}
CDate::CDate()
{
	ngay = ltm->tm_mday;
	thang = ltm->tm_mon + 1;
	nam = ltm->tm_year + 1990;
}
CDate::CDate(int ngay) : ngay(ngay)
{
	thang = ltm->tm_mon + 1;
	nam = ltm->tm_year + 1990;
	if (!ktra_hop_le()) ngay = ltm->tm_mday;
}
CDate::CDate(int ngay, int thang) : ngay(ngay), thang(thang)
{
	nam = ltm->tm_year + 1990;
	if (!ktra_hop_le())
	{
		ngay = ltm->tm_mday;
		thang = ltm->tm_mon;
	}
}
CDate::CDate(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam)
{
	if (!ktra_hop_le())
	{
		ngay = ltm->tm_mday;
		thang = ltm->tm_mon;
		nam = ltm->tm_year;
	}
}
istream& operator>>(istream& is, CDate& x)
{
	do
	{
		cout << "Nhap ngay thang nam: ";
		is >> x.ngay >> x.thang >> x.nam;
	} while (!x.ktra_hop_le());
	return is;
}
ostream& operator<<(ostream& os, CDate x)
{
	if (x.ngay < 10) cout << 0;
	cout << x.ngay<<"/";
	if (x.thang < 10) cout << 0;
	cout << x.thang << "/";
	cout << x.nam;
	return os;
}
CDate CDate::operator+(int x)
{
	ngay += x;
	while (ngay > so_ngay_trong_thang(thang, nam))
	{
		ngay -= so_ngay_trong_thang(thang, nam);
		thang++;
		if (thang > 12)
		{
			thang = 1;
			nam++;
		}
	}
	return CDate(ngay, thang, nam);
}
CDate CDate::operator-(int x)
{
	ngay -= x;
	while (ngay <= 0)
	{
		thang--;
		if (thang <= 0)
		{
			thang = 12;
			nam--;
		}
		ngay = so_ngay_trong_thang(thang, nam) - abs(ngay);
	}
	return CDate(ngay, thang, nam);
}
int CDate::so_ngay_toi_ht()
{
	int res = 0;
	for (int i = 1; i < thang; i++)
	{
		res += so_ngay_trong_thang(i, nam);
	}
	res += ngay;
	return res;
}
int CDate::operator-(CDate x)
{
	int res = 0;
	CDate earlier = *this, later = x;
	if (this->nam > x.nam || (this->nam == x.nam && this->thang > x.thang) ||
		(this->nam == x.nam && this->thang == x.thang && this->ngay > x.ngay))
	{
		earlier = x;
		later = *this;
	}
	for (int i = earlier.nam; i < later.nam; i++)
	{
		if (nam_nhuan(i)) res += 366;
		else res += 365;
	}
	res += later.so_ngay_toi_ht() - earlier.so_ngay_toi_ht();
	return res;
}
CDate CDate::operator++()
{
	ngay++;
	if (ngay > so_ngay_trong_thang(thang, nam))
	{
		ngay = 1;
		thang++;
		if (thang > 12)
		{
			nam++;
			thang = 1;
		}
	}
	return *this;
}
CDate CDate::operator++(int)
{
	CDate tmp = *this;
	++*this;
	return tmp;
}
CDate CDate::operator--()
{
	ngay--;
	if (ngay < 1)
	{
		ngay = so_ngay_trong_thang(thang, nam);
		thang--;
		if (thang < 1)
		{
			nam--;
			thang = 12;
		}
	}
	return *this;
}
CDate CDate::operator--(int)
{
	CDate tmp = *this;
	--*this;
	return tmp;
}