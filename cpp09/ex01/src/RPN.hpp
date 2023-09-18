/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:11:44 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 14:17:49 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <cstdlib>
# include <algorithm>
# include <exception>
# include <limits>

class RPN
{
public:
	class OverflowException : public std::exception{
		char const * what( void ) const throw();
	};
	class DivideByZeroException : public std::exception{
		char const * what( void ) const throw();
	};
	RPN ();
	RPN( RPN const & src );
	~RPN();

	RPN &	operator=( RPN const & rhs );
	static void			DoTheThing( std::string expr );

private:
	static std::stack<long>	_stack;

	static void			CheckCharacters( std::string & expr );
	static bool			CheckArgument( std::string const expr );
	static std::string*	split( const std::string& str, size_t num );
	static void			ClearAllocs( std::string* split_expr );
	static bool			isoperation( char const c );
	static bool			isoperation( std::string const str );
	static bool			isLongOverflow( std::string const & str);
	static size_t		count_words( std::string str );
	static void			calcResult( std::string *split_expr, size_t num);
	static void			do_op( char op );
	static long long	add( long long const a, long long const b ) throw ( OverflowException ) ;
	static long long	sub( long long const a, long long const b ) throw ( OverflowException ) ;
	static long long	mult( long long const a, long long const b ) throw ( OverflowException ) ;
	static long long	div( long long const a, long long const b ) throw ( DivideByZeroException ) ;
};

#endif