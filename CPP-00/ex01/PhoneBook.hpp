/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:07:03 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/25 18:28:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "Utilities.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact _contacts[MAX_CONTACTS];
	int		_nb_contacts;
	int		_oldest_contact;
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void display();
	void search_contact();
};

#endif