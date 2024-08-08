/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:59:11 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/30 16:47:32 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utilities.hpp"

bool	is_valid_number(std::string phonenbr)
{
	if (phonenbr.size() < 3 || phonenbr.size() > 15)
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

void to_upper(std::string &str)
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
		prompt = "Phone number (between 3 and 15 digits): ";
	if (field == SECRET)
		prompt = "Darkest secret: ";
	return prompt;
}

std::string get_info(int field)
{
	std::string ret;
	std::string prompt = get_prompt(field);
	std::cout << std::endl;
	do
	{
		std::cout << RESET << prompt << GREEN;
		std::getline(std::cin, ret);
		if (std::cin.eof())
		{
			std::cout << std::endl
					  << RED << "You interrupted the PhoneBook. Goodbye!" << RESET << std::endl;
			exit(0);
		}
		trim(ret);
		if (ret.empty())
		{
			std::cout << ORANGE << "\n⚠️  Field can't be empty. Try again." << RESET << std::endl;
		}
		else if (field == PHONENBR)
		{
			do
			{
				if (!is_valid_number(ret))
				{
					std::cout << ORANGE << "⚠️  Invalid number. Try again!" << RESET << std::endl
							  << prompt << GREEN;
					std::getline(std::cin, ret);
					if (std::cin.eof())
					{
						std::cout << std::endl
								  << RED << "You interrupted the PhoneBook. Goodbye!" << RESET << std::endl;
						exit(0);
					}
					trim(ret);
				}
			} while (!is_valid_number(ret));
		}
	} while (ret.empty());
	return ret;
}

std::string treat_info(std::string str)
{
	if (str.length() >= 10)
		str = str.substr(0, 9) + ".";
	return str;
}
