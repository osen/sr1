#define STD_SR1_DEBUG

#include <sr1/vector>
#include <sr1/zero_initialized>
#include <sr1/noncopyable>
#include <sr1/memory>

#include <iostream>

using std::sr1::vector;

struct Test
{
  std::sr1::zero_initialized<int> age;
};

struct NoCopy : public std::sr1::noncopyable
{
  char *data;

  NoCopy()
  {
    data = (char *)malloc(100);
  }

  ~NoCopy()
  {
    free(data);
  }
};

struct SelfDestroy;
std::sr1::shared_ptr<SelfDestroy> sd;

struct SelfDestroy
{
  void wipe()
  {
    sd.reset();
  }
};

void TestSelfDestroy(SelfDestroy& s)
{
  sd.reset();
}

int main()
{
  std::cout << "Hello World" << std::endl;

  vector<Test> tests;
  NoCopy nc;
  //NoCopy nc2(nc);
  NoCopy nc3;
  //nc3 = nc;
  //nc3 = NoCopy(nc);
  //nc3 = NoCopy();

  sd = std::sr1::make_shared<SelfDestroy>();
  //(*sd).wipe(); // NYI
  //sd->wipe();
  //TestSelfDestroy(*sd);

  for(int i = 0; i < 10; i++)
  {
    tests.push_back(Test());
  }

  (*(tests.begin() + 8)).age = 9;
  //tests.end()->age = 9;

  for(vector<Test>::iterator it = tests.begin();
    it != tests.end(); it++)
  {
    //tests.clear();
    std::cout << it->age << std::endl;
  }

  return 0;
}

