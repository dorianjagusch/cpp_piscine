/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:00:39 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 23:25:10 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const & src );
	~DiamondTrap( void );
	void		attack(const std::string& target);
	void		whoAmI( void ) const;

	DiamondTrap &	operator=( DiamondTrap const & rhs );
private:
	DiamondTrap( void );
	std::string _name;
};

#endif