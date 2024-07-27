/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:50:58 by lebarbos          #+#    #+#             */
/*   Updated: 2024/07/27 12:07:25 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include "PhoneBook.hpp"
# include "Contact.hpp"

#define DARKPURPLE "\033[38;5;141m"
#define LIGHTPURPLE "\033[38;5;225m"
#define ROSE "\033[38;5;217m"
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[38;5;228m"
#define GREEN "\033[38;5;148m"
#define CYAN "\033[38;5;159m"
#define BLUE "\033[38;5;153m"
#define PURPLE "\033[38;5;177m"
#define WHITE "\033[38;5;231m"
#define RED "\033[38;5;124m"
#define PINK "\033[38;5;198m"
#define RESET "\033[0m"
#define BOLD "\e[1m"

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