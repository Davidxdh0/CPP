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
		BitcoinExchange(std::ifstream& indata, char argv[]);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		std::string						getInput();
		std::map<std::string, double> 	getMap();
		double							getDataValue(std::string date);
		int								datetodecimal(std::string date);
		void							Exchange();
		bool							badInput(const std::string& input);
		void 							makeLine(std::string line);
};

#endif
