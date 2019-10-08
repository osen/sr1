#include <sr1/memory>

struct Foo;

std::sr1::shared_ptr<Foo> foo;

struct Foo : public std::sr1::enable_observer
{
  std::sr1::zero_initialized<int> a;

  void someFunc()
  {
    a = 9;
    foo = std::sr1::shared_ptr<Foo>();
    a = 8;
  }

};

int main()
{
  foo = std::sr1::make_shared<Foo>();
  std::sr1::observer_ptr<Foo> f = foo;

  f->someFunc();

  return 0;
}
