/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:46:15 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRIAN_HPP
# define BRIAN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	Brain( Brain const &src );
	~Brain();

	Brain &	operator=( Brain const &rhs );

private:
	std::string _ideas[100];

};

#endif