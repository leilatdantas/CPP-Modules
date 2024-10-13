/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:24:10 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 15:05:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm()
	: _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << DARK_CYAN "- " << getName() << " constructor called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << RESET << std::endl; 
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (_gradeToSign > 150 || _gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << DARK_CYAN "- " << getName() << " constructor called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << RESET << std::endl; 
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << DARK_CYAN "- " << getName() << " copy constructor called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << RESET << std::endl; 
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		(void)other;
		// _name, _gradeToSign, and _gradeToExecute are not assigned because they are const
		std::cout << DARK_CYAN "- " << getName() << " copy assignment called with gradeToSign " << getSignGrade() << " and gradeToExecute " << getExecuteGrade() << " - " << RESET << std::endl; 
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << ORANGE << "- " << getName() << " destructor called - " << RESET << std::endl;
}

std::string	AForm::getName() const
{
	return _name;
}

int		AForm::getSignGrade() const
{
	return _gradeToSign;
}
	
int		AForm::getExecuteGrade() const
{
	return _gradeToExecute;
}
	
bool	AForm::isSigned() const
{
	return _isSigned;
}
	
void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	else if (_isSigned)
		throw AForm::AlreadySignedException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return DARK_GREEN "AForm grade is too high!" RESET;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return DARK_RED "AForm grade is too low!" RESET;
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return DARK_MAGENTA "AForm is already signed!" RESET;
}

const char* AForm::FormNotSignedExeption::what() const throw()
{
	return DARK_YELLOW "AForm is not signed!" RESET;
}

std::ostream& operator<<(std::ostream &out, AForm& other)
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