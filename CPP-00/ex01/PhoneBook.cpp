/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:42 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/25 18:02:08 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	{
		fields[i] = get_info(i);
	}
	Contact contact(fields[FIRST_NAME], fields[LAST_NAME], fields[NICKNAME], fields[PHONENBR], fields[SECRET]);
	if (_nb_contacts < MAX_CONTACTS)
	{
		_contacts[_nb_contacts] = contact;
		contact.set_index(_nb_contacts + 1);
		_nb_contacts++;
	}
	else
	{
		_contacts[_oldest_contact] = contact;
		contact.set_index(_oldest_contact + 1);
		_oldest_contact = (_oldest_contact + 1) % MAX_CONTACTS;
	}
}

void PhoneBook::display()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _nb_contacts; i++)
	{
		_contacts[i].display_contact(i + 1);
	}
	
}

void PhoneBook::search_contact()
{
	int i;

	std::string index;
	if (_nb_contacts == 0)
	{
		std::cout << "No contacts to display (yet)." << std::endl;
		return ;
	}
	display();
	std::cout << "Enter the index of the contact you want to display: ";
	std::getline(std::cin, index);
	if (std::cin.eof())
	{
		return ;
	}
	else if (index.length() == 1 && index[0] >= '1' && index[0] < _nb_contacts + '1')
	{
		i = (index[0] - '0') - 1;
		_contacts[i].display_contact();
	}
	else
		std::cout << "Invalid index." << std::endl;
}
