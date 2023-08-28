/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:27 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
public:
	Data( std::string name, unsigned int id, unsigned int age, std::string occupation );
	~Data();
	Data( Data const &src );
	Data &	operator=( Data const &rhs );

private:
	Data ();

	std::string	_name;
	unsigned int	_id;
	unsigned int	_age;
	std::string	_occupation;
};

#endif