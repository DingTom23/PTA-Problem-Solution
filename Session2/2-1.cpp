#include <iostream>
#include <string>
using namespace std;

template<typename T>
T MAX_VALUE(T a, T b, T c)
{
  T max;
  if(a>b){
    max=a;
  }else{
    max=b;
  }
  
  if(c>max){
    max=c;
  }
  return max;
}

int main()
{

  int v1=MAX_VALUE(1,2,3);
  cout<<v1<<endl;
  double v2=MAX_VALUE(3.14, 20.1,11.9);
  cout<<v2<<endl;
  long v3=MAX_VALUE(100L,200L,300L);
  cout<<v3<<endl;
  return 0;

}

