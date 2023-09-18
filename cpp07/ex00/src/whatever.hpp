/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:53 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 09:05:02 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void	swap( T &a, T &b )
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template< typename T >
const T &	min( T const &a, T const &b )
{
	return a < b ? a : b;
}

template< typename T >
const T &	max( T const &a, const T &b )
{
	return a > b ? a : b;
}

# endif
