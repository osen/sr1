#include <sr1/memory>

#include <string>

struct Employee : public std::sr1::enable_observer
{
  std::sr1::zero_initialized<int> id;
  std::string name;

  virtual void work()
  {
    std::cout << "Emp" << std::endl;
  }
};

struct Manager : public Employee
{
  std::sr1::zero_initialized<int> departmentId;

  virtual void work()
  {
    std::cout << "Manager" << std::endl;
  }
};

int main()
{
  std::sr1::shared_ptr<Manager> mgr = std::sr1::make_shared<Manager>();
  Manager* pm = mgr.get();
  std::sr1::shared_ptr<Employee> emp = mgr;
  Employee* pe = pm;

  std::sr1::observer_ptr<Manager> m1 = mgr;
  std::sr1::observer_ptr<Employee> m2 = mgr;
  std::sr1::observer_ptr<Employee> m3 = emp;

  std::sr1::weak_ptr<Employee> wemp = emp;
  std::sr1::weak_ptr<Manager> wmgr = mgr;

  std::sr1::observer_ptr<Manager> om = mgr.get();

  mgr->work();

  std::cout << pm << std::endl;
  std::cout << pe << std::endl;
  std::cout << mgr.get() << std::endl;
  std::cout << emp.get() << std::endl;
  om.reset(pm);
  std::cout << om.get() << std::endl;

  if(mgr.get() != mgr.get()) return 1;
  if(emp.get() != mgr.get()) return 1;
  if(m1.get() != mgr.get()) return 1;
  if(m2.get() != mgr.get()) return 1;
  if(m3.get() != mgr.get()) return 1;
  if(wemp.lock().get() != mgr.get()) return 1;
  if(wmgr.lock().get() != mgr.get()) return 1;
  if(om.get() != mgr.get()) return 1;

  return 0;
}
