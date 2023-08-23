/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:15:29 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 21:43:00 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
public:
	MateriaSource ();
	MateriaSource( MateriaSource const & src );
	~MateriaSource();

	MateriaSource &	operator=( MateriaSource const & rhs );

private:

};

#endif