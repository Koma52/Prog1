#include "myTemplate2.h"

int main(){
   S<int> myInt {52};
   S<char> myChar {'k'};
   S<double> myDouble {52.666};
   S<std::string> myString {"cica"};
   S<std::vector<int>> myVectInt {std::vector<int> {1, 2, 3, 4, 5}};

   std::cout << "myInt: " << myInt.get() << std::endl;
   std::cout << "myChar: " << myChar.get() << std::endl;
   std::cout << "myDouble: " << myDouble.get() << std::endl;
   std::cout << "myString: " << myString.get() << std::endl;
   std::cout << "myVecInt: " << myVectInt.get() << std::endl;

    read_val(myInt);

    std::cout << myInt.get() << std::endl;

    return 0;
}