/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:56:17 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/05 14:49:33 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstring>

template< typename T>
class Array
{
public:
	class OutOfBoundsException : public std::exception{
		public:
			virtual const char *what( void ) const throw() {
				return "Out of bounds";
			};
	};

	Array();
	Array(unsigned int const &n);
	Array( Array const &src );
	~Array();

	Array			&operator=( Array const &rhs );
	T				&operator[]( unsigned int n ) const  throw(OutOfBoundsException);
	unsigned int	size( void ) const;
private:
	T				*_array;
	unsigned int	_size;
};

template< typename T>
Array<T>::Array() : _array( new T[0] ), _size(0)
{}

template< typename T>
Array<T>::Array( unsigned int const &n )
{
	_size = n;
	_array = new T[n];
	return ;
}

template< typename T>
Array<T>::Array( Array const &src )
{
	_size = src._size;
	_array = new T[_size];
	for ( unsigned int i = 0; i < src._size; i++ ){
		_array[i] = src._array[i];
	}
}

template< typename T>
Array<T>::~Array()
{
	if (_array)
		delete [] _array;
}

template< typename T>
Array<T> &Array<T>::operator=( Array<T> const &rhs )
{
	if( this != &rhs ){
		if (_array)
			delete [] _array;
		_array = new T[rhs._size];
		for ( unsigned int i = 0; i < rhs._size; i++ ){
			_array[i] = rhs._array[i];
		}
		_size = rhs._size;
	}
	return *this;
}

template< typename T>
T &Array<T>::operator[]( unsigned int n ) const throw(OutOfBoundsException)
{
	if ( n >= _size )
		throw( OutOfBoundsException() );
	return _array[n] ;
}

template<class T>
unsigned int Array<T>::size( void ) const
{
	return _size ;
}

template<typename T>
std::ostream &	operator<<( std::ostream & o, Array<T> const &rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++){
		if ( i != rhs.size() - 1 )
			o << rhs[i] << " ";
		else
			o << rhs[i];
	}
	return o;
}

#endif