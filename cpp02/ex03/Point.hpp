/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:30:56 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/24 20:26:14 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <iomanip>
# include "Fixed.hpp"

class Point
{
public:
	Point ();
	Point (float const & _x, float const & _y);
	Point( Point const & src );
	~Point();

	Point &	operator=( Point const & rhs );
	Fixed getX( void ) const;
	Fixed getY( void ) const;

private:
	Fixed const _x;
	Fixed const _y;
};

std::ostream & operator<<( std::ostream & out, Point const & num );

#endif