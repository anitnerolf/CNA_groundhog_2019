/*
** EPITECH PROJECT, 2020
** groundhog
** File description:
** cpp
*/

#include "../include/Groundhog.hpp"
#include <algorithm>
#include <iomanip>
#include <cmath>

Groundhog::Groundhog()
{
    this->end = 0;
    this->switches = 0;
    this->it = 0;
    this->triple_nan = "g=nan\tr=nan%\ts=nan";
    this->double_nan = "g=nan\tr=nan%\ts=";
    this->check_switch = 0.0;
}

Groundhog::~Groundhog()
{
}

void	Groundhog::usage(void)
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "\t./groundhog period" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl << "\tperiod\t\tthe number of days defining a period" << std::endl;
}

int	Groundhog::check_if_number(std::string str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] <= 57 && str[i] >= 48))
            return (1);
        else
            return (-1);
        i++;
    }
    return 0;
}

std::vector<double>	Groundhog::string_to_double(std::vector<std::string> list)
{
    std::vector<double> vect;
    std::for_each(list.begin(), list.end(), [&vect](const std::string &element) {
            vect.push_back(stod(element));
        });
    return (vect);
}

int	Groundhog::check_if_float_number(std::string str)
{
    int count = 0;
    int number = 0;

    if (str.find('.') != std::string::npos) {
        for (int i = 0; i < str.length(); i++) {
            if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.') {
                if (str[i] == '.') {
                    count++;
                }
            } else
                return 84;
        }
        if (count != 1)
            return 84;
    } else {
        return 84;
    }
    return 0;
}

double	Groundhog::calculate_r(int period, std::vector<std::string> list)
{
    std::vector<double> list_double = this->string_to_double(list);
    double result = (((list_double.back() - list_double.front()) / list_double.front()) * 100);
    return (round(result));
}

double	Groundhog::calculate_standard_deviation(int period, std::vector<std::string> list)
{
    double result = 0.0;
    std::vector<double> list_double = this->string_to_double(list);
    auto j = list_double.end() - 1;
    while (j >= list_double.end() - period) {
        result = result + *j;
        j--;
    }
    return (result);
}

double	Groundhog::calculate_s(int period, std::vector<std::string> list)
{
    std::vector<double> list_double = this->string_to_double(list);
    double result = 0.0;
    double value = 0.0;
    double standard_deviation = 0.0;
    auto j = list_double.end() - 1;
    while (j >= list_double.end() - period) {
        result = result + powf(*j, 2);
        j--;
    }
    value = result / period;
    standard_deviation = (value - (pow(this->calculate_standard_deviation(period, list) / period, 2)));
    return (sqrtf(standard_deviation));
}

void	Groundhog::check_iterations_cases(int it, int period, std::vector<std::string> list)
{
    const int first_case = period - 1;
    if (it == 0 || it < first_case)
        std::cout << this->triple_nan << std::endl;
    else if (it == first_case)
        std::cout << this->double_nan << std::fixed << std::setprecision(2) << this->calculate_s(period, list) << std::endl;
    else {
        if ((this->check_switch >= 0 && this->calculate_r(period, list) >= 0) || (this->check_switch < 0 && this->calculate_r(period, list) < 0))
            std::cout << "g=" << std::fixed << std::setprecision(2) << this->calculate_g(list) << "\tr=" << std::fixed << std::setprecision(0) << this->calculate_r(period, list) << "%\ts=" << std::fixed << std::setprecision(2) << this->calculate_s(period, list) << std::endl;
        else {
            this->switches++;
            std::cout << "g=" << std::fixed << std::setprecision(2) << this->calculate_g(list) << "\tr=" << std::fixed << std::setprecision(0) << this->calculate_r(period, list) << "%\ts=" << std::fixed << std::setprecision(2) << this->calculate_s(period, list) << "\ta switch occurs" << std::endl;
        }
    }
}

void	Groundhog::stop(int period)
{
    if (this->it < period)
        exit(84);
    else {
        std::cout << "Global tendency switched " << this->switches << " times" << std::endl;
        exit(0);
    }
}

double	Groundhog::calculate_g(std::vector<std::string> list)
{
    int size = list.size();
    double result = 0.0;
    double difference = 0.0;
    double final_result = 0.0;
    unsigned int i = 0;
    std::vector<double> list_double = this->string_to_double(list);
    while (i < size - 1) {
        difference = ((list_double[i + 1] - list_double[i]) < 0) ? 0 : list_double[i + 1] - list_double[i];
        result = result + difference;
        i++;
    }
    final_result = result / (size - 1);
    return (final_result);
}
void	Groundhog::loop(int period, std::vector<std::string> list)
{
    std::string input("");
    while (!this->end && std::getline(std::cin, input)) {
        if (input.compare("") == 0)
            continue;
        if (input == "STOP") {
            this->end++;
        }
        if (input.empty() || this->check_if_number(input) == -1)
            continue;
        list.push_back(input);
        this->check_iterations_cases(this->it, period, list);
        if (this->it > period - 1) {
            this->check_switch = this->calculate_r(period, list);
            list.erase(list.begin());
        }
        this->it++;
    }
    this->stop(period);
}
