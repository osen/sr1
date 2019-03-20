#include <sr1/shared_ptr>
//#include <sr1/memory>
#include <sr1/vector>
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

void test(Dummy& d)
{
  d.dummy = 99;
}

int main()
{
  std::sr1::shared_ptr<Dummy> d = std::sr1::make_shared<Dummy>();
  d = d;
  std::sr1::shared_ptr<Dummy> d2 = d;
  std::sr1::shared_ptr<Dummy> d3(d2);
  d->dummy = 9;

  std::sr1::shared_ptr<Dummy> dn;
  d3 = dn;

  d2 = d;
  d = d2;
  d3 = d3;

  test(*d);

  std::cout << d->dummy << std::endl;

  std::sr1::vector<std::sr1::shared_ptr<Dummy> > ds;

  for(size_t i = 0; i < 100; i++)
  {
    ds.push_back(d);
  }

  std::sr1::shared_ptr<Object> o = d;
  o = d;

  return 0;
}
