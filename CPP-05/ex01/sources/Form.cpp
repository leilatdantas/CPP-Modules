/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:24:10 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/12 15:03:51 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form()
	: _name("Defalult"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << CYAN << getName() << RESET << " constructor called with gradeToSign " << CYAN << getSignGrade() << RESET << " and gradeToExecute " << CYAN << getExecuteGrade() << RESET << std::endl; 
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (_gradeToSign > 150 || _gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << CYAN << getName() << RESET << " constructor called with gradeToSign " << CYAN << getSignGrade() << RESET << " and gradeToExecute " << CYAN << getExecuteGrade() << RESET << std::endl; 
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		// _name, _gradeToSign, and _gradeToExecute are not assigned because they are const
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << BLUE << getName() << RESET << " destructor called." << std::endl;
}

std::string	Form::getName()
{
	return _name;
}

int		Form::getSignGrade()
{
	return _gradeToSign;
}
	
int		Form::getExecuteGrade()
{
	return _gradeToExecute;
}
	
bool	Form::isSigned()
{
	return _isSigned;
}
	
void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return DARK_YELLOW "Form-Grade is too high!" RESET;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return DARK_CYAN "Form-Grade is too low!" RESET;
}

std::ostream& operator<<(std::ostream &out, Form& other)
{
	out << "Form: " << GREEN << other.getName() << RESET 
	<< ", requires grade " << GREEN << other.getSignGrade() << RESET 
	<< " to sign and grade " << other.getExecuteGrade() << " to execute. Signed: ";
	if (other.isSigned())
		out << "Yes";
	else
		out << "No";
	return out;
}
