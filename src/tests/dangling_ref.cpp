#include <sr1/memory>

struct Dummy
{
  int dummy;
};

std::sr1::shared_ptr<Dummy> d;

void broken(Dummy& dr)
{
  d.reset();
  dr.dummy = 9;
}

int main()
{
  d = std::sr1::make_shared<Dummy>();

  broken(*d);

  return 0;
}
