#include <sr1/vector>

std::sr1::vector<char> data;

void broken(char& c)
{
  c = 'k';
  data.push_back(c);
}

int main()
{
  data.push_back('K');
  data.push_back('a');
  data.push_back('r');
  data.push_back('s');
  data.push_back('t');
  data.push_back('e');
  data.push_back('n');

  broken(data.at(3));

  return 0;
}
