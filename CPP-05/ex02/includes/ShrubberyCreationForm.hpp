/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:52:57 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/30 20:53:42 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERYCREATIONFORM_HPP
#define SHRUBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

private:
};

#endif