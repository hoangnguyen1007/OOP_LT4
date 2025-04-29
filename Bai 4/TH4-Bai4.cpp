#include "CDate.h"

int main()
{
	CDate x, y;
	cin >> x;
	cout << "Ngay thang nam sau khi nhap: " << x << endl;
	cout << "Ngay thang nam sau khi cong 1 ngay: " << ++x << endl;
	cout << "Ngay thang nam sau khi tru 1 ngay: " << --(--x) << endl;
	cout << "Nhap so ngay de cong/tru: " ;
	int k;
	cin >> k;
	cout << "Ngay thang nam sau khi cong " << k << " ngay: " << x + k<<endl;
	cout << "Ngay thang nam sau khi tru " << k << " ngay: " << x - k - k<<endl;
	cout << "Nhap ngay thang nam de tinh khoang cach giua 2 date: "<<endl;
	cin >> y;
	cout << "Khoang cach giua 2 ngay thang nam la: " << x - y << " ngay";
}