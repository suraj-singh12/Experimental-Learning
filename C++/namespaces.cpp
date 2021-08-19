#include <iostream>

// namespace is used to declare a scope

// using namespace std;

namespace Wolverine{
	int value = 500;
	int getval(){
		return value*20;
	}
}
int main()
{
	int value = 50;
	std::cout << "from std namespace value: " << value << std::endl;
	std::cout << "from Wolverine namespace value: " << Wolverine::value << std::endl;
	std::cout << "from Wolverine namespace getval(): " << Wolverine::getval() << std::endl;
	return 0;
}