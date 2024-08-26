/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:41:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/24 14:59:20 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cstdlib>
#include <ctime>

int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	// Testing constructors and conversions
	Fixed c(42.42f);        // Constructor with float
	Fixed d(b);             // Copy constructor
	Fixed e = c;            // Copy assignment

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;

	// Testing conversions to float and int
	std::cout << "b to int: " << b.toInt() << std::endl;
	std::cout << "c to float: " << c.toFloat() << std::endl;

	// Testing arithmetic operators
	Fixed f = b + c;
	Fixed g = c - b;
	Fixed h = b * c;
	Fixed i = c / b;

	std::cout << "b + c: " << f << std::endl;
	std::cout << "c - b: " << g << std::endl;
	std::cout << "b * c: " << h << std::endl;
	std::cout << "c / b: " << i << std::endl;

	// Testing comparison operators
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= d: " << (b >= d) << std::endl;
	std::cout << "c <= e: " << (c <= e) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "c != e: " << (c != e) << std::endl;

	// Testing increment and decrement operators
	Fixed j;
	Fixed o(0);

	std::cout << "j / 0: " << j / o << std::endl;
	std::cout << "++j: " << ++j << std::endl;
	std::cout << "j to int: " << j.toInt() << std::endl;
	std::cout << "j++: " << j++ << std::endl;
	std::cout << "j: " << j << std::endl;

	std::cout << "--j: " << --j << std::endl;
	std::cout << "j--: " << j-- << std::endl;
	std::cout << "j: " << j << std::endl;

	// Testing static min and max functions
	Fixed const k(5.25f);
	Fixed const l(10.5f);

	std::cout << "min(k, l): " << Fixed::min(k, l) << std::endl;
	std::cout << "max(k, l): " << Fixed::max(k, l) << std::endl;

	// Testing modifications on objects using min and max
	Fixed m = Fixed::min(a, b);
	Fixed n = Fixed::max(a, b);

	std::cout << "min(a, b): " << m << std::endl;
	std::cout << "max(a, b): " << n << std::endl;

	return 0;
}
