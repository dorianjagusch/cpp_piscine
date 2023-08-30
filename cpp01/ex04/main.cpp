/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:58:23 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:28:12 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string getInput( void )
{
	char input[256];

	while ( !std::cin.getline( input, 256 ) )
	{
		if ( std::cin.eof() )
		{
			std::cin.clear();
			std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
			return ( std::string )"" ;
		}
		else if ( std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
			std::cout << "Input too long. Try again." << std::endl;
			return ( std::string )"" ;
		}
	}
	return input ;
}

bool continue_programme()
{
	std::string		input="";
	
	std::cout	<< "WARNING: Literal \"\\n\" and nl characters are BOTH treated as nl characters" << std::endl
				<< "Are you sure you want to proceed? [Y/n]:" << std::flush;
	
	while ( input != "Y" && input != "n" ){
		input = getInput();
		if ( input != "Y" && input != "n" )
			std::cout << "Type [Y] to continue or [n] to cancel: " << std::flush;
	}
	if (input == "n")
		return false ;
	return true ;
}

void replace_string(std::string inString, std::ofstream& outFile, std::string s1, std::string s2)
{
	size_t	pos;

	pos = inString.find( s1 );
	if ( pos == std::string::npos || s1.length() == 0 )
		outFile << inString;
	else
	{
		outFile << inString.substr( 0, pos );
		if ( s2 != "\\n" )
			outFile << s2;
		else
			outFile << std::endl;
		if ( s1 != "\\n" )
			replace_string(inString.substr( pos + s1.length() ), outFile, s1, s2);
		else
			replace_string(inString.substr( pos + 1 ), outFile, s1, s2);
	}
}

void	processInput( std::string & fileName, std::ifstream & inFile,
		std::ofstream & outFile, std::string & s1, std::string & s2 )
{	
	inFile.open(fileName.c_str(), std::fstream::in);
	if (!inFile.is_open() || !inFile.good()){
		std::cerr << "Failed to open input file." << std::endl;
		exit( 1 );
	}
	outFile.open(fileName.append( ".replace" ).c_str(), std::fstream::out );
	if ( !outFile.is_open() || !outFile.good() ){
		std::cerr << "Failed to open output file." << std::endl;
		inFile.close();
		exit( 2 );
	}
	if ( ( s1 == "\\n" || s2 == "\\n" ) && !continue_programme())
		exit( 3 );
}

int main(int ac, char **av)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		fileName;
	std::string		inString;
	std::string		s1;
	std::string		s2;

	if (ac != 4)
	{
		std::cerr << "Wrong numbers of paramters (3): <filename> <search-string> <replacement-string>" << std::endl;
		return 1;
	}
	fileName = av[1];
	s1 = av[2];
	s2 = av[3];
	processInput( fileName, inFile, outFile, s1, s2 );
	inFile.seekg( -1, inFile.end );
	char nl_flag = inFile.get();
	inFile.seekg( 0, inFile.beg );
	bool later_pass = false;
	do {
		replace_string( inString, outFile, s1, s2 );
		if ( nl_flag != '\n' && inFile.eof() )
			break ;
		if ( ( s1 != "\\n" || s2 == "\\n" ) && later_pass )
			outFile << std::endl;
		else if ( s1 == "\\n" && s2 != "\\n" && later_pass )
			outFile << s2; 
		later_pass = true;
	} while ( std::getline( inFile, inString ) );
	inFile.close();
	outFile.close();
	return 0;
}