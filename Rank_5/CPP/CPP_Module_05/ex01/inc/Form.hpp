/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:48:28 by yfang             #+#    #+#             */
/*   Updated: 2024/12/02 18:26:02 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   _name;
        bool                _status;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        Form(void);
        Form(const Form &oter);
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form    &operator=(const Form &other);
        ~Form(void);

        std::string getName(void) const;
        bool        getStatus(void) const;
        int         getSignGrade(void) const;
        int         getExecGrade(void) const;

        bool        beSigned(Bureaucrat const &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char  *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char  *what() const throw();
        };
};
std::ostream    &operator<<(std::ostream &out, const Form &f);

#endif
