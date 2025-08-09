/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:00:00 by lebarbos          #+#    #+#             */
/*   Updated: 2025/07/26 15:00:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>

int main() {
	std::cout << "=== Dynamic Cast Type Identification Test ===" << std::endl;
	std::cout << std::endl;
	
	// Test with multiple random generations
	std::cout << "Testing random generation and identification:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;
		
		Base* obj = generate();
		if (obj) {
			std::cout << "identify(Base* p): ";
			identify(obj);
			
			std::cout << "identify(Base& p): ";
			identify(*obj);
			
			delete obj;
		}
	}
	
	std::cout << std::endl;
	std::cout << "=== Manual Testing with Known Types ===" << std::endl;
	
	// Test with known types
	std::cout << "\nTesting with manually created objects:" << std::endl;
	
	A* a = new A();
	B* b = new B();
	C* c = new C();
	
	std::cout << "\nObject A:" << std::endl;
	std::cout << "identify(Base* p): ";
	identify(static_cast<Base*>(a));
	std::cout << "identify(Base& p): ";
	identify(static_cast<Base&>(*a));
	
	std::cout << "\nObject B:" << std::endl;
	std::cout << "identify(Base* p): ";
	identify(static_cast<Base*>(b));
	std::cout << "identify(Base& p): ";
	identify(static_cast<Base&>(*b));
	
	std::cout << "\nObject C:" << std::endl;
	std::cout << "identify(Base* p): ";
	identify(static_cast<Base*>(c));
	std::cout << "identify(Base& p): ";
	identify(static_cast<Base&>(*c));
	
	// Test edge cases
	std::cout << std::endl;
	std::cout << "=== Edge Cases ===" << std::endl;
	
	std::cout << "\nTesting NULL pointer:" << std::endl;
	std::cout << "identify(NULL): ";
	identify(static_cast<Base*>(NULL));
	
	// Test with Base pointer to Base object (if we had one)
	std::cout << "\nTesting polymorphic behavior:" << std::endl;
	Base* polyA = new A();
	Base* polyB = new B();
	Base* polyC = new C();
	
	std::cout << "Base* pointing to A: ";
	identify(polyA);
	std::cout << "Base* pointing to B: ";
	identify(polyB);
	std::cout << "Base* pointing to C: ";
	identify(polyC);
	
	std::cout << "\nReference testing:" << std::endl;
	std::cout << "Base& referring to A: ";
	identify(*polyA);
	std::cout << "Base& referring to B: ";
	identify(*polyB);
	std::cout << "Base& referring to C: ";
	identify(*polyC);
	
	// Cleanup
	delete a;
	delete b;
	delete c;
	delete polyA;
	delete polyB;
	delete polyC;
	
	std::cout << std::endl;
	std::cout << "=== Test completed successfully! ===" << std::endl;
	
	return 0;
}
