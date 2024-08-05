/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:19:13 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/05 17:26:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

void	replaceString(std::string filename, std::string string1, std::string string2)
{
	std::string::size_type pos = 0;
	std::string::size_type found = 0;

	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cout << "Error opening the file: " << filename <<  std::endl;
		return ;
	}
	std::istreambuf_iterator<char> begin(inputFile);
	std::istreambuf_iterator<char> end;
	std::string fileContent(begin, end);
	inputFile.close();
	std::string result;
	while(true)
	{
		found = fileContent.find(string1, pos);
		if (found == std::string::npos)
			break ;
		result.append(fileContent, pos, found - pos);
		result.append(string2);
		pos = found + string1.length();
	}
	result.append(fileContent, pos, fileContent.length() + pos);
	
	std::string newFilename = filename + ".replace";
	std::ofstream outfile;
	outfile.open(newFilename, std::ofstream::trunc);
	if (!outfile.is_open())
		std::cout << "Error opening outfile: " << newFilename << std::endl;
	outfile << result; 
	outfile.close();
}

int main(int argc, char const *argv[])
{
	(void)argv;
	if (argc != 4)
	{
		std::cout << std::endl;
		std::cout << RED << "Usage: " << RESET << "<filename> <string1> <string2>" << std::endl;
		std::cout << std::endl;
		return 1;
	}
	replaceString(argv[1], argv[2], argv[3]);
	return 0;
}
