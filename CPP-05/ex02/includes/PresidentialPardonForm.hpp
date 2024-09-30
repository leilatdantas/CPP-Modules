/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:46:44 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/30 20:52:23 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "../includes/AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

private:
};

#endif