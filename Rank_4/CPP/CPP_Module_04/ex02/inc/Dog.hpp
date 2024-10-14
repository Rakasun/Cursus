/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:38:18 by yfang             #+#    #+#             */
/*   Updated: 2024/10/07 11:41:14 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Brain.hpp"

class Dog: public AAnimal {
    private:
        Brain   *_brain;
    public:
        Dog(void);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual ~Dog(void);

        virtual void    makeSound(void) const;
};

#endif
