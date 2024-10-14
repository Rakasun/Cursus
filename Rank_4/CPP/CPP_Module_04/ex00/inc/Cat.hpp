/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:01 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 14:34:36 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat(void);
        Cat(const Cat &other);
        Cat     &operator=(const Cat &other);
        virtual ~Cat(void);

        virtual void    makeSound(void) const;
};

#endif
