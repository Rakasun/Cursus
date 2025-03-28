/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:54:27 by yfang             #+#    #+#             */
/*   Updated: 2024/09/03 18:03:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now."
    << std::endl;
}

void    Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
    << std::endl;
}

void    Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
    << std::endl;
}

void    Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
    << std::endl;
}

void    Harl::complain(std::string level) {
    function    func[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         i = 0;

    while (i < 4 && levels[i].compare(level))
        i++;
    switch (i) {
        case 0:
            while (i < 4)
                (this->*func[i++])();
            break;
        case 1:
            while (i < 4)
                (this->*func[i++])();
            break;
        case 2:
            (this->*func[2])();
            (this->*func[3])();
            break;
        case 3:
            (this->*func[3])();
            break;
        default:
            std::cout << "Invalid comment." << std::endl;
            break;
    }
}
