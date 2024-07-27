/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:17:34 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/27 12:37:25 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Utilities.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phonenbr, std::string darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phonenbr = phonenbr;
	_darkest_secret = darkest_secret;
}

void Contact::display_info()
{
	std::cout << std::setw(10) << treat_info(_first_name) << GREEN << "|" RESET;
	std::cout << std::setw(10) << treat_info(_last_name) << GREEN << "|" RESET;
	std::cout << std::setw(10) << treat_info(_nickname) << GREEN << "|" << RESET << std::endl;
}

void Contact::display_contact()
{
	std::cout << std::endl;
	std::cout << "• First Name: " << GREEN << _first_name << RESET << std::endl;
	std::cout << "• Last Name: " << GREEN << _last_name << RESET << std::endl;
	std::cout << "• Nickname: " << GREEN << _nickname << RESET << std::endl;
	std::cout << "• Phone Number: " << GREEN << _phonenbr << RESET << std::endl;
	std::cout << "• Darkest Secret: " << GREEN << _darkest_secret << RESET << std::endl;
	std::cout << std::endl;
}

Contact::~Contact()
{
}