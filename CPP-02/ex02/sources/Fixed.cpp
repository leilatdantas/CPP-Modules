/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:55:27 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/17 16:03:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
	: fixedPoint(0)
{
}

Fixed::Fixed(const int number)
{
	fixedPoint = number << bits;
}

Fixed::Fixed(const float number)
{
	fixedPoint = static_cast<int>(roundf(number * (1 << bits)));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{

	if (this != &other)
	{
		fixedPoint = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedPoint) / (1 << bits);
}

int Fixed::toInt(void) const
{
	return static_cast<int>(fixedPoint >> bits);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed& other)
{
	return(this->fixedPoint > other.fixedPoint);
}

bool	Fixed::operator<(const Fixed& other)
{
	return (this->fixedPoint < other.fixedPoint);
}

bool	Fixed::operator>=(const Fixed& other)
{
	return (this->fixedPoint >= other.fixedPoint);
}

bool	Fixed::operator<=(const Fixed& other)
{
	return (this->fixedPoint <= other.fixedPoint);
}

bool	Fixed::operator==(const Fixed& other)
{
	return (this->fixedPoint == other.fixedPoint);
}

bool	Fixed::operator!=(const Fixed& other)
{
	return(this->fixedPoint != other.fixedPoint);
}

Fixed	Fixed::operator+(const Fixed& other)
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)
{
	return Fixed(this->toFloat() * other.toFloat());
}


Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cout << "Error: Division by zero" << std::endl; 
		return (Fixed(0));
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = Fixed(*this);
	this->fixedPoint++;
	return tmp;
}

Fixed	Fixed::operator++()
{
	this->fixedPoint++;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = Fixed(*this);
	this->fixedPoint--;
	return tmp;
}

Fixed	Fixed::operator--()
{
	this->fixedPoint--;
	return *this;
}

const Fixed&	Fixed::min(const Fixed& one, const Fixed& other)
{
	if (one.fixedPoint <= other.fixedPoint)
		return one;
	return other;
}

Fixed&	Fixed::min(Fixed& one, Fixed& other)
{
	if (one.fixedPoint <= other.fixedPoint)
		return one;
	return other;
}

const Fixed&	Fixed::max(const Fixed& one, const Fixed& other)
{
	if (one.fixedPoint >= other.fixedPoint)
		return one;
	return other;
}

Fixed&	Fixed::max(Fixed& one, Fixed& other)
{
	if (one.fixedPoint >= other.fixedPoint)
		return one;
	return other;
}
