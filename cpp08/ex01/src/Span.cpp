/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:25:38 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/08 13:54:04 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
				min = static_cast<unsigned int>( labs( *i - *j ) );
		}
	}
	return min;
}

unsigned int	Span::longestSpan( void ) const {

	if (_values.size() < 2)
		throw ( NumberOfElementsException() );
	unsigned int max = static_cast<unsigned int>( *max_element( _values.begin(), _values.end()));
	unsigned int min = static_cast<unsigned int>( *min_element( _values.begin(), _values.end()));
	unsigned int result  = max - min;
	return result;
}

std::ostream & operator<<(std::ostream & o, Span const & rhs )
{
	for (std::list<int>::const_iterator i = rhs.getList().begin(); i != rhs.getList().end(); i++){
		o << *i << "; ";
	}
	o << std::endl;
	return (o);
}
