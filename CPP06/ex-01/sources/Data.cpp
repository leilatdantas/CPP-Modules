/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:30:00 by lebarbos          #+#    #+#             */
/*   Updated: 2025/07/26 14:30:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data() : id(0), name(""), value(0.0), active(false) {}

Data::Data(int id, const std::string& name, double value, bool active)
	: id(id), name(name), value(value), active(active) {}

Data::Data(const Data& other)
	: id(other.id), name(other.name), value(other.value), active(other.active) {}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		id = other.id;
		name = other.name;
		value = other.value;
		active = other.active;
	}
	return *this;
}

Data::~Data() {}

void Data::display() const {
	std::cout << "Data { id: " << id 
			  << ", name: \"" << name 
			  << "\", value: " << value 
			  << ", active: " << (active ? "true" : "false") 
			  << " }" << std::endl;
}
