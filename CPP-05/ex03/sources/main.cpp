/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:02:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/16 18:06:43 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Intern.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main()
{
    Intern someRandomIntern;

    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Alice");
    AForm* form3 = someRandomIntern.makeForm("robotomy request", "Bob");

    if (form1)
        std::cout << "Form 1: " << form1->getName() << " created successfully." << std::endl;
    if (form2)
        std::cout << "Form 2: " << form2->getName() << " created successfully." << std::endl;
    if (form3)
        std::cout << "Form 3: " << form3->getName() << " created successfully." << std::endl;

    AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Unknown");
    if (!invalidForm)
        std::cout << "Invalid form was not created, as expected." << std::endl;

    Bureaucrat highLevel("HighLevel", 1);  // Um Bureaucrat com nível alto o suficiente para assinar e executar os formulários
    try {
        if (form1) {
            form1->beSigned(highLevel);
            form1->execute(highLevel);
        }
        if (form2) {
            form2->beSigned(highLevel);
            form2->execute(highLevel);
        }
        if (form3) {
            form3->beSigned(highLevel);
            form3->execute(highLevel);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    delete form1;
    delete form2;
    delete form3;

    return 0;
}
