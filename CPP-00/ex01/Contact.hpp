/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:17:28 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/29 15:14:01 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <unistd.h>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phonenbr;
	std::string _darkest_secret;

public:
	Contact();
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phonenbr, std::string darkest_secret);
	void	display_resume();
	void	display_contact();
	~Contact();
};

#endif 