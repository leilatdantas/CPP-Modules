/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:30:00 by lebarbos          #+#    #+#             */
/*   Updated: 2025/07/26 14:30:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data
{
	int id;
	std::string name;
	double value;
	bool active;
	
	Data();
	Data(int id, const std::string& name, double value, bool active);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();
	
	void display() const;
};

#endif
