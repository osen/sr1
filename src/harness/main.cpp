#include <cstdlib>

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    return 1;
  }

  int rc = system(argv[1]);

  if(rc == 0)
  {
    return 1;
  }

  return 0;
}
