/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:17:58 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/16 08:22:40 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

#include "../includes/Form.hpp"

int main()
{
    try
    {
        std::cout << DARK_GRAY << "\n\n=========================================================" << std::endl;
        std::cout << DARK_GRAY << "========================= Tests =========================" << std::endl;
        std::cout << DARK_GRAY << "=========================================================" << RESET << std::endl;
        Bureaucrat bob("Bob", 10);
        Form remake("Remake", 20, 120);
        std::cout << remake << std::endl;
        bob.signForm(remake);
		bob.signForm(remake);
        std::cout << remake << std::endl;
        std::cout << bob << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
