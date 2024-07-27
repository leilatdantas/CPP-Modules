/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:11:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/27 12:59:08 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utilities.hpp"

void    display_options()
{
    std::cout << std::endl;
    std::cout << DARKPURPLE << "          [1]" << RESET << " ADD ➝" << RESET << LIGHTPURPLE << " Add a new contact to your PhoneBook" << RESET << std::endl;
    std::cout << DARKPURPLE << "          [2]" << RESET << " SEARCH ➝" << RESET << LIGHTPURPLE << " Search for a contact in your PhoneBook" << RESET << std::endl;
    std::cout << DARKPURPLE << "          [3]" << RESET << " EXIT ➝" << RESET << LIGHTPURPLE << " Exit your PhoneBook - You will lose all your saved contacts" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose an option " << PURPLE << "➤ " << RESET;
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
            {
                std::cout << ORANGE << "\n⚠️  Option can't be empty. Try again." << RESET << std::endl;
            }
            else
            {
                to_upper(option);
                if ((option.length() == 1 && option[0] == '1') || option == "ADD")
                    pb.add_contact();
                else if ((option.length() == 1 && option[0] == '2') || option == "SEARCH")
                    pb.search_contact();
                else if ((option.length() == 1 && option[0] == '3') || option == "EXIT")
                {
                    std::cout << CYAN << "Exiting PhoneBook..." << RESET << std::endl;
                    exit (0);
                }
                else
                {
                    std::cout << std::endl << ORANGE << "⚠️  Invalid option. Try again!" << RESET << std::endl;
                }
            }
        }
        else
        {
            std::cout << std::endl << RED << "You interrupted the PhoneBook. Goodbye! 👋🏻" << RESET << std::endl;
            break; 
        }
    }
    return (0);
}
