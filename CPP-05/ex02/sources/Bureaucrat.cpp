/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 12:56:16 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{
	std::cout << CYAN << "- " << getName() << " constructor called with grade " << getGrade() << " -" << RESET  << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << CYAN << "- " << getName() << " constructor called with grade " << getGrade() << " -" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << ROSE << "- " << getName() << RESET << " copy constructor called with grade " << ROSE << getGrade() << " -" << RESET <<  std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << ROSE << "- " << getName() << RESET << " copy assignment operator called with grade " << ROSE << getGrade() << " -" << RESET << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "- " << getName() << " destructor called -" << RESET << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	std::cout << DARK_GRAY << "Calling increment function for " << LIGHT_GREEN << getName() << RESET << std::endl;
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << LIGHT_GREEN << "- Increment done for " << getName() << "! -" << RESET << std::endl;
}

void Bureaucrat::decrementGrade()
{
	std::cout << DARK_GRAY << "Calling decrement function for " << LIGHT_RED << getName() << RESET << std::endl;
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << LIGHT_RED << "- Decrement done for " << getName() << "! -" << RESET << std::endl;
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << getName() << LIGHT_GREEN << " signs " << RESET << form.getName() << "." << std::endl;
	} catch (std::exception& e) {
		std::cout << getName() << LIGHT_RED << " cannot sign " << RESET << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form.getName() << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cerr << getName() << LIGHT_RED << " couldn't execute " << RESET << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED "Bureaucrat grade is too high!" RESET;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED "Bureaucrat grade is too low!" RESET;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& other)
{
	out << "\n------------------------------------------------------------\n"
		<< UNDERLINE << BOLD << "\t\t\tBureaucrat Details:\n" << RESET
		<< "  Name: " << GREEN << other.getName() << RESET << "\n"
		<< "  Grade: " << GREEN << other.getGrade() << RESET << "\n"
		<< "------------------------------------------------------------\n";
	return out;
}
