#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _Map(), _input("") {}

BitcoinExchange::BitcoinExchange(int argc, char *argv[]) {
	if (argc != 2 || argv[1] == NULL)
		throw std::runtime_error("Error: argc, argv");
	_input = argv[1];
	std::ifstream indata("data.csv");
	if (!indata.is_open())
		throw std::runtime_error("Can't open 'data.csv'");
	std::string line;
	bool firstline = 1;
	while(getline(indata, line)){
		if (firstline){
			firstline = 0;
			continue;
		}	
		size_t comma = line.find(',');
		if (comma != std::string::npos){
			std::string date = line.substr(0, comma);
        	std::string valuestr = line.substr(comma + 1);
        	double value = std::stod(valuestr);
        	_Map.insert({date, value});
		}
	}
	// for(auto itr = _Map.begin(); itr != _Map.end(); itr++){
	// 	std::cout << itr->second << '\n';
	// }
	// std::cout << std::endl;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _Map(other._Map), _input(other._input) {};

BitcoinExchange& BitcoinExchange::BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other){
		this->_Map = other._Map;
		this->_input = other._input;
	}
	return *this;
};
BitcoinExchange::~BitcoinExchange(){};

int	BitcoinExchange::datetodecimal(std::string date){
	size_t first = date.find('-');
	size_t second = date.find('-', first + 1);
	
	if (first != std::string::npos && second != std::string::npos){
		int year = std::stoi(date.substr(0, first));
		int month = std::stoi(date.substr(first + 1, second - first - 1));
		int day = std::stoi(date.substr(second + 1));
		if (year > 2008 && year < 2100 && month >= 0 && month <= 12 && day >= 0 && day <= 31) {
			 return year * 10000 + month * 100 + day;
		}
	}
	return -1;
}

int	BitcoinExchange::getDataValue(std::string date){
	if (datetodecimal(date) == -1){
		return -1;
	}
	auto pos = _Map.find(date);
	if (pos != _Map.end()){
		return (pos->second);
	}
	auto lower = _Map.lower_bound(date);
	auto higher = _Map.upper_bound(date);
	if (lower != _Map.begin())
		lower--;
	int decdate 	= datetodecimal(date);
	int declower 	= datetodecimal(lower->first);
	int dechigher 	= datetodecimal(higher->first);
	int difflow 	= std::abs(decdate-declower);
	int diffhigh 	= std::abs(decdate-dechigher);
	return (difflow <= diffhigh ? lower->second : higher->second);
}

void BitcoinExchange::getListValue(){
	if (_input.empty())
		throw std::runtime_error("Error: argv is empty");
	std::ifstream indata(_input);
	if (!indata.is_open())
		throw std::runtime_error("Can't open input");
	std::string line;
	bool firstline = 1;
	while(getline(indata, line)){
		if (firstline){
			firstline = 0;
			continue;
		}	
		try {
				size_t pipe = line.find('|');
				if (pipe != std::string::npos){
					std::string date = line.substr(0, pipe);
					std::string valuestr = line.substr(pipe + 1);
					double datavalue = getDataValue(date);
					if (datavalue < 0 || valuestr.empty() || pipe == std::string::npos){
						std::string errormessage = "Error: bad input => " + date;
						throw std::runtime_error(errormessage);
					}
					std::cout << "valuestr = " << valuestr << std::endl;
					double value = std::stod(valuestr);
					if (value < 0)
						throw std::invalid_argument("Error: not a positive number.");
					if (value > 1000)
						throw std::invalid_argument("Error: too large number.");
					double result = datavalue * value;
					std::cout << date << " => " << value << " = " << result << std::endl;
				}
			}
			catch (std::runtime_error& e){
				std::cerr << e.what() << std::endl;
			} catch(std::out_of_range& e) {
				std::cerr << e.what() << std::endl;
			} catch (std::invalid_argument& e){
				std::cerr << e.what() << std::endl;
			}  catch (...) {
            std::cerr << "Error: unknown." << std::endl;
        }
		}
}
	// for(auto itr = _Map.begin(); itr != _Map.end(); itr++){
	// 	std::cout << itr->second << '\n';
	// }
	// std::cout << std::endl;

std::map<std::string, double>  BitcoinExchange::getMap(){
	return (_Map);
}

std::string	BitcoinExchange::getInput(){
	return this->_input;
}