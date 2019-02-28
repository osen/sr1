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
  ds.push_back(Dummy());
  ds.push_back(Dummy());
  ds.push_back(Dummy());
  ds.push_back(Dummy());

  for(std::sr1::vector<Dummy>::iterator it = ds.begin();
    it != ds.end(); it++)
  {
    it->broken();
  }

  return 0;
}
