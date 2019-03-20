#include <sr1/memory>
#include <sr1/zero_initialized>
#include <iostream>

struct Object
{
  Object()
  {
    std::cout << "Object()" << std::endl;
  }

  ~Object()
  {
    std::cout << "~Object()" << std::endl;
  }
};

struct Dummy : public Object
{
  Dummy()
  {
    std::cout << "Dummy()" << std::endl;
  }

  ~Dummy()
  {
    std::cout << "~Dummy()" << std::endl;
  }

  std::sr1::zero_initialized<int> dummy;
};

int main()
{
  std::sr1::shared_ptr<Dummy> s = std::sr1::make_shared<Dummy>();

  std::sr1::weak_ptr<Dummy> w = s;

  std::cout << w.use_count() << std::endl;

  std::sr1::weak_ptr<Object> wo = s;

  std::cout << wo.use_count() << std::endl;

  wo = w;

  std::cout << wo.use_count() << std::endl;

  std::sr1::shared_ptr<Dummy> s2 = s;

  std::cout << wo.use_count() << std::endl;

  s = std::sr1::shared_ptr<Dummy>();

  std::cout << wo.use_count() << std::endl;

  s2 = std::sr1::shared_ptr<Dummy>();

  std::cout << wo.use_count() << std::endl;

  return 0;
}
