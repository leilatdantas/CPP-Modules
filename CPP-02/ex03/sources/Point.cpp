/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:26:43 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/17 16:09:42 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point()
	: x(0), y(0)
{
}

Point::Point(const float nbr1, const float nbr2)
	: x(nbr1), y(nbr2)
{
}


Point::Point(const Point& other)
{
	*this = other;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		const_cast<Fixed&>(x) = other.x;
		const_cast<Fixed&>(y) = other.y;
	}
	return *this;
}

Point::~Point()
{
}

const Fixed&	Point::getX() const
{
	return this->x;
}

const Fixed&	Point::getY() const
{
	return this->y;
}

Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) + 
                  (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) + 
                  (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));
	if (area < 0)
		area = area * Fixed(-1);
	return (area/ Fixed(2));
}



// Fixed area(Point const a, Point const b, Point const c) 
// {
//     // Acesso constante aos valores
//     float ax = a.getX().toFloat();
//     float ay = a.getY().toFloat();
//     float bx = b.getX().toFloat();
//     float by = b.getY().toFloat();
//     float cx = c.getX().toFloat();
//     float cy = c.getY().toFloat();

//     std::cout << "Pontos: A(" << ax << ", " << ay << "), B(" << bx << ", " << by << "), C(" << cx << ", " << cy << ")\n";

//     Fixed area = ((ax * (by - cy)) + 
//                   (bx * (cy - ay)) + 
//                   (cx * (ay - by)));
//     std::cout << "Cálculo da área antes da correção: " << area << std::endl;

//     // Corrige a área se for negativa
//     if (area < Fixed(0))
//         area = area * Fixed(-1);

//     std::cout << "Área corrigida: " << area << std::endl;
    
//     return area / Fixed(2);
// }


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	//area: 1/2 | x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
	Fixed A1(area(a, point, c));
	Fixed A2(area(point, b, c));
	Fixed A3(area(a, b, point));
	Fixed Atotal(area(a, b, c));
    return ((A1 + A2 + A3) == Atotal) && (A1 != 0) && (A2 != 0) && (A3 != 0);
}
