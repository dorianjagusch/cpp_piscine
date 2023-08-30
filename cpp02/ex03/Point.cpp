/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:39:43 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point( Point const &src ) : _x(src._x), _y(src._y)
{
	*this = src;
}

Point::Point (float const &x, float const &y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point &	Point::operator=( Point const &rhs )
{
	if( this != &rhs )
	{
		(Fixed) _x = rhs.getX();
		(Fixed) _y = rhs.getY();
	}
	return *this;
}

Fixed Point::getX( void ) const
{
	return _x;
}

Fixed Point::getY( void ) const
{
	return _y;
}

std::ostream &operator<<( std::ostream &out, Point const &point )
{
	out  << "x: " << std::setw(8) << point.getX() << "\ty: " << std::setw(8) << point.getY();
	return out;
}