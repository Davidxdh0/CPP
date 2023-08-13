#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <cmath>

class BitcoinExchange {
	private:
		std::map<std::string, double> 	_Map;
		std::string						_input;
	public:
		BitcoinExchange();
		BitcoinExchange(int argc, char *argv[]);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		std::string						getInput();
		std::map<std::string, double> 	getMap();
		int								getDataValue(std::string date);
		void 							getListValue();
		int								datetodecimal(std::string date);
		void							Exchange();
};

#endif
