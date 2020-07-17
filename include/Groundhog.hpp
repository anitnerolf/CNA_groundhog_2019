/*
** EPITECH PROJECT, 2020
** asdvb
** File description:
** sdfb
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <iostream>
#include <vector>

class Groundhog
{
public:
    Groundhog();
    ~Groundhog();
    void usage(void);
    int check_if_number(std::string str);
    int check_if_float_number(std::string str);
    void	loop(int period, std::vector<std::string> list);
    void	stop(int period);
    void	check_iterations_cases(int it, int period, std::vector<std::string> list);
    double	calculate_g(std::vector<std::string> list);
    double	calculate_r(int period, std::vector<std::string> list);
    double	calculate_s(int period, std::vector<std::string> list);
    double	calculate_standard_deviation(int period, std::vector<std::string> list);
    std::vector<double>	string_to_double(std::vector<std::string> list);
private:
    int end;
    int switches;
    std::string triple_nan;
    std::string double_nan;
    int it = 0;
    double check_switch;
};

#endif /* GROUNDHOG_HPP_ */
