/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:13:56 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++){
		_learned[i] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const &src )
{
	*this = src;
	for (int i = 0; i < 4; i++){
		_learned[i] = src._learned[i];
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++){
		if (_learned[i])
			delete _learned[i];
	}
}

MateriaSource &	MateriaSource::operator=( MateriaSource const &rhs )
{
	if ( this != &rhs ){
		for (int i = 0; i < 4; i++){
			if (_learned[i])
				delete _learned[i];
			_learned[i] = rhs._learned[i];
		// I decided to not transfer the unequipped materials as they are not accessible
		// to anything or anyone and would thus needlessly consume spac
		// if were to make them identical
		}
	}
	return (*this);
}

void MateriaSource::learnMateria( AMateria* materia )
{
	for ( int i = 0; i < 4; i++){
		if (!_learned[i]){
			_learned[i] = materia;
			return ;
		}
	}
	std::cout << "This materia source cannot learn any more Materias" << std::endl;
}

AMateria* MateriaSource::createMateria( std::string const &type )
{
	for ( int i = 0; i < 4; i++){
		if (_learned[i] != NULL && _learned[i]->getType() == type){
			// std::cout << "Materia source created " << type << std::endl;
			return (_learned[i]->clone());
		}
	}
	std::cout << "This materia source does not know " << type << std::endl;
	return (NULL);
}