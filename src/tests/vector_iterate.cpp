#include <sr1/vector>
#include <sr1/zero_initialized>

struct Foo
{
  std::sr1::zero_initialized<int> a;
};

int main()
{
  std::sr1::vector<Foo> foos;

  for(std::sr1::vector<Foo>::iterator it = foos.begin();
    it != foos.end(); it++)
  {
    it->a++;
  }

  // TODO
  //while(foos.size() > 0)
  //{
  //  //foos.erase(foos.end());
  //  foos.erase(foos.begin());
  //}

  return 0;
}
