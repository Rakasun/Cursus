/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   From.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:48:28 by yfang             #+#    #+#             */
/*   Updated: 2024/10/17 19:16:39 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROM_HPP
# define FROM_HPP

# include "Bureaucrat.hpp"

class From {
    private:
        const std::string   _name;
        bool                _status;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        From(void);
        From(const From &oter);
        From(const std::string &name, int gradeToSign, int gradeToExecute);
        From    &operator=(const From &other);
        ~From(void);
};

#endif
