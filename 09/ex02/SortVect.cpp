#include "PmergeMe.hpp"

std::vector<std::pair<int, int>>	PmergeMe::MergeVect(std::vector<std::pair<int, int>>& first, std::vector<std::pair<int, int>>& second){
	std::vector<std::pair<int, int>> result;
	result.reserve(first.size() + second.size());

	auto iterFirst 	= first.begin();
	auto endFirst 	= first.end();
	auto iterSecond = second.begin();
    auto endSecond 	= second.end();
	while (iterFirst != endFirst && iterSecond != endSecond) {
        if (iterFirst->first <= iterSecond->first) {
            result.emplace_back(std::move(*iterFirst));
            ++iterFirst;
        } else {
            result.emplace_back(std::move(*iterSecond));
            ++iterSecond;
        }
    }
	result.insert(result.end(), iterFirst, endFirst);
    result.insert(result.end(), iterSecond, endSecond);
	return result;
}

std::vector<std::pair<int, int>> PmergeMe::SortVectBig(std::vector<std::pair<int, int>>& pairs){

	if (pairs.size() <= 1)
        return pairs;
	
	size_t middle = pairs.size() / 2;
	std::vector<std::pair<int, int>> first(pairs.begin(), pairs.begin() + middle);
	std::vector<std::pair<int, int>> second(pairs.begin() + middle, pairs.end());
	first  = SortVectBig(first);
	second = SortVectBig(second);
	return (MergeVect(first, second));
}

//Ford–Johnson algorithm 
void	PmergeMe::sortVect(std::vector<int>& sortvect){
	std::vector<std::pair<int, int>> pairs;
	
	size_t sizevect	= sortvect.size();
	int unpaired 	= 0;
	bool uneven		= false;
	pairs.reserve(sizevect/2);
	for(size_t i = 0; i < sizevect; i+=2 ){
		if (i + 1 == sizevect && sizevect % 2 != 0 ){
			uneven 	 = true;
			unpaired = sortvect[i];
			continue ;
		}
		int high = std::max(sortvect[i], sortvect[i + 1]);
        int low  = std::min(sortvect[i], sortvect[i + 1]);
		pairs.emplace_back(high, low);
	}
	
	std::vector<std::pair<int, int>> sortedpairs = SortVectBig(pairs);
	
	_vect.clear();
	_vect.reserve(sizevect);
	for (const auto& pair : sortedpairs) {
        _vect.emplace_back(pair.first);
    }
	if (uneven){
		auto pos = std::lower_bound(_vect.begin(), _vect.end(), unpaired);
        _vect.insert(pos, unpaired);
	}
	for (const auto& pair : sortedpairs) {
		if (pair.second) {
			auto pos = std::lower_bound(_vect.begin(), _vect.end(), pair.second);
			_vect.insert(pos, pair.second);
		}
	}
}
