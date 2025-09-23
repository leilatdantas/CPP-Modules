/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:18:07 by lebarbos          #+#    #+#             */
/*   Updated: 2025/09/23 20:34:12 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << "[LOG] Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "[LOG] After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "xuxu1";
	std::string d = "xuxu2";

	std::cout << "[LOG] Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "[LOG] After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return 0;
}
