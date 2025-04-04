/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:20:56 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/04 16:15:49 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        const static int fractional_bits = 8;

    public:
        Fixed(void);
        Fixed(const int &fixed_number);
        Fixed(const float &fixed_number);
        Fixed(Fixed const &object);
        Fixed& operator=(const Fixed& object);
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        ~Fixed();
};
