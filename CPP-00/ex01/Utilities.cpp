/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:59:11 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/25 18:20:25 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utilities.hpp"

bool	is_valid_number(std::string phonenbr)
{
	if (phonenbr.size() < 6 || phonenbr.size() > 15)
		return (false);
	for(size_t i = 0; i < phonenbr.length(); i++)
	{
		if (!std::isdigit(phonenbr[i]))
			return (false);
	}
	return (true);
}

void trim(std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\v\f");
	if (start == std::string::npos)
		str.clear();
	else
	{
		size_t end = str.find_last_not_of(" \t\r\v\f");
		str = str.substr(start, end - start + 1);
	}
}

void to_upper(std::string& str) 
{
    for (size_t i = 0; i < str.size(); ++i) 
    {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

std::string get_prompt(int field)
{
	std::string prompt;
	if (field == FIRST_NAME)
		prompt = "First name: ";
	if (field == LAST_NAME)
		prompt = "Last name: ";
	if (field == NICKNAME)
		prompt = "Nickname: ";
	if (field == PHONENBR)
		prompt = "Phone number (it must have between 6 and 15 numbers): ";
	if (field == SECRET)
		prompt = "Darkest secret: ";
	return prompt;
}

std::string get_info(int field) {
    std::string ret;
    std::string prompt = get_prompt(field);
    do {
		std::cout << prompt;
        std::getline(std::cin, ret);
        if (std::cin.eof()) {
 			std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
			return "";
        }
        trim(ret);
        if (ret.empty()) {
            std::cout << "Field can't be empty. Try again." << std::endl;
        }
		else if (field == PHONENBR) {
			do {
				if (!is_valid_number(ret)) {
					std::cout << "Invalid number. Try again!" << std::endl << prompt;
					std::getline(std::cin, ret);
					if (std::cin.eof()) {
						std::cin.clear(); // Limpa o estado de erro
            			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
						return "";
					}
					trim(ret);
				}
			} while (!is_valid_number(ret));
		}
    } while (ret.empty());
    return ret;
}
