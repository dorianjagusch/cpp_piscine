/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:45 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( int value );
	Fixed( float value );
	Fixed( Fixed const &src );
	~Fixed( void );

	Fixed &	operator=( Fixed const &rhs );
	int		getRawBits( void ) const;
	int		setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int _value;
	static int const _frac_bits = 8;
};

std::ostream &operator<<( std::ostream &out, Fixed const &num );