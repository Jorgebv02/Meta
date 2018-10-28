//
//  parse_tokens.cpp
//  Parse_tokens
//
//  Parse tokens from TXT
//
//  Created by Elberth Adrián Garro Sánchez on 28/10/18.
//  Copyright © 2018 Elberth Adrián Garro Sánchez. All rights reserved.
//

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>

using namespace std;

vector<string> tokenize(string str)
{
	istringstream buf(str);
	istream_iterator<string> beg(buf), end;
	vector<string> tokens(beg, end); // done!
	return tokens;
}

vector<vector<string>> tokenize_txt_lines(string filename) 
{
	ifstream file(filename);
	string str; 
	vector<vector<string>> tokens;
	while (getline(file, str)) {
		tokens.push_back(tokenize(str));
	}
	return tokens;
}

int main(int argc, char *argv[]) 
{
	vector<vector<string>> tokens = tokenize_txt_lines("tokens.txt");
	for (auto const& tokens_vector: tokens) {
		for (auto const& t: tokens_vector) {
			 cout << t << endl;
		}
	}
}

