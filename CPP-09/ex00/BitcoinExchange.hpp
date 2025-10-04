/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:21:32 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 12:19:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cctype>

class BitcoinExchange
{
private:
	// use of map -> ordened key -> efficient search 
	std::map<std::string, float> _database;
	
	bool isValidDate(const std::string& date) const;
	bool isValidValue(float value) const;
	bool isLeapYear(int year) const;
	std::string trim(const std::string& str) const;
	float stringToFloat(const std::string& str) const;
	std::string findClosestDate(const std::string& date) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);
	
	void loadDatabase(const std::string& filename);
	void processInputFile(const std::string& filename);
	float getExchangeRate(const std::string& date) const;
	void displayExchange(const std::string& date, float value) const;
};

class BitcoinExchangeException : public std::exception
{
private:
	std::string _message;
	
public:
	BitcoinExchangeException(const std::string& message) : _message(message) {}
	virtual ~BitcoinExchangeException() throw() {}
	virtual const char* what() const throw() { return _message.c_str(); }
};

#endif
