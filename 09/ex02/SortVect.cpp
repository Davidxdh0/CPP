#include "PmergeMe.hpp"

std::vector<std::pair<int, int>>	PmergeMe::MergeVect(std::vector<std::pair<int, int>>& first, std::vector<std::pair<int, int>>& second){
	std::vector<std::pair<int, int>> result;
	result.reserve(first.size()+ second.size());

	auto iterFirst 	= first.begin();
	auto endFirst 	= first.end();
	auto iterSecond = second.begin();
    auto endSecond 	= second.end();
	while (iterFirst != endFirst && iterSecond != endSecond) {
        if (iterFirst->first <= iterSecond->first) {
            result.push_back(std::move(*iterFirst));
            iterFirst++;
        } else {
            result.push_back(std::move(*iterSecond));
            iterSecond++;
        }
    }
	result.insert(result.end(), iterFirst, endFirst);
    result.insert(result.end(), iterSecond, endSecond);
	return result;
}

std::vector<std::pair<int, int>> PmergeMe::SortVectBig(std::vector<std::pair<int, int>>& pairs){
	if (pairs.size() <= 1) {
        return pairs;
    }
	size_t middle = pairs.size() / 2;
	std::vector<std::pair<int, int>> first(pairs.begin(), pairs.begin() + middle);
	std::vector<std::pair<int, int>> second(pairs.begin() + middle, pairs.end());
	first  = SortVectBig(first);
	second = SortVectBig(second);
	return (MergeVect(first, second));
}

//Ford–Johnson algorithm 
void	PmergeMe::sortVect(std::vector<int> sortvect){
	
	size_t sizevect 			   = sortvect.size();
	std::vector<std::pair<int, int>> pairs;
	int unpaired 				   = 0;
	bool uneven 				   = false;
	pairs.reserve(sizevect);
	for(size_t i = 0; i < sizevect; i+=2 ){
		if (sizevect % 2 != 0 && i + 1 == sizevect){
			uneven = true;
			unpaired = sortvect[i];
			continue ;
		}
		int high = sortvect[i] > sortvect[i + 1] ? sortvect[i] : sortvect[i + 1];
		int low  = sortvect[i] < sortvect[i + 1] ? sortvect[i] : sortvect[i + 1];
		pairs.emplace_back(high, low);
	}
	
	std::vector<std::pair<int, int>> sortedpairs;
	sortedpairs.reserve(sizevect);
	sortedpairs = SortVectBig(pairs);

	_vect.clear();
	_vect.reserve(sizevect);
	for (const auto& pair : sortedpairs) {
        _vect.push_back(pair.first);
    }
	if (uneven)
		sortedpairs.push_back({-1, unpaired});;

	std::vector<std::pair<int, int>>::iterator begin = sortedpairs.begin();
	std::vector<std::pair<int, int>>::iterator end = sortedpairs.end();
	for (auto i = begin; i < end; i++) {
        if (i->second){
			std::vector<int>::iterator pos = std::lower_bound(_vect.begin(), _vect.end(), i->second);
			_vect.insert(pos, i->second);
		}
    }
}
