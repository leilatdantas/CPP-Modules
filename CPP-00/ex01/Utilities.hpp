/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:50:58 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/25 18:35:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include "PhoneBook.hpp"
# include "Contact.hpp"
# define DARKBLUE "\033[38;5;141m" // Azul escuro
# define LIGHTPURPLE "\033[38;5;225m" // Lilás claro
# define RESET "\033[0m" // Reset de cor

enum Field
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONENBR,
	SECRET
};

void		trim(std::string& str);
void 		to_upper(std::string& str);
bool		is_valid_number(std::string phonenbr);
std::string get_info(int field);
std::string get_prompt(int field);
std::string	treat_info(std::string str);

#endif