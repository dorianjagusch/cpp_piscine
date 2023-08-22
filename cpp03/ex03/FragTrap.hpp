/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:00:39 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 23:27:00 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	~FragTrap( void );
	void		HighFiveGuys( void );

	FragTrap &	operator=( FragTrap const & rhs );
protected:
	FragTrap( void );
};

#endif
