/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:19:11 by lebarbos          #+#    #+#             */
/*   Updated: 2025/09/26 17:25:13 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

#define MAX_VAL 750

int main(int, char**)
{
	// Basic test with empty Array
	std::cout << "=== Empty Array test ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
	
	// Test with integer Array
	std::cout << "\n=== Integer Array test ===" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	
	// Check if values match
	bool valuesMatch = true;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "Error: values do not match at index " << i << std::endl;
			valuesMatch = false;
			break;
		}
	}
	if (valuesMatch)
		std::cout << "All values match!" << std::endl;
	
	// Exception tests
	std::cout << "\n=== Exception test ===" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught for negative index: " << e.what() << std::endl;
	}
	
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught for out-of-bounds index: " << e.what() << std::endl;
	}
	
	// Test with strings
	std::cout << "\n=== String Array test ===" << std::endl;
	Array<std::string> strings(5);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "of";
	strings[3] = "Templates";
	strings[4] = "!";
	
	std::cout << "String array: ";
	for (unsigned int i = 0; i < strings.size(); i++)
	{
		std::cout << strings[i] << " ";
	}
	std::cout << std::endl;
	
	delete [] mirror;
	return 0;
}
