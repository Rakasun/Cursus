/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:13:39 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 16:12:47 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include "Ice.hpp"

class Cure : public AMateria {
    public:
        Cure(void);
        Cure(const Cure &other);
        Cure    &operator=(const Cure &other);
        ~Cure(void);

        AMateria    *clone(void) const;
        void        use(ICharacter &target);

};

#endif
