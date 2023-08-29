/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:45 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/29 17:09:24 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const &src );
		~Fixed();

		Fixed &	operator=( Fixed const &rhs );
		int		getRawBits( void ) const;
		int		setRawBits( int const raw );

	private:
		int _value;
		static int const _frac_bits = 8;
};