/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:22:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/16 19:38:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float nbr1, const float nbr2);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	const Fixed&	getX() const;
	const Fixed&	getY() const;

private:
	const Fixed x;
	const Fixed	y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif