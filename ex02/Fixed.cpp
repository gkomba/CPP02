/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:04:46 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/13 06:12:52 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): rawBits(0) {}

Fixed::Fixed(const int &intValue)
{
    rawBits = intValue << fractionaBits;
}

Fixed::Fixed(const float &floatValue)
{
    rawBits = roundf(floatValue * (1 << fractionaBits));
}

Fixed::Fixed(const Fixed& object)
{
    *this = object;
}

Fixed &Fixed::operator=(const Fixed& object)
{
    if (this != &object)
        this->rawBits = object.rawBits;
    return(*this);
}

int Fixed::getRawBits(void) const
{
    return (rawBits);    
}

void    Fixed::setRawBits(int value)
{
    rawBits = value;
}

int Fixed::toInt(void) const
{
    return (rawBits >> fractionaBits);
}

float Fixed::toFloat(void) const
{
    return (float(rawBits) / (1 << fractionaBits));
}

std::ostream&   operator<<(std::ostream& os, const Fixed& object)
{
    os << object.toFloat();
    return (os);
}

// arithmetic operators
Fixed  Fixed::operator+(const Fixed& object)
{
    Fixed   result;

    result.setRawBits((this->getRawBits() + object.getRawBits()));
    return(result);
}

Fixed   Fixed::operator-(const Fixed&  object)
{
    Fixed   result;

    result.setRawBits((this->getRawBits() - object.getRawBits()));
    return(result);
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed result;

    long temp = static_cast<long>(this->rawBits) * other.rawBits;
    result.setRawBits(static_cast<int>(temp >> this->fractionaBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed result;

    long dividend = static_cast<long>(this->rawBits) << fractionaBits;
    result.setRawBits(static_cast<int>(dividend / other.rawBits));
    return result;
}

bool   Fixed::operator>(const Fixed& other) const
{
    return (this->getRawBits() > other.getRawBits());    
}

bool    Fixed::operator<(const Fixed& other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool    Fixed::operator==(const Fixed& other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed& other) const
{
    return (this->getRawBits() != other.getRawBits());
}

bool    Fixed::operator<=(const Fixed& other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool    Fixed::operator>=(const Fixed& other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed  & Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}
Fixed&  Fixed::operator++()
{
    this->rawBits += 1;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->rawBits += 1;
    return (tmp);
}

Fixed&  Fixed::operator--()
{
    this->rawBits -= 1;
    return (*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed   tmp(*this);
    this->rawBits -= 1;
    return (tmp);
}

Fixed::~Fixed() {}