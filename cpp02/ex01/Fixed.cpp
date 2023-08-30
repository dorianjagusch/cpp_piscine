/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:42 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int value )
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _frac_bits;
}

Fixed::Fixed( float value ) : _value(value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = int( float( value ) * float( 1 << _frac_bits ) );
}

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return _value ;
}

int Fixed::setRawBits( int const raw )
{
	_value = raw;
	return raw ;
}

Fixed &Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this->_value != rhs.getRawBits() )
		_value = rhs.getRawBits();
	return *this ;
}

float	Fixed::toFloat( void ) const
{
	return float( _value ) / float( 1 << _frac_bits );
}

int		Fixed::toInt( void ) const
{
	return _value >> _frac_bits ;
}

std::ostream &operator<<( std::ostream &out, Fixed const &num )
{
	out << num.toFloat();
	return out ;
}