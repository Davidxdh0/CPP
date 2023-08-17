#include "PmergeMe.hpp"

std::deque<std::pair<int, int>>	PmergeMe::MergeDeque(std::deque<std::pair<int, int>>& first, std::deque<std::pair<int, int>>& second){
	std::deque<std::pair<int, int>> result;

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

std::deque<std::pair<int, int>> PmergeMe::SortDequeBig(std::deque<std::pair<int, int>>& pairs){
	if (pairs.size() <= 1) {
        return pairs;
    }
	size_t middle = pairs.size() / 2;
	std::deque<std::pair<int, int>> first(pairs.begin(), pairs.begin() + middle);
	std::deque<std::pair<int, int>> second(pairs.begin() + middle, pairs.end());
	first  = SortDequeBig(first);
	second = SortDequeBig(second);
	return (MergeDeque(first, second));
}

//Ford–Johnson algorithm 
void	PmergeMe::sortDeque(std::deque<int>& sortdeque){
	
	size_t sizevect 			   = sortdeque.size();
	std::deque<std::pair<int, int>> pairs;
	int unpaired 				   = 0;
	bool uneven 				   = false;
	for(size_t i = 0; i < sizevect; i+=2 ){
		if (sizevect % 2 != 0 && i + 1 == sizevect){
			uneven = true;
			unpaired = sortdeque[i];
			continue ;
		}
		int high = sortdeque[i] > sortdeque[i + 1] ? sortdeque[i] : sortdeque[i + 1];
		int low  = sortdeque[i] < sortdeque[i + 1] ? sortdeque[i] : sortdeque[i + 1];
		pairs.emplace_back(high, low);
	}
	
	std::deque<std::pair<int, int>> sortedpairs;
	sortedpairs = SortDequeBig(pairs);
	
	_deque.clear();
	for (const auto& pair : sortedpairs) {
        _deque.push_back(pair.first);
    }
	
	if (uneven)
		sortedpairs.push_back({-1, unpaired});;

	std::deque<std::pair<int, int>>::iterator begin = sortedpairs.begin();
	std::deque<std::pair<int, int>>::iterator end = sortedpairs.end();
	for (auto i = begin; i < end; i++) {
        if (i->second){
			std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), _deque.end(), i->second);
			_deque.insert(pos, i->second);
		}
    }
	
}
