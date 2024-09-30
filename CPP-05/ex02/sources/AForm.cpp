/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:24:10 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/30 20:43:34 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm()
	: _name("Defalult"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << CYAN << getName() << " constructor called with gradeToSign " << CYAN << getSignGrade() << RESET << " and gradeToExecute " << CYAN << getExecuteGrade() << RESET << std::endl; 
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		// Note: _name, _gradeToSign, and _gradeToExecute are not assigned because they are const
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << BLUE << getName() << RESET << " destructor called." << std::endl;
}

std::string	AForm::getName()
{
	return _name;
}

int		AForm::getSignGrade()
{
	return _gradeToSign;
}
	
int		AForm::getExecuteGrade()
{
	return _gradeToExecute;
}
	
bool	AForm::isSigned()
{
	return _isSigned;
}
	
void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return DARK_RED "AForm-Grade is too high!" RESET;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return DARK_GREEN "AForm-Grade is too low!" RESET;
}
