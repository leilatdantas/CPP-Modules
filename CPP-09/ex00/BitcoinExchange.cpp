/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:21:28 by lebarbos          #+#    #+#             */
/*   Updated: 2025/08/11 21:21:29 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <climits>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

float BitcoinExchange::stringToFloat(const std::string& str) const
{
	std::stringstream ss(str);
	float value;
	ss >> value;
	if (ss.fail() || !ss.eof())
		throw BitcoinExchangeException("bad input => " + str);
	return value;
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return false;
	}
	
	int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + 
			   (date[2] - '0') * 10 + (date[3] - '0');
	int month = (date[5] - '0') * 10 + (date[6] - '0');
	int day = (date[8] - '0') * 10 + (date[9] - '0');
	
	if (year < 2009 || year > 2022)
		return false;
	if (month < 1 || month > 12)
		return false;
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
		
	return true;
}

bool BitcoinExchange::isValidValue(float value) const
{
	return value >= 0 && value <= 1000;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw BitcoinExchangeException("Error: could not open database file.");
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue; // Skip header line
		}
		
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
			
		std::string date = trim(line.substr(0, commaPos));
		std::string valueStr = trim(line.substr(commaPos + 1));
		
		if (!isValidDate(date))
			continue;
			
		try
		{
			float value = stringToFloat(valueStr);
			_database[date] = value;
		}
		catch (const std::exception&)
		{
			continue;
		}
	}
	
	file.close();
	
	if (_database.empty())
		throw BitcoinExchangeException("Error: empty or invalid database file.");
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
	if (it == _database.begin())
		throw BitcoinExchangeException("Error: no data available for date " + date);
	--it;
	return it->first;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _database.find(date);
	if (it != _database.end())
		return it->second;
	
	// Find closest previous date
	std::string closestDate = findClosestDate(date);
	return _database.find(closestDate)->second;
}

void BitcoinExchange::displayExchange(const std::string& date, float value) const
{
	try
	{
		float rate = getExchangeRate(date);
		float result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw BitcoinExchangeException("Error: could not open input file.");
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue; // Skip header line
		}
		
		if (line.empty())
			continue;
		
		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 3));
		
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		
		try
		{
			float value = stringToFloat(valueStr);
			
			if (value < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			
			if (!isValidValue(value))
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			
			displayExchange(date, value);
		}
		catch (const BitcoinExchangeException& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	
	file.close();
}
