/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand->hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student->wethinkcode->co->za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:47:40 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/25 10:47:40 by jwolf            ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "eOperand.hpp"
#include "Factory.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <functional>
#include "Exceptions.hpp"

template <typename T>
T mod(T val1, T val2) {	return val1 % val2; }

template <>
float mod<float>(float val1, float val2) { return std::fmod(val1, val2); }

template <>
double mod<double>(double val1, double val2) { return std::fmod(val1, val2); }

template <typename T>
inline eOperandType getDataType() {	return eOperandType::UNDEFINED; }

template <>
inline eOperandType getDataType<int8_t>() { return eOperandType::INT8; }

template <>
inline eOperandType getDataType<int16_t>() { return eOperandType::INT16; }

template <>
inline eOperandType getDataType<int32_t>() { return eOperandType::INT32; }

template <>
inline eOperandType getDataType<float>() { return eOperandType::FLOAT; }

template <>
inline eOperandType getDataType<double>() { return eOperandType::DOUBLE; }

template<typename T>
class Operand: public IOperand
{
	public:
		Operand(){ this->val = 0;}
		Operand(const Operand& rhs) {*this = rhs;}
		~Operand(){}
		Operand &operator=(Operand const& rhs){ if (this != &rhs) *this = rhs; return *this;}
		Operand(std::string value)
		{
			eOperandType t = getDataType<T>();
			int32_t temp = std::stoi(value);
			switch (t)
			{
				default:
					break;
				case eOperandType::INT32:
				case eOperandType::INT16:
				case eOperandType::INT8:
					this->val = static_cast<int32_t>(temp);
					if (static_cast<int32_t>(this->val) != temp)
						throw Exceptions::OutOfRange((temp > this->val) ? "Overflow :(" : "Underflow :(");
					break;
				case eOperandType::FLOAT:
					this->val = std::stof(value);
					break;
				case eOperandType::DOUBLE:
					this->val = std::stof(value);
					break;
			}
			strVal = std::to_string(this->val);
		}
		virtual int		getPrecision(void) const
		{
			return static_cast<int>(getType());
		}
		virtual eOperandType getType(void) const
		{
			return getDataType<T>();
		}
		virtual IOperand const *operator+(IOperand const& rhs) const
		{
			std::string v;
			eOperandType t = rhs.getType() > getType() ? rhs.getType() : getType();
			Factory		f;
			switch (t)
			{
				case eOperandType::INT32:
				case eOperandType::INT16:
				case eOperandType::INT8:
					v = std::to_string(this->val + std::stoi(rhs.toString()));
					break;
				case eOperandType::FLOAT:
					v = std::to_string(this->val + std::stof(rhs.toString()));
					break;
				case eOperandType::DOUBLE:
					v = std::to_string(this->val + std::stod(rhs.toString()));
					break;
				default:
					break;
			}
			return f.getOperator(t, v);
		}
		virtual IOperand const *operator-(IOperand const& rhs) const
		{
			std::string v;
			eOperandType t = rhs.getType() > getType() ? rhs.getType() : getType();
			Factory		f;
			switch (t)
			{
				case eOperandType::INT32:
				case eOperandType::INT16:
				case eOperandType::INT8:
					v = std::to_string(this->val - std::stoi(rhs.toString()));
					break;
				case eOperandType::FLOAT:
					v = std::to_string(this->val - std::stof(rhs.toString()));
					break;
				case eOperandType::DOUBLE:
					v = std::to_string(this->val - std::stod(rhs.toString()));
					break;
				default:
					break;
			}
			return f.getOperator(t, v);
		}
		virtual IOperand const *operator*(IOperand const& rhs) const
		{
			if (rhs.getPrecision() > this->getPrecision())
				return (rhs * *this);
			std::string v;
			eOperandType t = rhs.getType() > getType() ? rhs.getType() : getType();
			Factory		f;
			Operand<T> temp(rhs.toString());
			T tVal = temp.val * this->val;
			return f.getOperator(t, std::to_string(tVal));
		}
		virtual IOperand const *operator/(IOperand const& rhs) const
		{
			std::string v;
			eOperandType t = rhs.getType() > this->getType() ? rhs.getType() : this->getType();
			int32_t op1 = std::stoi(rhs.toString());
			float op2 = std::stof(rhs.toString());
			double op3 = std::stod(rhs.toString());
			Factory		f;
			switch (t)
			{
				case eOperandType::INT32:
				case eOperandType::INT16:
				case eOperandType::INT8:
					if (op1 == 0)
						throw Exceptions::DivByZero();
					v = std::to_string(this->val / op1);
					break;
				case eOperandType::FLOAT:
					if (op2 == 0)
						throw Exceptions::DivByZero();
					v = std::to_string(this->val / op2);
					break;
				case eOperandType::DOUBLE:
					if (op3 == 0)
						throw Exceptions::DivByZero();
					v = std::to_string(this->val / op3);
					break;
				default:
					break;
			}
			return f.getOperator(t, v);
		}
		virtual IOperand const *operator%(IOperand const& rhs) const
		{
			std::string v;
			eOperandType t = rhs.getType() > this->getType() ? rhs.getType() : this->getType();
			int32_t op1 = std::stoi(rhs.toString());
			float op2 = std::stof(rhs.toString());
			double op3 = std::stod(rhs.toString());
			Factory		f;
			switch (t)
			{
				case eOperandType::INT32:
				case eOperandType::INT16:
				case eOperandType::INT8:
					if (op1 == 0)
						throw Exceptions::ModByZero();
					v = std::to_string(mod<int32_t>(this->val, op1));
					break;
				case eOperandType::FLOAT:
					if (op2 == 0)
						throw Exceptions::ModByZero();
					v = std::to_string(mod<float>(this->val, op2));
					break;
				case eOperandType::DOUBLE:
					if (op3 == 0)
						throw Exceptions::ModByZero();
					v = std::to_string(mod<double>(this->val, op3));
					break;
				default:
					break;
			}
			return f.getOperator(t, v);
		}
		Operand &operator=(IOperand const& rhs) const
		{
			if (this != &rhs) 
				*this = rhs;
			return *this;
		}
		virtual std::string const & toString(void) const { return strVal; }
	private:
		std::string strVal;
		T val;
};