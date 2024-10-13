/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:53:48 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 13:43:43 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationFormDefault", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedExeption();
	if (executor.getGrade() > getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream file((target + "_shrubbery").c_str());
	if(file.is_open())
	{
		file << "       \n"
			 << "       _-_\n"
			 << "    /~~ 🍎 ~~\\\n"
			 << " /~~        🍎~~\\\n"
			 << "{      🍎       }\n"
			 << " \\🍎 _-     -_🍎 /\n"
			 << "   ~  \\ //  ~\n"
			 << "_- -   | | _- _\n"
			 << "  _ -  | |   -_\n"
			 << "      // \\\n";
		file.close();
	}
	else
		std::cerr << "Failed to create file." << std::endl;
}
