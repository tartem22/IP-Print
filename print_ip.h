#ifndef IP_PRINT_H
#define IP_PRINT_H

/*!
\file
\brief Заголовочный файл с описанием и определнием
 шаблонных функций вывода ip адреса

Данный файл содержит в себе описание и определние
 шаблонных функций вывода ip адреса
*/

#include <type_traits>
#include <iostream>

/*!
Выводит в консоль ip адрес, представленный в виде произвольного
целочисленного типа
\param[in] ip ip адрес, представленный в виде произвольного
целочисленного типа
*/
template <typename T,
          std::enable_if_t<std::is_integral<std::remove_reference_t<T>>::value,
                           bool> = true>
void printIP(T &&ip)
{
    std::string out;
    uint8_t temp = 0;
    for (size_t i = 0; i < sizeof(T); i++)
    {
        temp = (ip >> (8 * i)) & 0xFF;
        out = std::to_string(temp) + out;
        if (i != sizeof(T) - 1)
            out = "." + out;
    }

    std::cout << out << std::endl;
}

/*!
Выводит в консоль ip адрес, представленный в виде строки
\param[in] ip ip адрес, представленный в виде строки
*/
template <typename T,
          std::enable_if_t<std::is_same<std::remove_reference_t<T>,
                                        std::string>::value, bool> = true>
void printIP(T &&ip)
{
    std::cout << ip << std::endl;
}

/*!
Выводит в консоль ip адрес, представленный в виде STL контейнера list или vector
\param[in] ip ip адрес, представленный в виде STL контейнера list или vector
*/
template <typename T, typename A, template <typename, typename> typename Container,
            std::enable_if_t<std::is_same<std::remove_reference_t<Container<T, A>>,
                                        std::vector<T, A>>::value ||
                             std::is_same<std::remove_reference_t<Container<T, A>>,
                                        std::list<T, A>>::value, bool> = true>
void printIP(Container<T, A> container)
{
    std::string out;
    for (auto it = container.begin(); it != container.end();)
    {
        out += std::to_string(*it);
        it++;
        if (it != container.end())
            out = out + ".";
    }

    std::cout << out << std::endl;
}

// template <typename T>
// void printIP(std::tuple<T> ip)
// {
//     std::cout << std::get<0>(ip) << std::endl;
// }

// template <typename T, typename... Tail>
// void printIP(std::tuple<T, Tail...> ip)
// {
//         std::cout << std::get<0>(ip) << ".";
// }

// template<typename T>
// void printIP(std::tuple<T, T, T, T> ip)
// {
//     std::cout << ip.get<0> << "." << std::endl;
//     // printIP(Args...);
// }

#endif