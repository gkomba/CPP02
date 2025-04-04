/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:21:21 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/04 16:43:49 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    rawBits = 0;
}

Fixed::Fixed(const int &intValue)
{
    std::cout << "Int constructor called" << std::endl;
    rawBits = intValue << fractionalBits;
}

Fixed::Fixed(const float &floatValue)
{
    std::cout << "float constructor called" << std::endl;
    // rawBits=floatvalue×2^fractionalBits
    rawBits = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &object)
{
    std::cout << "Copy constructor called" << std::endl;
    rawBits = object.rawBits;
}

Fixed   &Fixed::operator=(const Fixed& object)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &object)
    {
        this->rawBits = object.getRawBits();
    }
    return *(this);
}

int     Fixed::getRawBits(void) const
{
    return (rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    rawBits = raw;
}

int   Fixed::toInt(void) const
{
    return ((getRawBits() >> fractionalBits));
}

float   Fixed::toFloat(void)  const
{
    return (float)getRawBits() / (1 << fractionalBits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}