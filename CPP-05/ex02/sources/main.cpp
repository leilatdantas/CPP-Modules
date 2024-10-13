/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:58:24 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 14:34:18 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

void testFormInitialization() 
{
    std::cout << DARK_GRAY << "\n\n=========================================================" << std::endl;
    std::cout << DARK_GRAY << "================== Initializing forms ===================" << std::endl;
    std::cout << DARK_GRAY << "=========================================================\n" << RESET << std::endl;
    try {
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testSigningForms() 
{
    try
    {
        std::cout << DARK_GRAY << "\n\n===============================================================" << std::endl;
        std::cout << DARK_GRAY << "================= Trying to create Bureaucrats ================" << std::endl;
        std::cout << DARK_GRAY << "===============================================================\n" << RESET << std::endl;
        Bureaucrat john("John", 140);
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 2);
        std::cout << DARK_GRAY << "\n\n===============================================================" << std::endl;
        std::cout << DARK_GRAY << "======================= Creating Forms ========================" << std::endl;
        std::cout << DARK_GRAY << "===============================================================\n" << RESET << std::endl;
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");
        std::cout << DARK_GRAY << "\n\n===============================================================" << std::endl;
        std::cout << DARK_GRAY << "================== Trying to sign the forms ===================" << std::endl;
        std::cout << DARK_GRAY << "===============================================================\n" << RESET << std::endl;
        john.signForm(shrubbery);
        alice.signForm(robotomy);
        bob.signForm(pardon);
        std::cout << DARK_GRAY << "\n\n==================================================================" << std::endl;
        std::cout << DARK_GRAY << "================== Trying to execute the forms ===================" << std::endl;
        std::cout << DARK_GRAY << "==================================================================\n" << RESET << std::endl;
        john.executeForm(shrubbery);
        // alice.executeForm(shrubbery);
        alice.executeForm(robotomy);
        bob.executeForm(robotomy);
        alice.executeForm(robotomy);
        bob.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error creating Bureaucrats: "<< e.what() << '\n';
    }
}

void testExceptions()
{
    std::cout << DARK_GRAY << "\n\n=========================================================" << std::endl;
    std::cout << DARK_GRAY << "================== Testing Exceptions ===================" << std::endl;
    std::cout << DARK_GRAY << "=========================================================" << RESET << std::endl;
    Bureaucrat lowRank("LowRank", 150);
    RobotomyRequestForm robotomy("Bender");
    lowRank.signForm(robotomy);
    lowRank.executeForm(robotomy);
}

int main() 
{
    testFormInitialization();
    testSigningForms();
    testExceptions();
    return 0;
}
