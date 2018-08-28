#include <sr1/vector>
#include <sr1/zero_initialized>

#include <iostream>

struct Test
{
  std::sr1::zero_initialized<int> age;
};

int main()
{
  std::cout << "Hello World" << std::endl;

  std::sr1::vector<Test> tests;

  for(int i = 0; i < 10; i++)
  {
    tests.push_back(Test());
  }

  (*(tests.begin() + 8)).age = 9;
  //tests.end()->age = 9;

  for(std::sr1::vector<Test>::iterator it = tests.begin();
    it != tests.end(); it++)
  {
    std::cout << it->age << std::endl;
  }

  return 0;
}
