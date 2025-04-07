/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:39:29 by yfang             #+#    #+#             */
/*   Updated: 2025/04/07 17:42:33 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN \"expresion\"" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        int result = rpn.evaluate(av[1]);
        std::cout << result << std::endl;
    } catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
