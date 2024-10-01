/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:58:24 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/01 09:03:51 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);        // Um burocrata com o nível mais alto
        Bureaucrat alice("Alice", 50);   // Um burocrata com um nível intermediário
        Bureaucrat john("John", 140);    // Um burocrata com nível baixo

        ShrubberyCreationForm shrubbery("home");        // Plantar arbustos em "home"
        RobotomyRequestForm robotomy("Bender");         // Robotomizar "Bender"
        PresidentialPardonForm pardon("Ford Prefect");  // Perdoar "Ford Prefect"

        std::cout << "== Inicializando formulários ==" << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n== Tentando assinar os formulários ==" << std::endl;
        john.signForm(shrubbery);  // John pode assinar ShrubberyCreationForm
        alice.signForm(robotomy);  // Alice pode assinar RobotomyRequestForm
        bob.signForm(pardon);      // Bob pode assinar PresidentialPardonForm

        std::cout << "\n== Tentando executar os formulários ==" << std::endl;
        john.executeForm(shrubbery);   // John pode executar ShrubberyCreationForm
        alice.executeForm(robotomy);   // Alice tentará robotomizar "Bender"
        bob.executeForm(pardon);       // Bob pode perdoar Ford Prefect

        std::cout << "\n== Testando exceções ==" << std::endl;
        Bureaucrat lowRank("LowRank", 150);
        lowRank.signForm(robotomy);    // LowRank não consegue assinar
        lowRank.executeForm(robotomy); // LowRank não consegue executar

    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
