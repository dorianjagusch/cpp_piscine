/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:04:49 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/21 07:46:24 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <list>
# include <iterator>
# include <algorithm>

# define VECTOR_TYPE 0
# define LIST_TYPE 1
# define MIN_SIZE 3

class PmergeMe
{
public:
	enum error_codes{
		good,
		invalidErr = 1,
		fillingErr
	};

	PmergeMe( int ac, char **arg);
	PmergeMe( PmergeMe const & src );
	~PmergeMe();

	PmergeMe &	operator=( PmergeMe const & rhs );
	
	void					sort( int ac, char **av );
	std::vector<long long>	getContainer( void ) const;

private:
	PmergeMe();
	

	static error_codes				validateInput( int ac, char **args);
	static bool						issign( char const c);
	static int						makeInt( char const *str );
	static bool						isIntOverflow( std::string const & str );
	static void						fillVector( int ac, char **args );
	static void						fillList( int ac, char **args );
	static std::vector<long long>	_container1;
	static std::list<long long>		_container2;

	static void	sortContainer( std::vector<long long>::iterator beg, std::vector<long long>::iterator end );
	static void	insertion_sort( std::vector<long long>::iterator beg , std::vector<long long>::iterator end );
	static void	merge(std::vector<long long>::iterator beg, std::vector<long long>::iterator mid,
				std::vector<long long>::iterator end );
			
	static void	sortContainer( std::list<long long>::iterator beg , std::list<long long>::iterator end );
	static void	insertion_sort( std::list<long long>::iterator beg , std::list<long long>::iterator end );
	static void	merge(std::list<long long>::iterator beg, std::list<long long>::iterator mid,
				std::list<long long>::iterator end );

	static void		setStart( void );
	static void		setDuration( double & duration );
	static double	_startTime;
	static double	_duration1;
	static double	_duration2;
};

# include "utils.tpp"

#endif