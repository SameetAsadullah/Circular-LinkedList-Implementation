#pragma once
#include<iostream>
#include<string>
using namespace std;

struct EmployeeID {
private:
	int batch, rollNo;

public:
	EmployeeID() : batch(0), rollNo(0) {
	}

	EmployeeID(int b, int rN) : batch(b), rollNo(rN) {
	}

	void setBatch(const int& b) {
		if (b > 0) {
			batch = b;
		}
	}

	void setRollNo(const int& rN) {
		if (rN > 0) {
			rollNo = rN;
		}
	}

	int getBatch() const {
		return batch;
	}

	int getRollNo() const {
		return rollNo;
	}
};

struct Date {
private:
	int day, month, year;

public:
	Date() : day(0), month(0), year(0) {
	}

	Date(int d, int m, int y) : day(d), month(m), year(y) {
	}

	void setDate(const int& d) {
		if (d > 0 && d <= 31) {
			day = d;
		}
	}

	void setMonth(const int& m) {
		if (m > 0 && m <= 12) {
			month = m;
		}
	}

	void setYear(const int& y) {
		if (y > 0) {
			year = y;
		}
	}

	int getDay() const {
		return day;
	}

	int getMonth() const {
		return month;
	}

	int getYear() const {
		return year;
	}
};

class Employee {
	EmployeeID EmpID;
	string NIC;
	Date JoiningDate;
	int Salary, Bonus;

public:
	Employee() : EmpID(), NIC(""), JoiningDate(), Salary(0), Bonus(0) {
	}

	Employee(int b, int rN, string nic, int d, int m, int y, int s, int bonus) : EmpID(b, rN), NIC(nic), JoiningDate(d, m, y), Salary(s), Bonus(bonus) {
	}

	void setEmployeeID(int b, int rN) {
		if (b > 0 && rN > 0) {
			EmpID.setBatch(b);
			EmpID.setRollNo(rN);
		}
	}

	void setNIC(string nic) {
		if (nic != "") {
			NIC = nic;
		}
	}

	void setDate(int d, int m, int y) {
		if (d > 0 && d <= 31 && m > 0 && m <= 12 && y > 0) {
			JoiningDate.setDate(d);
			JoiningDate.setMonth(m);
			JoiningDate.setYear(y);
		}
	}

	void setSalary(int s) {
		if (s > 0) {
			Salary = s;
		}
	}

	void setBonus(int b) {
		if (b > 0) {
			Bonus = b;
		}
	}

	EmployeeID getEmpID() const {
		return EmpID;
	}

	string getNIC() const {
		return NIC;
	}

	Date getDate() const {
		return JoiningDate;
	}

	int getSalary() const {
		return Salary;
	}

	int getBonus() const {
		return Bonus;
	}

	void Display() {
		cout << "Batch no: " << EmpID.getBatch() << endl;
		cout << "Roll no: " << EmpID.getRollNo() << endl;
		cout << "NIC: " << NIC << endl;
		cout << "Joining Date: " << JoiningDate.getDay() << "/" << JoiningDate.getMonth() << "/" << JoiningDate.getYear() << endl;
		cout << "Salary: " << Salary << endl;
		cout << "Bonus: " << Bonus << endl << endl;
	}
};
