#include <iostream>
#include <vector>
#include <memory> // For smart pointers
using namespace std;

// Base class
class Employee {
protected:
    int emp_id;
    string name;

public:
    Employee(int id, const string& emp_name) : emp_id(id), name(emp_name) {}

    virtual void displayDetails() const {
        cout << "ID: " << emp_id << ", Name: " << name << endl;
    }

    // Virtual method for salary calculation
    virtual double calculateSalary() const = 0;

    virtual ~Employee() {}
};

// Derived class: Manager
class Manager : public Employee {
private:
    double base_salary;
    double bonus;

public:
    Manager(int id, const string& emp_name, double salary, double bonus_amount)
        : Employee(id, emp_name), base_salary(salary), bonus(bonus_amount) {}

    double calculateSalary() const override {
        return base_salary + bonus;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Role: Manager, Salary: $" << calculateSalary() << endl;
    }
};

// Derived class: Worker
class Worker : public Employee {
private:
    int hours_worked;
    double hourly_rate;

public:
    Worker(int id, const string& emp_name, int hours, double rate)
        : Employee(id, emp_name), hours_worked(hours), hourly_rate(rate) {}

    double calculateSalary() const override {
        return hours_worked * hourly_rate;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Role: Worker, Salary: $" << calculateSalary() << endl;
    }
};

// Main function
int main() {
    vector<shared_ptr<Employee>> employees;

    // Add employees
    employees.push_back(make_shared<Manager>(1, "Alice", 5000.0, 1000.0));
    employees.push_back(make_shared<Worker>(2, "Bob", 160, 20.0));
    employees.push_back(make_shared<Worker>(3, "Charlie", 120, 18.5));

    cout << "Employee Details:\n";
    for (const auto& emp : employees) {
        emp->displayDetails();
        cout << "-------------------------\n";
    }
return 0;
}
