/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:54:31 by yfang             #+#    #+#             */
/*   Updated: 2024/08/28 17:01:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string str) : type(str) {}

Weapon::~Weapon() {
    std::cout << type << " is broken." << std::endl;
}

const   std::string &Weapon::getType() const {
    return type;
}

void    Weapon::setType(std::string newType) {
    type = newType;
}
