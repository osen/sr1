#include <sr1/vector>

struct Dummy;

std::sr1::vector<Dummy> ds;

struct Dummy
{
  int dummy;

  void broken()
  {
    ds.clear();
    dummy = 9;
  }
};

int main()
{
  for(int i = 0; i < 100; i++)
  {
    ds.push_back(Dummy());
  }

  for(std::sr1::vector<Dummy>::iterator it = ds.begin();
    it != ds.end(); it++)
  {
    if(it == ds.begin() + 5)
    {
      ds.erase(it);
    }
  }

  return 0;
}
