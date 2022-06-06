#include "encoder.hpp"
#include "global.hpp"

#define TESTING_OFF 0

#if TESTING_OFF
void write_data(unsigned char *data, unsigned int size)
{
  mtx.lock();
  GlobalData.data = data;
  GlobalData.size = size;
  mtx.unlock();
}
#endif

void encode_data(unsigned int timestamp, std::vector<int> &data) {
  #if TESTING_OFF
  // Encode the data 
  // Then write to the global data
  // Use a mutex

  //convert vector of ints into bytes
  //basically encode into unsigned char*

  //GlobalData.size = static_cast<int>(data.size());
  int size = data.size();    
  unsigned char encData[size];
  int num = 0;
  std::string str = "";

  printf("\n\n");
  for(int i = 0; i < size; i++)
  {
    std::cout << (data[i] * (i+1)) << std::endl;
    num += data[i] * (i+1);
  }
  printf("\n\n");

  printf("Number is: %d\nStr is: %s\n\n", num, str.c_str());
  std::cout << "string is : " << str << std::endl;
#if 1
  printf("==In %s==\n", __FILE__);
  for(const auto & x : data)
  {
    printf("%d", x);
  }
  printf("\n");
#endif
  //write_data(_,_);
  #endif
}