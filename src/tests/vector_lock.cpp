#include <sr1/vector>

void sample(char& c, std::sr1::vector<char>& foos)
{
  c = 'h';
  foos = std::sr1::vector<char>();
  c = 'k';
}

int main()
{
  std::sr1::vector<char> foos;

  for(int i = 0; i < 100; i++)
  {
    foos.push_back('j');
  }

  sample(foos.at(20), foos);

  return 0;
}
