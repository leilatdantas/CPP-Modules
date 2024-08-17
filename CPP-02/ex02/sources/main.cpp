/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:41:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/17 15:55:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // Testes iniciais fornecidos
    std::cout << "Initial tests:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;

    // Novos testes
    std::cout << "\nAdditional operator overloading tests:" << std::endl;

    // Operadores aritméticos
    Fixed c = a + b;
    std::cout << "a + b: " << a << " + " << b << " = " << c << std::endl;

    c = a - b;
    std::cout << "a - b: " << a << " - " << b << " = " << c << std::endl;

    c = b / a;
    std::cout << "b / a: " << b << " / " << a << " = " << c << std::endl;
	std::cout << "REAL 10.1016 / 0.0078125: " << 10.1016 / 0.0078125 << std::endl;

    c = a * b;
    std::cout << "a * b: " << a << " * " << b << " = " << c << std::endl;

    // Operadores de comparação
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // Teste do construtor de cópia e operador de atribuição
    Fixed d(c);
    std::cout << "\nCopy constructor d(c): " << d << std::endl;

    Fixed e;
    e = d;
    std::cout << "Assignment operator e = d: " << e << std::endl;

	std::cout << "\nPrecision tests with arithmetic operations:" << std::endl;

	Fixed f1(1.5f);
	Fixed f2(0.3f);
	Fixed result_fixed = f1 / f2;
	float result_float = 1.5f / 0.3f;

	std::cout << "Fixed point division (1.5 / 0.3): " << result_fixed << std::endl;
	std::cout << "Float division (1.5 / 0.3): " << result_float << std::endl;
	std::cout << "Difference: " << (result_float - result_fixed.toFloat()) << std::endl;

	#include <cmath>

	std::cout << "\nPrecision tests with trigonometric functions:" << std::endl;

	Fixed angle_fixed(0.785398f); // 45 degrees in radians
	float angle_float = 0.785398f;

	Fixed sin_fixed = Fixed(sin(static_cast<float>(angle_fixed.toFloat())));
	float sin_float = sin(angle_float);

	std::cout << "Fixed point sin(45 degrees): " << sin_fixed << std::endl;
	std::cout << "Float sin(45 degrees): " << sin_float << std::endl;
	std::cout << "Difference: " << (sin_float - static_cast<float>(sin_fixed.toFloat())) << std::endl;

	std::cout << "\nPrecision tests with small numbers:" << std::endl;

	Fixed small_fixed(0.0001f);
	Fixed large_fixed(10000.0f);
	Fixed result_small_fixed = small_fixed * large_fixed;
	float small_float = 0.0001f;
	float large_float = 10000.0f;
	float result_small_float = small_float * large_float;

	std::cout << "Fixed point multiplication (0.0001 * 10000): " << result_small_fixed << std::endl;
	std::cout << "Float multiplication (0.0001 * 10000): " << result_small_float << std::endl;
	std::cout << "Difference: " << (result_small_float - static_cast<float>(result_small_fixed.toFloat())) << std::endl;

	std::cout << "\nTesting overflow and underflow:" << std::endl;

	Fixed max_fixed(MAXFLOAT);
	Fixed overflow_test = max_fixed * Fixed(2);
	std::cout << "Overflow test result: " << overflow_test << std::endl;

	Fixed underflow_test = Fixed(0) / Fixed(0.0000001f); // Avoid division by zero in practice
	std::cout << "Underflow test result: " << underflow_test << std::endl;

	std::cout << "\nTesting with random values:" << std::endl;

	std::srand(std::time(nullptr));

	for (int i = 0; i < 5; ++i) {
		float random_float = static_cast<float>(std::rand()) / RAND_MAX;
		Fixed random_fixed(random_float);

		std::cout << "Random float value: " << random_float << std::endl;
		std::cout << "Converted Fixed point value: " << random_fixed << std::endl;
		std::cout << "Difference: " << (random_float - static_cast<float>(random_fixed.toFloat())) << std::endl;
	}

	Fixed nul(0);
	Fixed one(1);
	Fixed Result = one / nul; 
	std::cout << "DIVISAO POR ZERO: " << Result << std::endl;
	float zero = 0;
	float oneeee = 1; 
	float division = oneeee/zero; 
	std::cout << "DIVISAO POR ZERO FLOAT: " << division << std::endl;
    return 0;
}
