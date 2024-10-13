/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:23:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 14:39:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestFormDefault", 72, 45), target("Default"), executionCount(0)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target), executionCount(0)
{
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &  executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedExeption();
	if (executor.getGrade() > getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << ITALIC << ROSE << "\n* Drilling noises *" << RESET << std::endl;
	if (executionCount % 2)
		std::cout << "Robotomy failed for " << target << "!" << std::endl;
	else
		std::cout << PURPLE << target << RESET << " has been robotomized successfully!" << std::endl;
	executionCount++;
}
