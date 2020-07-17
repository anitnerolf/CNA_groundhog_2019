//
// EPITECH PROJECT, 2020
// asdfg
// File description:
// sdfg
//

#include "../include/Groundhog.hpp"

int	main(int ac, char **av)
{
    Groundhog groundhog;
    std::vector<std::string> list;
    if (ac == 2) {
	if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
	    groundhog.usage();
	else {
	    if (groundhog.check_if_number(av[1]) == -1) {
		std::cerr << "Argument must be a number!" << std::endl;
		exit(84);
	    } else
                groundhog.loop(atoi(av[1]), list);
	}
    } else {
	std::cerr << "Wrong number of arguments!" << std::endl;
	exit(84);
    }
    return (0);
}
