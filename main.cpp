#include <iostream>
#include <string>

using namespace std;

//=====================================================================================================
class Employee
{
private:
  std::string name;

protected:
  
  int         salary;
  
public:
  
  Employee() {}  
  Employee(const std::string _name, int _salary) :name(_name), salary(_salary) {}
  virtual ~Employee() {}

  const std::string getName () const { return name; }
  
  virtual double getActualSalary() const = 0;
  
  virtual void print() const = 0;
};

//=====================================================================================================
class SalaryEmployee: public Employee
{
private:
  int percentage;
  
public:
  
  SalaryEmployee() {}
  SalaryEmployee(int _percentage):percentage(_percentage) {}
  
  virtual ~SalaryEmployee() {}
  
  virtual double getActualSalary() const
  {
    return percentage*salary/100.0;
  }
  
  
  void print()
  {
    cout << "SalaryEmploye - name=" << getName()      << endl
	 << "  base salary   = " << salary            << endl      
	 << "  percentage    = " << percentage        << endl
      	 << "  actual salary = " << getActualSalary() << endl;
  }
};

//=====================================================================================================
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


//=====================================================================================================
int main()
{
  //Employee name(101, 3000);
  //name.print();
  
  
  SalaryEmployee amount(2500);
  amount.print();
  
  HourlyEmployee sun(8);
  sun.print();
  
  return 0;
}

