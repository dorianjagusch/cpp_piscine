/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:41:12 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 14:19:05 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & src );
	~ClapTrap();

	ClapTrap &	operator=( ClapTrap const & rhs );

	std::string getName( void ) const;
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

protected:
	std::string	_name;
	long		_health;
	long		_energy;
	long		_damage;

	ClapTrap( void );
	void no_energy( void ) const ;
	void is_dead( void ) const ;
};

#endif