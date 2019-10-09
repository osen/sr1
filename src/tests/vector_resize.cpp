#include <sr1/vector>
#include <sr1/zero_initialized>

struct Foo
{
  std::sr1::zero_initialized<int> dummy;
};

void clone(Foo& foo, std::sr1::vector<Foo>& foos)
{
  foos.push_back(foo);
  foo.dummy = 9;
}

int main()
{
  std::sr1::vector<Foo> foos;

  for(int i = 0; i < 100; i++)
  {
    foos.push_back(Foo());
  }

  clone(foos.at(20), foos);

  return 0;
}
