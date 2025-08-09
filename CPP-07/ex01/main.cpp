#include "iter.hpp"

// Função simples para demonstrar
void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

int main(void)
{
	// Teste com array de inteiros
	std::cout << "=== Teste com inteiros ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
	
	std::cout << "Array original: ";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl;
	
	::iter(intArray, intSize, increment<int>);
	std::cout << "Após incrementar: ";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl << std::endl;
	
	// Teste com array de chars
	std::cout << "=== Teste com chars ===" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
	
	std::cout << "Array original: ";
	::iter(charArray, charSize, print<char>);
	std::cout << std::endl;
	
	::iter(charArray, charSize, toUpper);
	std::cout << "Em maiúsculas: ";
	::iter(charArray, charSize, print<char>);
	std::cout << std::endl << std::endl;
	
	// Teste com array de strings
	std::cout << "=== Teste com strings ===" << std::endl;
	std::string stringArray[] = {"Hello", "World", "Templates", "CPP"};
	size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
	
	std::cout << "Array de strings: ";
	::iter(stringArray, stringSize, print<std::string>);
	std::cout << std::endl;
	
	return 0;
}
