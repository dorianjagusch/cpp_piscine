/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:58:23 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 09:39:54 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "fstream"

void replace_string(std::string inString, std::ofstream& outFile, std::string s1, std::string s2)
{
	size_t	pos;

	pos = inString.find(s1);
	if (pos == std::string::npos || s1.length() == 0)
		outFile << inString;
	else
	{
		outFile << inString.substr(0, pos);
		outFile << s2;
		replace_string(inString.substr(pos + s1.length()), outFile, s1, s2);
	}
}

int main(int ac, char **av)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		fileName;
	std::string		inString;

	if (ac != 4)
	{
		std::cerr << "Wrong numbers of paramters (3): <filename> <search-string> <replacement-string>" << std::endl;
		return (1);
	}
	fileName = av[1];
	inFile.open(fileName.c_str(), std::fstream::in);
	if (!inFile.is_open() || !inFile.good()
		|| inFile.peek() == std::ifstream::traits_type::eof()){
		std::cerr << "Failed to open input file." << std::endl;
		return (2);
	}
	outFile.open(fileName.append(".replace").c_str(), std::fstream::out);
	if (!outFile.is_open() || !outFile.good()){
		std::cerr << "Failed to open output file." << std::endl;
		inFile.close();
		return (3);
	}

	while (std::getline(inFile, inString))
	{
		replace_string(inString, outFile, av[2], av[3]);
		outFile << '\n';
	}

	inFile.close();
	outFile.close();
	return 0;
}