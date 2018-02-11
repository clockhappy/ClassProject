#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//
// Check out:
//      -- what lambda functions mean
//      -- what operator functions means
//      -- what return by reference means
//

using namespace std;

//=====================================================================================================
class Employee
{
  //
  // Base class for storing basic employe information
  //
  
private:
  
  std::string name;
  double      base_salary;
  
public:
  
  Employee() {}  
  Employee(const std::string _name, double _base_salary) :name(_name), base_salary(_base_salary) {}
  
  virtual ~Employee() {}
  
  const std::string& getName      () const { return name;         }
  double             getBaseSalary() const { return base_salary; }
  
  virtual double getActualSalary() const = 0;
  
  virtual void print() const = 0;
};

//=====================================================================================================
struct SortByName
{
  bool operator()(const Employee *lhs, const Employee *rhs)
  {
    return lhs->getName() < rhs->getName();
  }
};

//=====================================================================================================
struct SortBySalary
{
  bool operator()(const Employee *lhs, const Employee *rhs)
  {
    return lhs->getActualSalary() > rhs->getActualSalary();
  }
};

//=====================================================================================================
class SalaryEmployee: public Employee
{
  //
  // Salaried employee has a contract with company and can work part time or over time
  //
private:
  
  double work_fraction;
  
public:
  
  SalaryEmployee() {}
  SalaryEmployee(const std::string _name,
		 double _base_salary,
		 double _work_fraction):
    Employee     (_name, _base_salary),
    work_fraction(_work_fraction)
  {
  }
  
  virtual ~SalaryEmployee() {}
  
  virtual double getActualSalary() const
  {
    return getBaseSalary()*work_fraction;
  }
  
  
  void print() const
  {
    cout << "SalaryEmployee - " << getName()     << endl
	 << "  base salary   = " << getBaseSalary()   << endl      
	 << "  percentage    = " << work_fraction     << endl
      	 << "  actual salary = " << getActualSalary() << endl;
  }
};

//=====================================================================================================
class HourlyEmployee : public Employee
{
  //
  // Employee who is paid by the hour
  //
protected:
  
  double hourly_rate;
  double hours_worked;
  
public:
  
  HourlyEmployee() {}
  
  HourlyEmployee(const std::string &name, double _rate, double _hours) :
    Employee    (name, 0.0),
    hourly_rate (_rate),
    hours_worked(_hours)
  {
  }


  virtual double getActualSalary() const
  {
    return hourly_rate*hours_worked;
  }
  
  
  void print() const
  {
    cout << "HourlyEmployee - " << getName()     << endl
	 << "  base salary   = " << getBaseSalary()   << endl      
	 << "  hourly_rate   = " << hourly_rate       << endl
      	 << "  hours_worked  = " << hours_worked      << endl
      	 << "  actual salary = " << getActualSalary() << endl;
  }  
};

//=====================================================================================================
int main()
{
  Employee *anna = new SalaryEmployee("Anna", 500.0, 1.20);
  
  Employee *john = new SalaryEmployee("John", 200.0, 0.90);

  Employee *jim  = new HourlyEmployee("Jim",  30.0,  4.50);

  std::vector<Employee *> employees;

  employees.push_back(john);
  employees.push_back(jim);
  employees.push_back(anna);

  cout << "-----------------------------------------------------------------" << endl
       << "Print all initial employees" << endl;
  
  for(const Employee *employee: employees) {
    employee->print();
  }
  
  
  //
  // Sort by name
  //
  std::sort(employees.begin(), employees.end(), SortByName());

  cout << "-----------------------------------------------------------------" << endl
       << "Print employees sorted by name:" << endl;
  
  for(const Employee *employee: employees) {
    employee->print();
  }

  //
  // Sort by salary
  //
  std::sort(employees.begin(), employees.end(), SortBySalary());

  cout << "-----------------------------------------------------------------" << endl
       << "Print employees sorted by salary:" << endl;
  
  for(const Employee *employee: employees) {
    employee->print();
  }
  
  return 0;
}

