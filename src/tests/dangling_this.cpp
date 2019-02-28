#include <sr1/memory>

struct Dummy;

std::sr1::shared_ptr<Dummy> d;

struct Dummy
{
  int dummy;

  void broken()
  {
    d.reset();
    dummy = 9;
  }
};

int main()
{
  d = std::sr1::make_shared<Dummy>();

  d->broken();

  return 0;
}
