#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN
{
private:
	std::stack<double> _stack;
	
	bool isOperator(const std::string& token) const;
	bool isNumber(const std::string& token) const;
	double stringToDouble(const std::string& str) const;
	double performOperation(char op, double a, double b) const;

public:
	RPN();
	RPN(const RPN& other);
	~RPN();
	RPN& operator=(const RPN& other);
	
	double evaluate(const std::string& expression);
	void clear();
};

class RPNException : public std::exception
{
private:
	std::string _message;
	
public:
	RPNException(const std::string& message) : _message(message) {}
	virtual ~RPNException() throw() {}
	virtual const char* what() const throw() { return _message.c_str(); }
};

#endif
