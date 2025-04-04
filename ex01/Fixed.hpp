/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:20:56 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/04 16:36:03 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int rawBits;
        const static int fractionalBits = 8;

    public:
        Fixed(void);
        Fixed(const int &intValue);
        Fixed(const float &floatValue);
        Fixed(Fixed const &object);
        Fixed& operator=(const Fixed& object);
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        ~Fixed();
};
