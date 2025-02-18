#include "cpp1.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Result(0, 7, 0);
	Result(0, 0, 0);
	Result(4, 0, 0);
	Result(0, 0, -9);
	Result(3, 3, 0);
	Result(1, 0, -1);
	Result(0, 6, 6);
	Result(3, 5, -3);
	Result(-1, 2, -10);
	Result(4, -12, 9);
	return 0;
}