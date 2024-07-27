/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:42 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/27 13:08:01 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utilities.hpp"

PhoneBook::PhoneBook()
{
	_nb_contacts = 0;
	_oldest_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
	std::string fields[5];
	for (int i = 0; i < 5; i++)
		fields[i] = get_info(i);
	Contact contact(fields[FIRST_NAME], fields[LAST_NAME], fields[NICKNAME], fields[PHONENBR], fields[SECRET]);
	if (_nb_contacts < MAX_CONTACTS)
	{
		_contacts[_nb_contacts] = contact;
		_nb_contacts++;
	}
	else
	{
		_contacts[_oldest_contact] = contact;
		_oldest_contact = (_oldest_contact + 1) % MAX_CONTACTS;
	}
}

void PhoneBook::display()
{
	std::cout << std::endl;
	std::cout << BOLD << DARKPURPLE << std::setw(10) << "Index" << RESET << GREEN << "|" << RESET;
	std::cout << BOLD << PURPLE << std::setw(10) << "First Name" << RESET << GREEN << "|" << RESET;
	std::cout << BOLD << PURPLE << std::setw(10) << "Last Name" << RESET << GREEN << "|" << RESET;
	std::cout << BOLD << PURPLE << std::setw(10) << "Nickname" << RESET << GREEN << "|" << RESET << std::endl;
	for (int i = 0; i < _nb_contacts; i++)
	{
		std::cout << BOLD << DARKPURPLE << std::setw(10) << i + 1 << RESET << GREEN << "|" << RESET;
		_contacts[i].display_resume();
	}
	std::cout << std::endl;
	
}

void PhoneBook::search_contact()
{
	int i;

	std::string index;
	if (_nb_contacts == 0)
	{
		std::cout << std::endl << ORANGE << "No contacts to display (yet)." << RESET << std::endl;
		return ;
	}
	display();
	std::cout << "Enter the index of the contact you want to display: ";
	std::getline(std::cin, index);
	if (std::cin.eof())
	{
		std::cout << std::endl << RED << "You interrupted the PhoneBook. Goodbye! 👋🏻" << RESET << std::endl;
		exit (0);
	}
	else if (index.length() == 1 && index[0] >= '1' && index[0] < _nb_contacts + '1')
	{
		i = (index[0] - '0') - 1;
		_contacts[i].display_contact();
	}
	else
		std::cout << ORANGE << "\n⚠️  Invalid index. Next time choose a index between " << 1 << " and " << _nb_contacts << "." << RESET << std::endl;
}
