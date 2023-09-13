/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:58:49 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/13 08:55:06 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template< typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack ();
	MutantStack( MutantStack const & src );
	virtual ~MutantStack();

	MutantStack &	operator=( MutantStack const & rhs );

	typedef typename Container::iterator				iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator				begin( void );
	iterator				end( void );
	const_iterator			begin( void ) const;
	const_iterator			end( void ) const;
	reverse_iterator		rbegin( void );
	reverse_iterator		rend( void );
	const_reverse_iterator	rbegin( void ) const;
	const_reverse_iterator	rend( void ) const;

private:

};
template< typename T , class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

template< typename T , class Container>
MutantStack<T, Container>::MutantStack( MutantStack<T, Container> const & src ) : std::stack<T, Container>(src)
{
	*this = src;
}

template< typename T , class Container>
MutantStack<T, Container>::~MutantStack()
{}

template< typename T , class Container>
MutantStack<T, Container> &	MutantStack<T, Container>::operator=( MutantStack<T, Container> const & rhs )
{
	if( this != &rhs )
		std::stack<T, Container>::operator=(rhs);
	return (*this);
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin( void )
{
	return std::stack< T, Container>::c.begin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end( void )
{
	return std::stack< T, Container>::c.end();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin( void ) const
{
	return std::stack< T, Container>::c.begin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end( void ) const
{
	return std::stack< T, Container>::c.end();
}

template<typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin( void )
{
	return std::stack< T, Container>::c.rbegin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend( void )
{
	return std::stack< T, Container>::c.rend();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin( void ) const
{
	return std::stack< T, Container>::c.rbegin();
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend( void ) const
{
	return std::stack< T, Container>::c.rend();
}

#endif
