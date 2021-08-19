#include <iostream>
using namespace std;

/*
KNOW: 0xFF 			: 2^8-1   all 1s => 255		; 8 bit unsigned int_max
	  0xFFFF 		: 2^16-1  all 1s => 65535	; 16 bit unsigned int_max
	  0xFFFFFFFF 	: 2^32-1  all 1s			; 32 bit unsigned int_max
	  0xFFFFFFFFFFFFFFFF 	: 2^64-1  all 1s			: 64 bit unsigned int_max

NOTE: to calculate range of unsigned number type : 2^n - 1; where n is no of bits
	  
	  for signed : 2^(n-1)-1
*/
int main()
{
	// setting kth bit
	int n=5;
	n=n|(1<<3);
	cout << "After setting 4th bit 5 is: " << n << "\n";
	n=n^(1<<2);
	cout << "After toggling 3rd bit of 13: " << n << "\n\n"; 

	// unsetting kth bit
	n=15;
	int max_val = (0xFF^1<<2);	//0xFF means last 8 bits of the number set to 1, (remaining all 0)  i.e (2^8-1) = 255 then rightmost 3rd bit is toggled to 0 using XOR operation
	n=n&max_val;		
	cout <<"15 after unsetting leftmost 3rd bit is: " << n << "\n\n";

	// flipping the number (by flipping its bits) 	
	int number = 24;
	cout << "Number: " << number <<'\n';
	int value= 0xFF;	// means last 8 bits of the number set to 1 (rest all 0) i.e. (2^8-1)=255
	cout << "Flipped number: "  << value - number << "\n\n";

	// dividing a number by 2
	number = 5;
	cout << "Dividing 5 by 2: " << (number>>1) << "\n\n";

	// multiplying a number by 2
	number = 5;
	cout << "Multiplying 5 by 2: " << (number<<1) << "\n\n";

	// swapping two numbers
	int a=5, b=10;
	cout << "Before swapping: " << a << " " << b << endl;
	a^=b;
	b^=a;
	a^=b;
	cout << "After swapping: " << a << "  " << b << "\n\n";

	
	cout << "Setting bits (8bits, 16bits, 32bits, 64bits) by using hex values :\n";
	int value0=0xFF;
	cout << "0xFF : " << value0 << endl;
	int value1=0xFFFF;
	cout << "0xFFFF : " <<  value1 << endl;
	uint32_t value2=0xFFFFFFFF;
	cout << "0xFFFFFFFF : " << value2 << endl;
	uint64_t value3 = 0xFFFFFFFFFFFFFFFF;
	cout << "0xFFFFFFFFFFFFFFFF : " << value3 << "\n\n";

	cout << "Alternatively it can be done as: \n";
	uint8_t e = ~0;
	cout << +e << endl;
	uint16_t c = ~0;
	cout << c << endl;
	uint32_t x = ~0;
	cout << x << endl;
	uint64_t y = ~0;
	cout << y << endl;

	// NOTE: check this out 
	cout << "\nCheck this: \n";
	uint8_t cd = 127;
	cout << cd << endl;
	uint8_t d = ~0;
	cout << d << endl;
	// This behavior is because internally C++ treats uint8_t and int8_t 
	// as unsigned char and signed char respectively
	// To print the int value of these we need to print the ASCII value by +varName or unsigned(varName)
	cout << +d << " " << unsigned(d) << endl;
	return 0;
}