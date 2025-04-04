/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:20:56 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/04 16:17:25 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
    private:
        int fixed_point;
        const static int fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(Fixed const &object);
        Fixed& operator=(const Fixed& object);
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        ~Fixed();
};
