/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:42 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/24 23:17:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int value )
{
	//std::cout << "Int constructor called" << std::endl;
	_value = value << _frac_bits;
}

Fixed::Fixed( float value ) : _value(value)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = (int)(float(value) * float(1<<_frac_bits));
}

Fixed::Fixed( Fixed const & src )
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (_value);
}

int Fixed::setRawBits( int const raw )
{
	_value = raw;
	return (raw);
}

float	Fixed::toFloat( void ) const
{
	return (float(_value) / float(1<<_frac_bits));
}

int		Fixed::toInt( void ) const
{
	return (_value >> _frac_bits);
}



std::ostream & operator<<( std::ostream & out, Fixed const & num )
{
	out << num.toFloat();
	return (out);
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this->_value != rhs.getRawBits())
		_value = rhs.getRawBits();
	return (*this);
}

//Comparative operators

bool	Fixed::operator>( Fixed const & rhs ) const
{
	return ( this->getRawBits() > rhs.getRawBits() );
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	return ( this->getRawBits() < rhs.getRawBits() );
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	return ( this->getRawBits() >= rhs.getRawBits() );
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	return ( this->getRawBits() <= rhs.getRawBits() );
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	return ( this->getRawBits() == rhs.getRawBits() );
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	return ( this->getRawBits() != rhs.getRawBits() );
}


//Arithmetic operations

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	Fixed result;

	result.setRawBits(_value + rhs.getRawBits());
	return ( result );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	Fixed result;

	result.setRawBits(_value - rhs.getRawBits());
	return ( result );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	Fixed result;

	result.setRawBits((static_cast<long long>(_value) * static_cast<long long>(rhs.getRawBits()))>>_frac_bits);
	return ( result );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	Fixed result;

	result.setRawBits(((static_cast<long long>(_value)) << _frac_bits) / static_cast<long long>(rhs.getRawBits()));
	return ( result );
}


// Increment and Decrement overload

Fixed &	Fixed::operator++( void )
{
	_value++;
	return (*this);
}

Fixed 	Fixed::operator++( int )
{
	Fixed temp(*this);

	_value++;
	return (temp);
}

Fixed &	Fixed::operator--( void )
{
	_value--;
	return (*this);
}

Fixed 	Fixed::operator--( int )
{
	Fixed temp(*this);

	_value--;
	return (temp);
}

// Static comparison functions

const Fixed & Fixed::min(Fixed const & a, Fixed const & b)
{
	std::cout << "const min called" << std::endl;
	if (a < b)
		return (a);
	return (b);
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b)
{
	std::cout << "const max called" << std::endl;
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	std::cout << "min called" << std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	std::cout << "max called" << std::endl;
	if (a > b)
		return (a);
	return (b);
}
