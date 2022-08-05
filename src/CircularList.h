#pragma once
#include "Employee.h"

struct Node {
public:
	Employee emp;
	Node* next;

	Node() :emp(), next(NULL) {
	}
};

class CircularList {
	Node* head, * cursor;
	int size;

public:
	CircularList() :head(NULL), cursor(NULL), size(0) {
	}

	int getSize()const {
		return size;
	}

	Node* getHead()const {
		return head;
	}

	void Insert(const Employee& emp) {
		Node* temp = new Node;
		temp->emp = emp;
		size++;

		if (head == NULL) {
			head = temp;
			cursor = temp;
			head->next = head;
		}

		else {
			cursor = head;
			while (cursor->next != head) {
				cursor = cursor->next;
			}

			cursor->next = temp;
			cursor = temp;
			cursor->next = head;
		}
	}

	void remove(EmployeeID id) {
		if (head != NULL) {
			Node* temp;
			if (head->emp.getEmpID().getBatch() == id.getBatch() && head->emp.getEmpID().getRollNo() == id.getRollNo()) {
				Node* temp1 = head;
				while (temp1->next != head) {
					temp1 = temp1->next;
				}
				temp = head;
				head = head->next;
				delete temp;
				cursor = head;
				size--;
				temp1->next = head;
			}

			else {
				temp = head;
				for (int i = 1; i < size; i++) {
					if (temp->next->emp.getEmpID().getBatch() == id.getBatch() && temp->next->emp.getEmpID().getRollNo() == id.getRollNo()) {
						Node* temp1 = temp->next;
						cursor = temp;
						temp->next = temp->next->next;
						delete temp1;
						size--;
						break;
					}
					temp = temp->next;
				}
			}
		}
	}

	void updateSalary(const int& salary, EmployeeID id) {
		if (head != NULL) {
			if (head->emp.getEmpID().getBatch() == id.getBatch() && head->emp.getEmpID().getRollNo() == id.getRollNo()) {
				head->emp.setSalary(salary);
			}

			else {
				Node* temp = head;
				for (int i = 0; i < size; i++) {
					if (temp->emp.getEmpID().getBatch() == id.getBatch() && temp->emp.getEmpID().getRollNo() == id.getRollNo()) {
						temp->emp.setSalary(salary);
					}
					temp = temp->next;
				}
			}
		}
	}

	void updateBonus(const int& bonus, EmployeeID id) {
		if (head != NULL) {
			if (head->emp.getEmpID().getBatch() == id.getBatch() && head->emp.getEmpID().getRollNo() == id.getRollNo()) {
				head->emp.setBonus(bonus);
			}

			else {
				Node* temp = head;
				for (int i = 0; i < size; i++) {
					if (temp->emp.getEmpID().getBatch() == id.getBatch() && temp->emp.getEmpID().getRollNo() == id.getRollNo()) {
						temp->emp.setBonus(bonus);
					}
					temp = temp->next;
				}
			}
		}
	}

	void clear() {
		Node* temp = head;

		for (int i = 0; i < size; i++) {
			Node* temp1 = temp;
			temp = temp->next;
			delete temp1;
		}
		head = NULL;
		size = 0;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}

	void Display() {
		Node* temp = head;

		if (temp != NULL) {
			while (temp->next != head) {
				temp->emp.Display();
				temp = temp->next;
			}
			temp->emp.Display();
		}
	}

	void sort() {
		Node* temp, * temp1, * prev;

		temp1 = head;
		temp = head;
		prev = head;

		for (int i = 1; i < size; i++) {
			temp = temp->next;
		}
		temp->next = NULL;
		temp = head;

		for (int i = 1; i < size; i++) {
			temp = head;
			prev = head;
			for (int j = 1; j < size; j++) {
				if (temp == head) {
					if (temp->emp.getSalary() > temp->next->emp.getSalary()) {
						head = temp->next;
						temp1 = head->next;
						head->next = prev;
						prev->next = temp1;
						prev = head;
						temp = head;
					}
					temp = temp->next;
				}

				else if (temp != head) {
					if (temp->next != NULL) {
						if (temp->emp.getSalary() > temp->next->emp.getSalary()) {
							temp1 = temp->next;
							temp->next = temp->next->next;
							temp1->next = temp;
							prev->next = temp1;
							prev = temp1;
						}

						else {
							temp = temp->next;
							prev = prev->next;
						}
					}
				}
			}
		}

		temp = head;
		for (int i = 1; i < size; i++) {
			temp = temp->next;
		}
		temp->next = head;
	}
};