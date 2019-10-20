#include <sr1/memory>

#include <iostream>

struct Foo : public std::sr1::enable_observer
{
  std::sr1::zero_initialized<int> a;

  void someFunc()
  {
    a = 9;

    std::cout << "Func ran! " << a << std::endl;
  }

};

std::sr1::shared_ptr<Foo> foo;

int main()
{
  foo = std::sr1::make_shared<Foo>();
  std::sr1::observer_ptr<Foo> f = foo;

  std::cout << "f should not be NULL" << std::endl;
  f->someFunc();

  foo = std::sr1::shared_ptr<Foo>();

  std::cout << "f should be NULL" << std::endl;
  f->someFunc();

  return 0;
}
