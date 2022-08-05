#include"CircularList.h"

int main() {
	CircularList l1;
	Employee e1(10, 300, "0", 25, 8, 2018, 5, 100);
	Employee e2(20, 400, "0", 25, 8, 2018, 4, 100);
	Employee e3(30, 500, "0", 25, 8, 2018, 3, 100);
	Employee e4(40, 600, "0", 25, 8, 2018, 2, 100);
	Employee e5(50, 700, "0", 25, 8, 2018, 1, 100);
	l1.Insert(e1);
	l1.Insert(e2);
	l1.Insert(e3);
	l1.Insert(e4);
	l1.Insert(e5);
	EmployeeID id(30, 500);
	l1.updateSalary(50000, id);
	l1.updateBonus(50000, id);
	l1.sort();
	l1.Display();
}