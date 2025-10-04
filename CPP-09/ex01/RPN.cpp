/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:21:51 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 12:56:03 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

void RPN::clear()
{
	while (!_stack.empty())
		_stack.pop();
}

bool RPN::isOperator(const std::string& token) const
{
	return token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;
	
	size_t start = 0;
	if (token[0] == '+' || token[0] == '-')
		start = 1;
	
	if (start >= token.length())
		return false;
	
	bool hasDecimal = false;
	for (size_t i = start; i < token.length(); i++)
	{
		if (token[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
		else if (!std::isdigit(token[i]))
			return false;
	}
	
	return true;
}

double RPN::stringToDouble(const std::string& str) const
{
	std::istringstream iss(str);
	double value;
	iss >> value;
	if (iss.fail() || !iss.eof())
		throw RPNException("Error: invalid number format");
	return value;
}

double RPN::performOperation(char op, double a, double b) const
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw RPNException("Error: division by zero");
			return a / b;
		default:
			throw RPNException("Error: unknown operator");
	}
}

double RPN::evaluate(const std::string& expression)
{
	clear();
	
	if (expression.empty())
		throw RPNException("Error: empty expression");
	
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		if (isNumber(token))
		{
			try
			{
				double num = stringToDouble(token);
				if (num < 0 || num >= 10)
					throw RPNException("Error: numbers must be between 0 and 9");
				_stack.push(num);
			}
			catch (const RPNException&)
			{
				throw;
			}
			catch (const std::exception&)
			{
				throw RPNException("Error: invalid number");
			}
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw RPNException("Error: insufficient operands");
			
			double b = _stack.top(); _stack.pop();
			double a = _stack.top(); _stack.pop(); // important order - 1st operator is the second one on stack
			
			try
			{
				double result = performOperation(token[0], a, b);
				_stack.push(result);
			}
			catch (const RPNException&)
			{
				throw;
			}
		}
		else
		{
			throw RPNException("Error: invalid token");
		}
	}
	
	if (_stack.size() != 1)
		throw RPNException("Error: invalid expression");
	
	return _stack.top();
}
