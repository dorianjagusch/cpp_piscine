/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:48:06 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/15 10:35:58 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <list>
# include <limits>
# include <algorithm>

class Span
{
public:
	class NumberOfElementsException : public std::exception{
		virtual char const * what( void ) const throw();
	};

	class SpanFullException : public std::exception{
		virtual char const * what( void ) const throw();
	};

	Span( unsigned int N );
	Span( Span const & src );
	~Span();

	Span &	operator=( Span const & rhs );
	const std::list<int> & getList( void ) const;

	void			addNumber( int value );
	void			addNumber( std::list<int>::const_iterator start, std::list<int>::const_iterator end);
	unsigned int	shortestSpan( void ) const ;
	unsigned int	longestSpan( void ) const ;

private:
	Span();
	unsigned int					_capacity;
	std::list<int>					_values;
	std::list<int>::const_iterator	_first;
	std::list<int>::const_iterator	_last;
};

std::ostream & operator<<(std::ostream & o, Span const & rhs );

#endif