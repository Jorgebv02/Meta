//
//  vasm_to_vbin.cpp
//  Problem #2: Vasm To Vbin
//
//  Converts vasm to vbin.
//
//

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include "scan.hpp"

using namespace std;
using namespace scanpp;

void asm_to_hex(vector<string>& tokens)
{
	for (vector<int>::size_type i = 0; i < tokens.size(); ++i) {
		if ("load" == tokens[i]) {
			tokens[i] = "0x01";
		}
		else if ("loadl" == tokens[i]) {
			tokens[i] = "0x02";
		}
		else if ("store" == tokens[i]) {
			tokens[i] = "0x03";
		}
		else if ("add" == tokens[i]) {
			tokens[i] = "0x04";
		}
		else if ("sub" == tokens[i]) {
			tokens[i] = "0x05";
		}
		else if ("mult" == tokens[i]) {
			tokens[i] = "0x06";
		}
		else if ("equal" == tokens[i]) {
			tokens[i] = "0x07";
		}
		else if ("jmp" == tokens[i]) {
			tokens[i] = "0x08";
		}
		else if ("jmpz" == tokens[i]) {
			tokens[i] = "0x09";
		}
		else if ("jmpnz" == tokens[i]) {
			tokens[i] = "0x0A";
		}
		else if ("edit" == tokens[i]) {
			tokens[i] = "0x1N";
		}
		else if ("print" == tokens[i]) {
			tokens[i] = "0x0C";
		}
		else if ("halt" == tokens[i]) {
			tokens[i] = "0x0D";
		}
		else if ("space" == tokens[i]) {
			tokens[i] = "0x2N";
		}
		else if ("block" == tokens[i]) {
			tokens[i] = "0x00";
		}
		else if ("end" == tokens[i]) {
			tokens[i] = "0x00";
		}
	}
}

int main(int argc, char *argv[]) 
{
	vector<vector<string>> tokens = tokenize_lines("example2.vasm");
	for (auto& tokens_vector: tokens) {
		asm_to_hex(tokens_vector);
	}
	cout_tokens(tokens);
}

