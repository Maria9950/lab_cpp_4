#include "cpp1.h"
using namespace std;


double Diskriminant(double a, double b, double c) {
	return (b * b - 4 * a * c);
}

void prov(double a, double b, double c, int& flag) {

	if (a == 0 && b == 0 && c == 0) {
		cout << "x - любое число" << endl;
		flag += 1;
	}

	if (a == 0 && c == 0 && b!=0)  {
		cout << "x = 0" << endl;
		flag += 1;
	}
	if (a == 0 && b == 0 && c!=0) {
		cout << "Ошибка ввода, уравнения не существует" << endl;
		flag += 1;
	}
	if (b == 0 && c == 0 && a!=0)  {
		cout << "x = 0" << endl;
		flag += 1;
	}
	if (a == 0 && b != 0 && c != 0)  {
		cout << "x = " << -c/b << endl;
		flag += 1;
	}
	if (b == 0 && c !=0 && a!=0) {
		cout << "x1 = " << -sqrt(fabs(c/a)) << endl;
		cout << "x2 = " << sqrt(fabs(c/a)) << endl;
		flag += 1;
	}
	if (c == 0 && b!=0 &&a!=0) {
		cout << "x1 = 0" << endl;
		cout << "x2 = " << -b/a << endl;
		flag += 1;
	}


}

void dis0(double& x, double dis, double a, double b, double c) {
	x = -b / (2 * a);
	cout << "x = " << x << endl;
}

void dis_ok(double& x1, double& x2, double dis, double a, double b, double c) {
	x1 = (-b + sqrt(dis)) / (2 * a);
	cout << "x1 = " << x1 << endl;
	x2 = (-b - sqrt(dis)) / (2 * a);
	cout << "x2 = " << x2 << endl;
}

void Result(double a, double b, double c) {
	int flag = 0;

	prov(a, b, c, flag);

	if (flag != 0) return;

	double dis = Diskriminant(a, b, c);

	if (dis == 0) {
		double x;
		dis0(x, dis, a, b, c);

	}

	if (dis < 0) {
		cout << "нет решений" << endl;
	}

	if (dis > 0) {
		double x1, x2;
		dis_ok(x1, x2, dis, a, b, c);
	}
}
