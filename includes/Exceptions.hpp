/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 07:50:42 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/26 10:29:04 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

class Exceptions
{
	public:
	Exceptions(void);
	Exceptions(const Exceptions&);
	~Exceptions(void);
	Exceptions &operator=(const Exceptions&);
	class OutOfRange : public std::exception
	{
		public:
			OutOfRange(void);
			OutOfRange(std::string);
			OutOfRange(const OutOfRange&);
			virtual ~OutOfRange(void) throw();
			OutOfRange  &operator= (const OutOfRange&);
			virtual const char    *what() const throw();
		private:
			std::string reason;
	};

	class ModByZero : public std::exception
	{
		public:
			ModByZero(void);
			ModByZero(const ModByZero&);
			virtual ~ModByZero(void) throw();
			ModByZero  &operator= (const ModByZero&);
			virtual const char    *what() const throw();
	};

	class DivByZero : public std::exception
	{
		public:
			DivByZero(void);
			DivByZero(const DivByZero&);
			virtual ~DivByZero(void) throw();
			DivByZero  &operator= (const DivByZero&);
			virtual const char    *what() const throw();
	};

	class StackToSmall : public std::exception
	{
		public:
			StackToSmall(void);
			StackToSmall(const StackToSmall&);
			virtual ~StackToSmall(void) throw();
			StackToSmall  &operator= (const StackToSmall&);
			virtual const char    *what() const throw();
	};

	class AssertFailed : public std::exception
	{
		public:
			AssertFailed(void);
			AssertFailed(const AssertFailed&);
			virtual ~AssertFailed(void) throw();
			AssertFailed  &operator= (const AssertFailed&);
			virtual const char    *what() const throw();
	};

	class EmptyStack : public std::exception
	{
		public:
			EmptyStack(void);
			EmptyStack(const EmptyStack&);
			virtual ~EmptyStack(void) throw();
			EmptyStack  &operator=(const EmptyStack&);
			virtual const char    *what() const throw();
	};

	class UnknownCommand : public std::exception
	{
		public:
			UnknownCommand(void);
			UnknownCommand(const UnknownCommand&);
			virtual ~UnknownCommand(void) throw();
			UnknownCommand  &operator= (const UnknownCommand&);
			virtual const char    *what() const throw();
	};

	class UnknownDataType : public std::exception
	{
		public:
			UnknownDataType(void);
			UnknownDataType(const UnknownDataType&);
			virtual ~UnknownDataType(void) throw();
			UnknownDataType  &operator= (const UnknownDataType&);
			virtual const char    *what() const throw();
	};
	
	class NoTokens: public std::exception
	{
		public:
			NoTokens(void);
			NoTokens(const NoTokens&);
			virtual ~NoTokens(void) throw();
			NoTokens &operator=(const NoTokens&);
			virtual const char	*what() const throw();
	};
};

