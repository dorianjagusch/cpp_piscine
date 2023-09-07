/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:48:06 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/05 16:38:15 by djagusch         ###   ########.fr       */
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
		char const * what( void ) const throw() {
			return ( "Too few elements in span" );
		}
	};

	class SpanFullException : public std::exception{
		char const * what( void ) const throw() {
			return ( "Span is already at capacity" );
		}
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


Span::Span() : _capacity( 0 )
{}

Span::Span( unsigned int N ) : _capacity( N )
{
}


Span::Span( Span const & src )
{
	*this = src;
}


Span::~Span()
{
}


Span &	Span::operator=( Span const & rhs )
{
	if( this != &rhs )
	{
		_capacity = rhs._capacity;
		_values = rhs._values;
	}
	return *this;
}

const std::list<int> & Span::getList( void ) const
{
	return (_values);
}


void	Span::addNumber( int value ){
	if ( _capacity == 0 || _values.size() + 1 > _capacity )
		throw( SpanFullException() );
	_values.push_back(value);
	_first = _values.begin();
	_last = _values.end();
}

void	Span::addNumber( std::list<int>::const_iterator start, std::list<int>::const_iterator end)
{
	for (std::list<int>::const_iterator i = start; i != end; i++){
		if ( _capacity == 0 || _values.size() + 1 > _capacity)
			throw ( SpanFullException() );
		_values.push_back(*i);
	}
}


unsigned int	Span::shortestSpan( void ) const {
	if (_values.size() < 2)
		throw ( NumberOfElementsException() );
	unsigned int min = std::numeric_limits<unsigned int>::max();
	for (std::list<int>::const_iterator i = _first; i != _last; i++){
		for (std::list<int>::const_iterator j = i; j != _last; j++){
			if ( i != j && labs( *i - *j ) < min)
				min = labs( *i - *j );
		}
	}
	return min;
}

unsigned int	Span::longestSpan( void ) const {
	if (_values.size() < 2)
		throw ( NumberOfElementsException() );
	return *max_element( _first, _last ) - *min_element( _first, _last );
}


std::ostream & operator<<(std::ostream & o, Span const & rhs )
{
	for (std::list<int>::const_iterator i = rhs.getList().begin(); i != rhs.getList().end(); i++){
		o << *i << "; ";
	}
	o << std::endl;
	return (o);
}

#endif