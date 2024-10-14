/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:38:18 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 14:34:28 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog(void);
        Dog(const Dog &other);
        Dog     &operator=(const Dog &other);
        virtual ~Dog(void);

        virtual void    makeSound(void) const;
};

#endif
