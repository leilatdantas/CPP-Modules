/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:23 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/12 12:44:10 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	std::string	getName();
	int			getGrade();
	void		incrementGrade();
	void		decrementGrade();
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat& other);

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
#define BLACK "\033[38;5;0m"
#define DARK_RED "\033[38;5;88m"
#define DARK_GREEN "\033[38;5;22m"
#define DARK_YELLOW "\033[38;5;130m"
#define DARK_BLUE "\033[38;5;18m"
#define DARK_MAGENTA "\033[38;5;90m"
#define DARK_CYAN "\033[38;5;30m"
#define LIGHT_GRAY "\033[38;5;250m"
#define DARK_GRAY "\033[38;5;240m"
#define LIGHT_RED "\033[38;5;196m"
#define LIGHT_GREEN "\033[38;5;82m"
#define LIGHT_YELLOW "\033[38;5;226m"
#define LIGHT_BLUE "\033[38;5;45m"
#define LIGHT_MAGENTA "\033[38;5;213m"
#define LIGHT_CYAN "\033[38;5;87m"
#define LIGHT_WHITE "\033[38;5;15m"

#endif