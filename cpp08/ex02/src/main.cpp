/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:53:57 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 13:05:57 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <deque>
#include <list>

// For eval: replace iterator with reverse and const iterators

int main()
{
	{
		std::cout << "================= MutantStack ===================" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(737);
		mstack.push(737);
		mstack.push(737);
		mstack.push(737);
		mstack.push(737);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "================= List ===================" << std::endl;
		std::list<int> test_list;
		test_list.push_back(5);
		test_list.push_back(17);
		std::cout << test_list.back() << std::endl; // equivalent to top
		test_list.pop_back();
		std::cout << test_list.size() << std::endl;
		test_list.push_back(3);
		test_list.push_back(5);
		test_list.push_back(737);
		test_list.push_back(737);
		test_list.push_back(737);
		test_list.push_back(737);
		test_list.push_back(737);
		test_list.push_back(737);
		test_list.push_back(737);
		test_list.push_back(0);
		std::list<int>::const_iterator it = test_list.begin();
		std::list<int>::const_iterator ite = test_list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(test_list);
	}

	return 0;
}