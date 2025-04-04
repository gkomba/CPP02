/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:21:21 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/04 16:15:39 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const int &fixed_number)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = fixed_number << fractional_bits;
}

Fixed::Fixed(const float &fixed_number)
{
    std::cout << "float constructor called" << std::endl;
    fixed_point = roundf(fixed_number);
}

Fixed::Fixed(Fixed const &object)
{
    std::cout << "Copy constructor called" << std::endl;
    fixed_point = object.fixed_point;
}

Fixed   &Fixed::operator=(const Fixed& object)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &object)
    {
        this->fixed_point = object.getRawBits();
    }
    return *(this);
}

int     Fixed::getRawBits(void) const
{
    return (fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

int   Fixed::toInt(void) const
{
    return ((getRawBits() >> fractional_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}