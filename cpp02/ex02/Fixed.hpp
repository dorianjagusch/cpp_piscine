/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:45 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 17:41:55 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( int value );
		Fixed( float value );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed &	operator=( Fixed const & rhs );
		int		getRawBits( void ) const;
		int		setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		//Comparative operators

		bool	operator>( Fixed const & rhs ) const ;
		bool	operator<( Fixed const & rhs ) const ;
		bool	operator>=( Fixed const & rhs ) const ;
		bool	operator<=( Fixed const & rhs ) const ;
		bool	operator==( Fixed const & rhs ) const ;
		bool	operator!=( Fixed const & rhs ) const ;
		
		//Arithmetic operations

		Fixed	operator+( Fixed const & rhs ) const ;
		Fixed	operator-( Fixed const & rhs ) const ;
		Fixed	operator/( Fixed const & rhs ) const ;
		Fixed	operator*( Fixed const & rhs ) const ;

		// Increment and Decrement overload

		Fixed &	operator++( void );
		Fixed	operator++( int );
		Fixed &	operator--( void );
		Fixed	operator--( int );
		
		// Static comparison functions

		static const Fixed & min(Fixed const & a, Fixed const & b);
		static const Fixed & max(Fixed const & a, Fixed const & b);
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);

	private:
		int _value;
		static int const _frac_bits = 8;
};

std::ostream & operator<<( std::ostream & out, Fixed const & num );