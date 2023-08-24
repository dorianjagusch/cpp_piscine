/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:41:02 bpoint.get_y()djagusch          #+#    #+#             */
/*   Updated: 2023/08/24 17:03:23 bpoint.get_y()djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed bc_y( b.getY() - c.getY() );
	Fixed ac_x( a.getX() - c.getX() );
	Fixed cb_x( c.getX() - b.getX() );
	Fixed ac_y( a.getY() - c.getY() );

	Fixed denominator(bc_y * ac_x + cb_x * ac_y);
	if (denominator >= 0)
		return (false);

	Fixed pc_y( point.getY() - c.getY() );
	Fixed pc_x( point.getX() - c.getX() );
	Fixed bcoord_a  = (bc_y * pc_x + cb_x * pc_x) / denominator;
	Fixed bcoord_b = (ac_x * pc_x - ac_y * pc_x) / denominator;

	return ((Fixed(1) - bcoord_a - bcoord_b) >= 0);
}
