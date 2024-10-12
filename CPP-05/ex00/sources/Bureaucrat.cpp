/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/12 14:34:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{
	std::cout << CYAN << getName() << RESET << " constructor called with grade " << CYAN << getGrade() << RESET << "." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << PURPLE << getName() << RESET << " constructor called with grade " << PURPLE << getGrade() << RESET << "." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << ROSE << getName() << RESET << "copy constructor called with grade " << ROSE << getGrade() << RESET << "." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << PINK << getName() << RESET << " copy assignment operator called with grade " << PINK << getGrade() << RESET << "." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << getName() << RESET << " destructor called." << std::endl;
}

std::string Bureaucrat::getName()
{
	return _name;
}

int			Bureaucrat::getGrade()
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	std::cout << DARK_GRAY << "Calling increment function for " << LIGHT_GREEN<< getName() << RESET << std::endl;
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << LIGHT_GREEN << "Increment done for " << getName() << "!" << RESET << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	std::cout << DARK_GRAY << "Calling decrement function for " << LIGHT_RED << getName() << RESET << std::endl;
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	std::cout << LIGHT_RED << "Decrement done for " << getName() << "!" << RESET << std::endl;
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED "Grade too high!" RESET;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED "Grade too low!" RESET;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& other)
{
	out << GREEN << other.getName() << RESET << ", bureaucrat grade: " << GREEN << other.getGrade() << RESET;
	return out;
}
