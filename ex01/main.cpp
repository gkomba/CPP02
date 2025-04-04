/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <gkomba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:21:35 by gkomba            #+#    #+#             */
/*   Updated: 2025/04/04 16:42:18 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a(8.75f);
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << "a: " << a.toFloat() << std::endl;
    std::cout << "b: " << b.toFloat() << std::endl;
    std::cout << "c: " << c.toFloat() << std::endl;
    return 0;
}