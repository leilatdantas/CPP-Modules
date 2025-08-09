/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:30:00 by lebarbos          #+#    #+#             */
/*   Updated: 2025/07/26 14:30:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

int main() {
	// Create a Data object with some meaningful data
	Data originalData(42, "Test Object", 3.14159, true);
	
	std::cout << "=== Serialization Test ===" << std::endl;
	std::cout << "Original Data object:" << std::endl;
	originalData.display();
	std::cout << "Original pointer address: " << &originalData << std::endl;
	std::cout << std::endl;
	
	// Test serialization
	std::cout << "=== Serializing pointer ===" << std::endl;
	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
	std::cout << std::endl;
	
	// Test deserialization
	std::cout << "=== Deserializing back to pointer ===" << std::endl;
	Data* deserializedPtr = Serializer::deserialize(serialized);
	std::cout << "Deserialized pointer address: " << deserializedPtr << std::endl;
	std::cout << std::endl;
	
	// Verify the pointers are equal
	std::cout << "=== Verification ===" << std::endl;
	std::cout << "Original pointer == Deserialized pointer: " 
			  << ((&originalData == deserializedPtr) ? "YES ✓" : "NO ✗") << std::endl;
	
	// Verify the data is intact
	if (deserializedPtr) {
		std::cout << "Data integrity check:" << std::endl;
		deserializedPtr->display();
		
		bool dataIntact = (deserializedPtr->id == originalData.id &&
						   deserializedPtr->name == originalData.name &&
						   deserializedPtr->value == originalData.value &&
						   deserializedPtr->active == originalData.active);
		std::cout << "Data integrity: " << (dataIntact ? "PRESERVED ✓" : "CORRUPTED ✗") << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "=== Additional Tests ===" << std::endl;
	
	// Test with different Data objects
	Data data1(1, "First", 1.1, true);
	Data data2(2, "Second", 2.2, false);
	
	uintptr_t ser1 = Serializer::serialize(&data1);
	uintptr_t ser2 = Serializer::serialize(&data2);
	
	Data* deser1 = Serializer::deserialize(ser1);
	Data* deser2 = Serializer::deserialize(ser2);
	
	std::cout << "Multiple objects test:" << std::endl;
	std::cout << "data1 address: " << &data1 << " -> serialized: " << ser1 << " -> deserialized: " << deser1 << std::endl;
	std::cout << "data2 address: " << &data2 << " -> serialized: " << ser2 << " -> deserialized: " << deser2 << std::endl;
	std::cout << "Pointers match: " << ((&data1 == deser1 && &data2 == deser2) ? "YES ✓" : "NO ✗") << std::endl;
	
	// Test with null pointer
	std::cout << std::endl << "Null pointer test:" << std::endl;
	Data* nullPtr = NULL;
	uintptr_t serializedNull = Serializer::serialize(nullPtr);
	Data* deserializedNull = Serializer::deserialize(serializedNull);
	std::cout << "NULL -> " << serializedNull << " -> " << deserializedNull << std::endl;
	std::cout << "Null preservation: " << ((nullPtr == deserializedNull) ? "YES ✓" : "NO ✗") << std::endl;
	
	return 0;
}
