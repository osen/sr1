#include <sr1/memory>

struct Dummy
{
  int dummy;
};

std::sr1::shared_ptr<Dummy> d;

void somefunc(Dummy& unused)
{
  std::sr1::shared_ptr<Dummy> dc(d);
}

int main()
{
  d = std::sr1::make_shared<Dummy>();

  somefunc(*d);

  return 0;
}
