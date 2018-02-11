#include <iostream>
#include <string>

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
    cout << "SalaryEmploye - name=" << getName()      << endl
	 << "  base salary   = " << getBaseSalary()   << endl      
	 << "  percentage    = " << work_fraction     << endl
      	 << "  actual salary = " << getActualSalary() << endl;
  }
};

//=====================================================================================================
/*
class HourlyEmployee : protected Employee
{
protected:
  
  long hourlyRate;
  
public:
  
  HourlyEmployee() {}
  
  HourlyEmployee(long long _hourlyRate) :hourlyRate(_hourlyRate) {}

  void SetValueRate(int _hourlyRate)
  {
    hourlyRate=hourlyRate;
  }
  
  void print()
  {
    cout << "HourlyEmployee - name=" << getName() << endl
	 <<  "  hourlyRate = " << hourlyRate << endl;
  }
};
*/

//=====================================================================================================
int main()
{
  SalaryEmployee *john = new SalaryEmployee("John", 200.0, 0.90);
  john->print();
  
  return 0;
}

