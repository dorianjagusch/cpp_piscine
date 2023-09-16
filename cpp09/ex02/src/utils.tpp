/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:53:49 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/16 13:12:33 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TPP
# define UTILS_TPP

# include <iostream>

template <typename Container>
void printContainer(const Container& c) {
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
template <typename Container>
void printResult(Container container, double duration, int id){
	static const std::string args[2] = {
		"vector",
		"list"
	};
	
	std::cout << "Time to process a range of " 
		<< container.size() << " elements with std::"<< args[id] << "<int>: "
		<< duration << " us" <<  std::endl;
}

#endif