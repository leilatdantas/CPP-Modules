/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:24:10 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 12:22:26 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form()
	: _name("Defalult"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << DARK_CYAN "- " << getName() << " form constructor called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << RESET << std::endl; 
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
	std::cout << DARK_CYAN "- " << getName() << " form constructor called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << RESET << std::endl; 
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << DARK_CYAN "- " << getName() << " form copy constructor called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << RESET << std::endl; 
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		(void)other;
		// _name, _gradeToSign, and _gradeToExecute are not assigned because they are const
		std::cout << DARK_CYAN "- " << getName() << " form copy assigment called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << " - " << RESET << std::endl; 
	}
	return *this;
}

Form::~Form()
{
	std::cout << ORANGE << "- Form " << getName() << " destructor called - " << RESET << std::endl;
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
		throw Bureaucrat::GradeTooLowException();
	else if (_isSigned)
		throw Form::AlreadySignedException();
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

const char* Form::AlreadySignedException::what() const throw()
{
	return DARK_MAGENTA "Form is already signed!" RESET;
}

std::ostream& operator<<(std::ostream &out, Form& other)
{
	out << "\n------------------------------------------------------------\n"
		<< UNDERLINE << BOLD  << "\t\t\tForm Details:\n" << RESET
		<< "  Name: " << PURPLE << other.getName() << RESET << "\n"
		<< "  Grade required to sign: " << PURPLE << other.getSignGrade() << RESET << "\n"
		<< "  Grade required to execute: " << PURPLE << other.getExecuteGrade() << RESET << "\n"
		<< "  Signed: " << (other.isSigned() ? LIGHT_GREEN "Yes" RESET : LIGHT_RED "No" RESET) << "\n"
		<< "------------------------------------------------------------\n";
	return out;
}
