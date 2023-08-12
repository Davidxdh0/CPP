#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <random>

class BitcoinExchange {
	private:
		unsigned int 	_N;
		std::map<int> 	_Map;
	public:
		BitcoinExchange();
		BitcoinExchange(unsigned int N);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		int				getDataValue(int i);
		int 			getListValue(int low, int high);

		std::map<int>  	getVect();
};

#endif
