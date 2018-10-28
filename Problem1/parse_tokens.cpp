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

// asm_instructions = { {label, code, bytes}, ... }
vector<vector<string>> asm_instructions = {
	{"load", "0x01", "4"},
	{"loadl", "0x02", "9"},
	{"store", "0x03", "4"},
	{"add", "0x04", "1"},
	{"sub", "0x05", "1"},
	{"mult", "0x06", "1"},
	{"equal", "0x07", "1"},
	{"jmp", "0x08", "4"},
	{"jmpz", "0x09", "4"},
	{"jmpnz", "0x0A", "4"},
	{"edit", "0x1N", "2"},
	{"print", "0x0C", "1"},
	{"halt", "0x0D", "1"},
	{"space", "0x2N", "1"},
	{"block", "0x00", "1"}, 
	{"end", "0x00", "1"}
};

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

