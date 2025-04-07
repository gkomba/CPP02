/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:05:02 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/06 15:53:52 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int rawBits;
        static const int fractionaBits = 8;
        
    public:
        Fixed();
        Fixed(const int &intValue);
        Fixed(const float &floatValue);
        Fixed(const Fixed& object);
        Fixed&   operator=(const Fixed& object);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;

        // arithmetic operators
        Fixed   operator+(const Fixed& object);
        Fixed   operator-(const Fixed& object);
        Fixed   operator*(const Fixed& object);
        Fixed   operator/(const Fixed& object);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& object);

#endif