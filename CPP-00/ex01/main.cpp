/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:11:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/29 15:27:20 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utilities.hpp"
#include <termios.h>
#include <unistd.h>

void set_terminal_mode() {
    struct termios tattr;

    // Obter os atributos do terminal
    tcgetattr(STDIN_FILENO, &tattr);

    // Definir o terminal para o modo não canônico e sem eco
    tattr.c_lflag &= ~(ECHO);

    // Definir os atributos do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

// Função para restaurar o terminal ao modo original
void reset_terminal_mode() {
    struct termios tattr;

    // Obter os atributos do terminal
    tcgetattr(STDIN_FILENO, &tattr);

    // Restaurar o terminal para o modo canônico e com eco
    tattr.c_lflag |= (ICANON | ECHO);

    // Definir os atributos do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

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
    display_options();
}


int main()
{
    PhoneBook pb;
    std::string option;
    // set_terminal_mode();
    while (1)
    {
        displayBanner();
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
                {
                    pb.search_contact();
                    sleep(3);
                }
                else if ((option.length() == 1 && option[0] == '3') || option == "EXIT")
                {
                    std::cout << CYAN << "Exiting PhoneBook..." << RESET << std::endl;
                    exit (0);
                }
                else
                    std::cout << std::endl << ORANGE << "⚠️  Invalid option. Try again!" << RESET << std::endl;
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
