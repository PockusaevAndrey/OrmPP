//
// Created by pokys on 25.05.2022.
//

#ifndef orm_ERRORS_HPP
#define orm_ERRORS_HPP

#include <exception>
#include <string>

namespace orm {
    class InvalidColumn : public std::exception {
        [[nodiscard]] const char *what() const noexcept override;
    };

    class InvalidQuery : public std::exception {
        [[nodiscard]] const char *what() const noexcept override;
    };

    class TypeMismatch : public std::exception {
        std::string column, result;
    public:
        TypeMismatch(std::string column);
        [[nodiscard]] const char *what() const noexcept override;
    };

}


#endif //orm_ERRORS_HPP
