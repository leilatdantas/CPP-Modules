/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:52:03 by lebarbos          #+#    #+#             */
/*   Updated: 2025/03/05 16:48:19 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)(other); }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// ************************************************************************** //

TYPE ScalarConverter::getType(const std::string &str)
{
	static std::string specialLiterals[] = {"+inff", "-inff", "nanf", "+inf", "-inf", "nan"};
	static TYPE specialTypes[] = {_P_INFF, _N_INFF, _NANF, _P_INF, _N_INF, _NAN};

	for (size_t i = 0; i < 6; i++)
	{
		if (str == specialLiterals[i])
			return specialTypes[i];
	}

	if ((str.length() == 3 && str[0] == '\'' && str[2] == '\'' && std::isprint(str[1])) ||
		(str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])))
	{
		return _CHAR;
	}

	int dots = 0, fCount = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			continue;
		if (str[i] == '.')
			dots++;
		else if (str[i] == 'f')
			fCount++;
		else if (!std::isdigit(str[i]))
			return INVALID;
	}

	if (dots == 0 && fCount == 0)
		return _INT;
	if (dots == 1 && fCount == 1 && str.back() == 'f')
		return _FLOAT;
	if (dots == 1 && fCount == 0)
		return _DOUBLE;
	return INVALID;
}

void ScalarConverter::convert(const std::string &literal)
{
	TYPE type = getType(literal);
	if (type == INVALID)
	{
		std::cout << "Error: invalid." << std::endl;
		return;
	}
	printConversion(literal, type);
}

void ScalarConverter::printConversion(const std::string &input, TYPE type)
{
	switch (type)
	{
	case _CHAR:
		convertChar(input);
		break;
	case _INT:
		convertInt(input);
		break;
	case _FLOAT:
		convertFloat(input);
		break;
	case _DOUBLE:
		convertDouble(input);
		break;
	case _P_INFF:
	case _N_INFF:
	case _NANF:
	case _P_INF:
	case _N_INF:
	case _NAN:
		convertSpecial(input);
		break;
	default:
		std::cout << "Error: Invalid type." << std::endl;
	}
}

void ScalarConverter::convertChar(const std::string &str)
{
	char c;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		c = str[1];
	}
	else
	{
		c = str[0];
	}

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &str)
{
	long double num = std::stold(str);

	std::cout << "char: ";
	if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(num))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: ";
	if (num > std::numeric_limits<float>::max() || num < -(std::numeric_limits<float>::max() + 1))
		std::cout << "overflow\n";
	else
	{
		if (static_cast<float>(num) <= 999999)
			std::cout << static_cast<float>(num) << ".0f" << std::endl;
		else
			std::cout << static_cast<float>(num) << "f" << std::endl;
	}

	std::cout << "double: ";
	if (num > std::numeric_limits<double>::max() || num < -(std::numeric_limits<double>::max() + 1))
		std::cout << "overflow\n";
	else
	{
		if (static_cast<double>(num) <= 999999)
			std::cout << static_cast<double>(num) << ".0" << std::endl;
		else
			std::cout << static_cast<double>(num) << std::endl;
	}
}

void ScalarConverter::convertFloat(const std::string &str)
{
	long double num = std::stold(str);

	std::cout << "char: ";
	if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(num)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;

	std::cout << "float: ";
	if (num > std::numeric_limits<float>::max() || num < -(std::numeric_limits<float>::max() + 1))
		std::cout << "overflow\n";
	else
	{
		if (static_cast<float>(num) <= 999999)
			std::cout << static_cast<float>(num) << ".0f" << std::endl;
		else
			std::cout << static_cast<float>(num) << "f" << std::endl;
	}

	std::cout << "double: ";
	if (num > std::numeric_limits<double>::max() || num < -(std::numeric_limits<double>::max() + 1))
		std::cout << "overflow\n";
	else
	{
		if (static_cast<double>(num) <= 999999)
			std::cout << static_cast<double>(num) << ".0" << std::endl;
		else
			std::cout << static_cast<double>(num) << std::endl;
	}
}

void ScalarConverter::convertDouble(const std::string &str)
{
	long double num = std::stold(str);

	std::cout << "char: ";
	if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(num)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;

	std::cout << "float: ";
	if (num > std::numeric_limits<float>::max() || num < -(std::numeric_limits<float>::max() + 1))
		std::cout << "overflow\n";
	else
	{
		if (static_cast<float>(num) <= 999999)
			std::cout << static_cast<float>(num) << ".0f" << std::endl;
		else
			std::cout << static_cast<float>(num) << "f" << std::endl;
	}

	std::cout << "double: ";
	if (num > std::numeric_limits<double>::max() || num < -(std::numeric_limits<double>::max() + 1))
		std::cout << "overflow\n";
	else
	{
		if (static_cast<double>(num) <= 999999)
			std::cout << static_cast<double>(num) << ".0" << std::endl;
		else
			std::cout << static_cast<double>(num) << std::endl;
	}
}

void ScalarConverter::convertSpecial(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "+inff" || str == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "nanf" || str == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}
