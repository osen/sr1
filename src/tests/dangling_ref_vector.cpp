#include <sr1/vector>

struct Dummy
{
  int dummy;
};

std::sr1::vector<Dummy> ds;

void broken(Dummy& dr)
{
  ds.clear();
  dr.dummy = 9;
}

int main()
{
  ds.push_back(Dummy());

  broken(ds.at(0));

  return 0;
}
