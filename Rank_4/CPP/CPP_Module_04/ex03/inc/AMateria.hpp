/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:23:23 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 18:32:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

class ICharacter;

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria(void);
        AMateria(const std::string &type);
        AMateria(const AMateria &other);
        AMateria    &operator=(const AMateria &other);
        virtual     ~AMateria(void);

        const std::string   &getType(void) const;
        virtual AMateria    *clone(void) const = 0;
        virtual void        use(ICharacter &target) = 0;
};

#endif
