/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:58:24 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 13:11:05 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

void testFormInitialization() 
{
    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << DARK_GRAY << "\n\n=========================================================" << std::endl;
    std::cout << DARK_GRAY << "================== Initializing forms ===================" << std::endl;
    std::cout << DARK_GRAY << "=========================================================\n" << RESET << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;
}

void testSigningForms() 
{
    Bureaucrat john("John", 146);
    Bureaucrat alice("Alice", 50);
    Bureaucrat bob("Bob", 0);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << DARK_GRAY << "\n\n===============================================================" << std::endl;
    std::cout << DARK_GRAY << "================== Trying to sign the forms ===================" << std::endl;
    std::cout << DARK_GRAY << "===============================================================\n" << RESET << std::endl;
    john.signForm(shrubbery);
    alice.signForm(robotomy);
    bob.signForm(pardon);
}

void testExecutingForms()
{
    Bureaucrat john("John", 146);
    Bureaucrat alice("Alice", 50);
    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << DARK_GRAY << "\n\n==================================================================" << std::endl;
    std::cout << DARK_GRAY << "================== Trying to execute the forms ===================" << std::endl;
    std::cout << DARK_GRAY << "==================================================================\n" << RESET << std::endl;
    john.executeForm(shrubbery);
    alice.executeForm(robotomy);
    bob.executeForm(pardon);
}

void testExceptions()
{
    Bureaucrat lowRank("LowRank", 150);
    RobotomyRequestForm robotomy("Bender");

    std::cout << DARK_GRAY << "\n\n=========================================================" << std::endl;
    std::cout << DARK_GRAY << "================== Testing Exceptions ===================" << std::endl;
    std::cout << DARK_GRAY << "=========================================================" << RESET << std::endl;
    lowRank.signForm(robotomy);
    lowRank.executeForm(robotomy);
}

int main() 
{
    try 
    {
        testFormInitialization();
        testSigningForms();
        testExecutingForms();
        testExceptions();
    } 
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
