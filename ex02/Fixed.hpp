/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:05:02 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/13 06:11:06 by gkomba           ###   ########.fr       */
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

        // comparasion opeators
        bool   operator>(const Fixed& object) const;
        bool   operator<(const Fixed& object) const;
        bool   operator==(const Fixed& object) const;
        bool   operator>=(const Fixed& object) const;
        bool   operator<=(const Fixed& object) const;
        bool   operator!=(const Fixed& object) const;

        // increment
        Fixed&  operator++();
        Fixed  operator++(int);
        Fixed&  operator--();
        Fixed  operator--(int);

        // min
        static  Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        
        //max
        static  Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& object);

#endif