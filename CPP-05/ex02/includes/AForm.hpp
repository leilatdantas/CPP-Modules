/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:39:42 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/30 20:43:37 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <fstream>
#include "Bureaucrat.hpp"

class AForm
{
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	std::string	getName() const;
	int		getSignGrade() const;
	int		getExecuteGrade() const;
	bool	isSigned() const;
	void	beSigned(Bureaucrat& b);
	virtual void	execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class FormNotSignedExeption : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, AForm& form);

#endif