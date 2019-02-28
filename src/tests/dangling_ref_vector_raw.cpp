#include <sr1/vector>

std::sr1::vector<int> nums;

void broken(int& a)
{
  nums.clear();
  a = 9;
}

int main()
{
  for(int i = 0; i < 100; i++)
  {
    nums.push_back(i);
  }

  broken(nums[10]);

  return 0;
}
