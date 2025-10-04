/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:21:45 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 18:43:40 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	try
	{
		RPN calculator;
		double result = calculator.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
//8  9 * 9 - 9 - 4 - 1 +
// Token  | Action           | Stack State
// -------|------------------|------------
// "8"    | push(8)         | [8]
// "9"    | push(9)         | [8, 9]
// "*"    | pop 9,8 → 8*9=72| [72]
// "9"    | push(9)         | [72, 9]
// "-"    | pop 9,72 → 72-9 | [63]
// "9"    | push(9)         | [63, 9]
// "-"    | pop 9,63 → 63-9 | [54]
// "9"    | push(9)         | [54, 9]
// "-"    | pop 9,54 → 54-9 | [45]
// "4"    | push(4)         | [45, 4]
// "-"    | pop 4,45 → 45-4 | [41]
// "1"    | push(1)         | [41, 1]
// "+"    | pop 1,41 → 41+1 | [42]

// Resultado: 42