/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:55:30 by yfang             #+#    #+#             */
/*   Updated: 2024/10/16 19:09:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

int main(void) {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    /* IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Cure());

    AMateria *tmp;
    tmp = src->createMateria("fire");
    
    ICharacter* me = new Character("me");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(5, *bob);
    me->use(-1, *bob);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(4);
    me->unequip(-1);
    me->unequip(0);

    delete bob;
    delete me;
    delete src; */


    return 0;
}
