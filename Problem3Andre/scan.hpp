//
//  scan.hpp
//  Scanpp
//
//  Scan tokens in txt created from Reflex.
//
//

#ifndef scan_hpp
#define scan_hpp

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>

namespace scanpp {
	// this function consider " " as token separator
	std::vector<std::string> tokenize(std::string str)
	{
		std::istringstream buffer(str);
		std::istream_iterator<std::string> begin(buffer), end;
		std::vector<std::string> tokens(begin, end); // done!
		return tokens;
	}

	std::vector<std::vector<std::string>> tokenize_lines(std::string file_name) 
	{
		std::ifstream file(file_name);
		std::string str;
		std::vector<std::vector<std::string>> tokens;
		while (getline(file, str)) {
			tokens.push_back(tokenize(str));
		}
		return tokens;
	}
	
	void cout_tokens(std::vector<std::vector<std::string>>& tokens) 
	{
		for (auto& tokens_vector: tokens) {
			for (auto& t: tokens_vector) {
				std::cout << t << " ";
			}
			std::cout << std::endl;
		}
	}
}

#endif /* scan_hpp */
