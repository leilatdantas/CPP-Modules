/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:58:24 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/12 11:33:06 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

void testFormInitialization() 
{
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "== Inicializando formulários ==" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;
}

void testSigningForms() 
{
    Bureaucrat john("John", 146);
    Bureaucrat alice("Alice", 50);
    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "\n== Tentando assinar os formulários ==" << std::endl;
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

    std::cout << "\n== Tentando executar os formulários ==" << std::endl;
    john.executeForm(shrubbery);
    alice.executeForm(robotomy);
    bob.executeForm(pardon);
}

void testExceptions()
{
    Bureaucrat lowRank("LowRank", 150);
    RobotomyRequestForm robotomy("Bender");

    std::cout << "\n== Testando exceções ==" << std::endl;
    try
    {
        lowRank.signForm(robotomy);
    } catch (std::exception& e)
    {
        std::cerr << "Erro ao assinar: " << e.what() << std::endl;
    }
    try {
        lowRank.executeForm(robotomy);
    } catch (std::exception& e) {
        std::cerr << "Erro ao executar: " << e.what() << std::endl;
    }
}

int main() 
{
    try {
        testFormInitialization();
        testSigningForms();
        testExecutingForms();
        testExceptions();
    } catch (std::exception& e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    return 0;
}
