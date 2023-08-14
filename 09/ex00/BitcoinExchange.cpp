#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _Map(), _input("") {}

BitcoinExchange::BitcoinExchange(std::ifstream& indata, char argv[]) {
	_input = argv;
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

double	BitcoinExchange::getDataValue(std::string date){
	if (datetodecimal(date) == -1)
		return -1;
	auto pos = _Map.find(date);
	if (pos != _Map.end())
		return (pos->second);
	auto lower = _Map.lower_bound(date);
	if (lower != _Map.begin())
		lower--;
	return (lower->second);
}



void BitcoinExchange::Exchange(){
	if (_input.empty())
		throw std::runtime_error("Error: argv is empty");
	std::ifstream indata(_input);
	if (!indata.is_open())
		throw std::runtime_error("Can't open input");
	std::string line;
	bool firstline = 1;
	while(getline(indata, line)){
		if (line == "date | value" && firstline){
			firstline = 0;
			continue;
		}	
		try {
				makeLine(line);
			}
			catch (std::runtime_error& e){
				std::cerr << e.what() << std::endl;
			} catch (std::out_of_range& e) {
				std::cerr << e.what() << std::endl;
			} catch (std::invalid_argument& e){
				std::cout << "Error: bad input => " + line << std::endl;
			}  catch (...) {
            	std::cerr << "Error: unknown." << std::endl;
        	}
		}
}

void BitcoinExchange::makeLine(std::string line){
	size_t pipe = line.find('|');
	if (pipe != std::string::npos){
		std::string date = line.substr(0, pipe);
		std::string valuestr = line.substr(pipe + 1);
		double datavalue = getDataValue(date);
		if (valuestr.empty() || pipe == std::string::npos || badInput(line)){
			std::string errormessage = "Error: bad input => " + date;
			throw std::runtime_error(errormessage);
		}
		double value = std::stod(valuestr);
		if (value < 0)
			throw std::out_of_range("Error: not a positive number.");
		if (value > 1000)
			throw std::out_of_range("Error: too large number.");
		if (datavalue < 0){
			std::string errormessage = "Error: bad input => " + date;
			throw std::runtime_error(errormessage);
		}
		double result = datavalue * value;
		std::cout << date << "=> " << value << " = "  << result << std::endl;
	}
	else {
		std::string errormessage = "Error: bad input => " + line;
		throw std::runtime_error(errormessage);
	}
}
	
std::map<std::string, double>  BitcoinExchange::getMap(){
	return (_Map);
}

std::string	BitcoinExchange::getInput(){
	return this->_input;
}

bool	BitcoinExchange::badInput(const std::string& input){
	int dash = 0;
	int dot = 0;
	int pipe = 0;
	int valuedash = 0;
	for (size_t i = 0; input[i] != '\0'; i++){
		if (input[i] == '-' && pipe == 0)
			dash++;
		else if (input[i] == '.')
			dot++;
		else if (input[i] == '-' && pipe == 1)
			valuedash++;
		else if (input[i] == '|')
			pipe++;
		else if (!isdigit(input[i]) && input[i] != ' '){
			return true;
		}
	}
	if (dot > 1 || dash > 2 || pipe > 1)
		return true;
	return false;
}