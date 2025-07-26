/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:08:12 by lebarbos          #+#    #+#             */
/*   Updated: 2025/03/03 12:02:05 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>

enum TYPE {_CHAR, _INT, _FLOAT, _DOUBLE, _P_INFF, _N_INFF, _NANF, _P_INF, _N_INF, _NAN, INVALID };

class ScalarConverter
{
	
public:
	static void convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static TYPE getType(const std::string &str);
	static void printConversion(const std::string &input, TYPE type);

	static void convertChar(const std::string &str);
	static void convertInt(const std::string &str);
	static void convertFloat(const std::string &str);
	// static void convertDouble(const std::string &str);
	// static void convertSpecial(const std::string &str);
	
};

#endif