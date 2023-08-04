/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 14:40:56 by dyeboa        #+#    #+#                 */
/*   Updated: 2023/06/18 21:34:21 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc;) {
		std::string str = argv[i];
		for (std::size_t p = 0; p < str.size(); ++p) {
			char& c = str[p];
			c = std::toupper(c);
		}
		std::cout << str;
		i++;
		if (i < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
    return (argc);
}
