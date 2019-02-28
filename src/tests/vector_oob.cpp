#include <sr1/vector>

int main()
{
  std::sr1::vector<int> nums;

  for(int i = 0; i < 100; i++)
  {
    nums.push_back(i);
  }

  int num = nums[100];

  return 0;
}
