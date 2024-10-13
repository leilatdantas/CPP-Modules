/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:48:46 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 15:16:06 by lebarbos         ###   ########.fr       */
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

AForm*	Intern::makeForm(std::string form, std::string target)
{
	std::string s[3] = {"Shrubbery Creation", "Presidential Pardon", "Robotomy Request"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newPresidential, &Intern::newRobotomy};
	int i = 0;
	while(i < 4 && strcasecmp(s[i].c_str(), form.c_str()) != 0)
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