/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:02:59 by yfang             #+#    #+#             */
/*   Updated: 2025/03/26 18:54:06 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    try {
        btc.loadDatabase("data.csv");
        btc.processInputFile(av[1]);
    } catch (const std::runtime_error &e) {
        std::cout << "Caught execption: " << e.what() << std::endl;
    }
    return 0;
}
