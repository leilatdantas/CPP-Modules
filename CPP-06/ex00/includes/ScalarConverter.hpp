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
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <cctype>
# include <limits>
# include <string>
# include <cstdlib>

#define RESET = "\033[0m"
#define BLACK = "\033[30m"
#define RED = "\033[31m"
#define GREEN = "\033[32m"
#define YELLOW = "\033[33m"
#define BLUE = "\033[34m"
#define MAGENTA = "\033[35m"
#define CYAN = "\033[36m"


typedef enum {

	_CHAR,
	_INT,
	_FLOAT,
	_DOUBLE,
	_P_INFF,
	_N_INFF,
	_NANF,
	_P_INF,
	_N_INF,
	_NAN,
	INVALID
} TYPE;

class ScalarConverter 
{
	private:


		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();


	public:

		static void convert(std::string str);

	class ImpossibleConversion : public std::exception {
		virtual const char* what() const throw() {
			return ("Impossible conversion exception");
		}
	};
};


#endif