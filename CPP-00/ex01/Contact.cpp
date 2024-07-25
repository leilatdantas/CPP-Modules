/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:17:34 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/25 18:35:39 by lebarbos         ###   ########.fr       */
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


void Contact::set_index(int index)
{
	_index = index;
}

void Contact::display_contact(int index)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << treat_info(_first_name) << "|";
	std::cout << std::setw(10) << treat_info(_last_name) << "|";
	std::cout << std::setw(10) << treat_info(_nickname) << std::endl;
}

void Contact::display_contact()
{
	std::cout << "First Name: " << _first_name << std::endl;
	std::cout << "Last Name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phonenbr << std::endl;
	std::cout << "Darkest Secret: " << _darkest_secret << std::endl;
}

Contact::~Contact()
{
}