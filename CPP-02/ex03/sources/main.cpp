/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:41:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/17 16:08:29 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
int main() 
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(2, 2);
    bool result1 = bsp(a, b, c, p1);
    std::cout << "Test 1 - Point (2, 2) inside the triangle: " << (result1 ? "True" : "False") << std::endl;
    Point p2(10, 10);
    bool result2 = bsp(a, b, c, p2);
    std::cout << "Test 2 - Point (10, 10) outside the triangle: " << (result2 ? "True" : "False") << std::endl;
    Point p3(0, 0);
    bool result3 = bsp(a, b, c, p3);
    std::cout << "Test 3 - Point (0, 0) at the vertex of the triangle: " << (result3 ? "True" : "False") << std::endl;
    Point p4(5, 0);
    bool result4 = bsp(a, b, c, p4);
    std::cout << "Test 4 - Point (5, 0) on the edge of the triangle: " << (result4 ? "True" : "False") << std::endl;
    Point p5(1, 1);
    bool result5 = bsp(a, b, c, p5);
    std::cout << "Test 5 - Point (1, 1) inside the triangle: " << (result5 ? "True" : "False") << std::endl;

    return 0;
}
