/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:11:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/25 19:10:07 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utilities.hpp"

void    display_options()
{
    std::cout << std::endl;
    std::cout << PURPLE << "          1." << RESET << " ADD" << std::endl;
    std::cout << PURPLE << "          2." << RESET << " SEARCH" << std::endl;
    std::cout << PURPLE << "          3." << RESET << " EXIT" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose one option " << PURPLE << "➤ " << RESET;
}

void displayBanner() {
    system("clear");
    std::cout << LIGHTPURPLE << "██████" << DARKPURPLE << "╗ " << LIGHTPURPLE << "██" << DARKPURPLE << "╗  " << LIGHTPURPLE << "██" << DARKPURPLE << "╗ " << LIGHTPURPLE << "██████" << DARKPURPLE << "╗ " << LIGHTPURPLE << "███" << DARKPURPLE << "╗   " << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "███████" << DARKPURPLE << "╗" << LIGHTPURPLE << "██████" << DARKPURPLE << "╗  " << LIGHTPURPLE << "██████" << DARKPURPLE << "╗  " << LIGHTPURPLE << "██████" << DARKPURPLE << "╗ " << LIGHTPURPLE << "██" << DARKPURPLE << "╗  " << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << std::endl;
    std::cout << LIGHTPURPLE << "██" << DARKPURPLE << "╔══" << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "██" << DARKPURPLE << "║  " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "╔═══" << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "████" << DARKPURPLE << "╗  " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "╔════╝" << LIGHTPURPLE << "██" << DARKPURPLE << "╔══" << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "██" << DARKPURPLE << "╔═══" << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "██" << DARKPURPLE << "╔═══" << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "██" << DARKPURPLE << "║ " << LIGHTPURPLE << "██" << DARKPURPLE << "╔╝" << std::endl;
    std::cout << LIGHTPURPLE << "██████" << DARKPURPLE << "╔╝" << LIGHTPURPLE << "███████" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "║   " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "╔" << LIGHTPURPLE << "██" << DARKPURPLE << "╗ " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "█████" << DARKPURPLE << "╗  " << LIGHTPURPLE << "██████" << DARKPURPLE << "╔╝" << LIGHTPURPLE << "██" << DARKPURPLE << "║   " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "║   " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "█████" << DARKPURPLE << "╔╝ " << std::endl;
    std::cout << LIGHTPURPLE << "██" << DARKPURPLE << "╔═══╝ " << LIGHTPURPLE << "██" << DARKPURPLE << "╔══" << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "║   " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "║" << DARKPURPLE << "╚" << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "╔══╝  " << LIGHTPURPLE << "██" << DARKPURPLE << "╔══" << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << LIGHTPURPLE << "██" << DARKPURPLE << "║   " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "║   " << LIGHTPURPLE << "██" << DARKPURPLE << "║" << LIGHTPURPLE << "██" << DARKPURPLE << "╔═" << LIGHTPURPLE << "██" << DARKPURPLE << "╗ " << std:: endl;
    std::cout << LIGHTPURPLE << "██" << DARKPURPLE << "║     " << LIGHTPURPLE << "██" << DARKPURPLE << "║  " << LIGHTPURPLE << "██" << DARKPURPLE << "║╚" << LIGHTPURPLE << "██████" << DARKPURPLE << "╔╝" << LIGHTPURPLE << "██" << DARKPURPLE << "║ ╚" << LIGHTPURPLE << "████" << DARKPURPLE << "║" << LIGHTPURPLE << "███████" << DARKPURPLE << "╗" << LIGHTPURPLE << "██████" << DARKPURPLE << "╔╝╚" << LIGHTPURPLE << "██████" << DARKPURPLE << "╔╝╚" << LIGHTPURPLE << "██████" << DARKPURPLE << "╔╝" << LIGHTPURPLE << "██" << DARKPURPLE << "║  " << LIGHTPURPLE << "██" << DARKPURPLE << "╗" << std::endl;
    std::cout << DARKPURPLE << "╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝" << RESET << std::endl;
    std::cout << std::endl;
}

int main()
{
    PhoneBook pb;
    std::string option;
    displayBanner();
    while (1)
    {
        display_options();
		std::getline(std::cin, option);
        if (!(std::cin.eof()))
        {
            trim(option);
            if (option.empty())
                std::cout << "Field can't be empty. Try again." << std::endl;
            else
            {
                to_upper(option);
                if ((option.length() == 1 && option[0] == '1') || option == "ADD")
                    pb.add_contact();
                else if ((option.length() == 1 && option[0] == '2') || option == "SEARCH")
                    pb.search_contact();
                else if ((option.length() == 1 && option[0] == '3') || option == "EXIT")
                    exit (0);
                else
                {
                    std::cout << "Invalid option. Try again!" << std::endl;
                    display_options();
                }
            }
        }
        else
        {
            std::cout << std::endl << "Finishing phonebook..." << std::endl;
            break; 
        }
    }
    return (0);
}
