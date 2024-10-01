/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:23:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/01 09:04:55 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestFormDefault", 72, 45), target("Default")
{
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestFormDefault", 72, 45), target(target)
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
		throw AForm::GradeTooLowException();
	std::cout << "* Drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << target << "has been romotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << target << "!" << std::endl; 
}
