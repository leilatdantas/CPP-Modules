/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:48:46 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/16 18:08:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}

Intern::~Intern()
{
}

AForm*	Intern::newShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::newPresidential(std::string target)
{
	return(new PresidentialPardonForm(target));
}

AForm*	Intern::newRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string s[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newPresidential, &Intern::newRobotomy};
	int i = 0;
	while(i < 3 && s[i] != form) // Changed the loop condition to i < 3
		i++;
	if(i < 3)
	{
		std::cout << "Intern creates " << s[i] << std::endl;
		return ((this->*p[i])(target));
	}
	else {
		std::cout << form << " is not a valid form." << std::endl;
	}
	return NULL;
}