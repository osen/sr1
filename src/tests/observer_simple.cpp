#include <sr1/memory>

struct Bar : public std::sr1::enable_observer
{
  int a;
};

int main()
{
  Bar b = {};
  std::sr1::observer_ptr<Bar> pb = &b;

  pb->a = 9;

  return 0;
}
