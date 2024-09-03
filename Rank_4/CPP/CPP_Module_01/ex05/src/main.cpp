/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:50:09 by yfang             #+#    #+#             */
/*   Updated: 2024/09/03 17:19:58 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int ac, char **av) {
    if (ac == 2) {
        Harl        harl;
        std::string level = av[1];

        harl.complain(level);
    }
    else
        std::cout << "Error: bad number of arguments." << std::endl;
    return 0;
}
