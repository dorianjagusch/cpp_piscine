/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:11:44 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/14 13:18:59 by djagusch         ###   ########.fr       */
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

class RPN
{
public:
	class OverflowException : public std::exception{
		char const * what( void ) const throw(){
			return ("Exception: Result overflowed long type");
		}
	};
	class DivideByZeroException : public std::exception{
		char const * what( void ) const throw(){
			return ("Exception: Division by zero");
		}
	};
	RPN ();
	RPN( RPN const & src );
	~RPN();

	RPN &	operator=( RPN const & rhs );
	static void			DoTheThing( std::string expr );

private:
	static std::stack<long>	_stack;
	static std::string*	split( const std::string& str, size_t num );
	static bool			isoperation( char const c );
	static size_t		count_words( std::string str );
	static void			calcResult( std::string *split_expr, size_t num);
	static void			do_op( char op );
	static long long	add( long long const a, long long const b ) throw ( OverflowException ) ;
	static long long	sub( long long const a, long long const b ) throw ( OverflowException ) ;
	static long long	mult( long long const a, long long const b ) throw ( OverflowException ) ;
	static long long	div( long long const a, long long const b ) throw ( DivideByZeroException ) ;
};

#endif