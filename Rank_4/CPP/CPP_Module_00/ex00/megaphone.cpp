/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:02:21 by yfang             #+#    #+#             */
/*   Updated: 2024/07/17 12:05:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < ac; ++i) {
            std::string argument = av[i];
            for (size_t j = 0; j < argument.length(); ++j)
                std::cout << static_cast<char>(toupper(argument[j]));
            if (i < ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}
