#include "iter.hpp"

// Simple function to demonstrate
void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

int main(void)
{
	// Test with integer array
	std::cout << "=== Test with integers ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
	
	std::cout << "Original array: ";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl;
	
	::iter(intArray, intSize, increment<int>);
	std::cout << "After increment: ";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl << std::endl;
	
	// Test with char array
	std::cout << "=== Test with chars ===" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
	
	std::cout << "Original array: ";
	::iter(charArray, charSize, print<char>);
	std::cout << std::endl;
	
	::iter(charArray, charSize, toUpper);
	std::cout << "Uppercase: ";
	::iter(charArray, charSize, print<char>);
	std::cout << std::endl << std::endl;
	
	// Test with string array
	std::cout << "=== Test with strings ===" << std::endl;
	std::string stringArray[] = {"Hello", "World", "Templates", "CPP"};
	size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
	
	std::cout << "String array: ";
	::iter(stringArray, stringSize, print<std::string>);
	std::cout << std::endl;
	
	return 0;
}
