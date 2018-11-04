//
//  vasm_to_vbin.cpp
//  Problem #2: Vasm To Vbin
//
//  Converts vasm to vbin.
//	Complexity: O(n)
//
//

#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include "scan.hpp"

using namespace std;
using namespace scanpp;

class Vasm {
	private:
		int program_counter;
		string vasm_file_name;
		vector<vector<string>> tokens;
		map<string, string> memory_adresses;
		map<string, vector<string>> vasm_instructions;
		
		vector<vector<string>> get_tokens() 
		{
			return tokens;
		}
		
		void show_tokens() 
		{
			cout_tokens(tokens);
		}
		
		map<string, vector<string>> get_vasm_instructions() 
		{
			return vasm_instructions;
		}
		
		string int_to_hex(int i)
		{
			stringstream stream;
			stream << "0x" 
				   << setfill('0') 
				   << setw(sizeof(int) * 2) 
				   << hex 
				   << i;
			return stream.str();
		}
		
		void generate_addresses() 
		{
			for (auto& tokens_vector: tokens) {
				auto instruction_address = int_to_hex(program_counter);
				// push instruction address to tokens vector
				tokens_vector.push_back(
					instruction_address
				);
				auto first_token = tokens_vector[0];
				auto vasm_search = vasm_instructions.find(first_token);
				// if first token is an vasm instruction
				if (vasm_search != vasm_instructions.end()) {
					// add vasm instruction bytes to program counter
					program_counter += stoi(vasm_instructions[first_token][0]);
				}
			}
		}
		
		void save_labels_addresses() 
		{
			for (auto& tokens_vector: tokens) {
				// if tokens vector only have two tokens
				if (tokens_vector.size() == 2) {
					auto first_token = tokens_vector[0];
					auto vasm_search = vasm_instructions.find(first_token);
					// if tokens vector represents a vasm label
					// => i.e. if first token is not a vasm instruction
					if (vasm_search == vasm_instructions.end()) {
						// save token address
						auto address = tokens_vector[1];
						memory_adresses[first_token] = address;
					}
				}
			}
		}
		
		string string_to_ascii_hex(string s) 
		{
			stringstream stream;	
			auto first = s.begin();
			auto last = s.end();
			while (first != last) {
				stream << "0x" << hex << static_cast<int>(*first) << " ";
				++first;
			}
			return stream.str();
		}
		
		void generate_code() 
		{
			for (auto& tokens_vector: tokens) {
				auto first_token = tokens_vector[0];
				auto vasm_search = vasm_instructions.find(first_token);
				// if first token is an vasm instruction
				if (vasm_search != vasm_instructions.end()) {
					// push instruction code to tokens_vector
					tokens_vector.push_back(
						// vasm instruction code
						vasm_instructions[first_token][1]
					);
				}
				// if tokens vector only have four tokens
				// => i.e. if is a vasm instruction 
				if (tokens_vector.size() == 4) {
					auto second_token = tokens_vector[1];
					auto memory_search = memory_adresses.find(second_token);
					// if second token is a label with a valid memory address
					if (memory_search != memory_adresses.end()) {
						tokens_vector.push_back(
							memory_adresses[second_token]
						);
					} else {
						tokens_vector.push_back(
							string_to_ascii_hex(second_token)
						);
					}
				}
			}
		}
		
		void save_vbin_code() 
		{
			ofstream vbin_code;
			vbin_code.open("code.vbin", ofstream::out | ofstream::trunc);
			for (auto& tokens_vector: tokens) {
				for (auto& t: tokens_vector) {
					vbin_code << t << " ";
				}
				vbin_code << endl;
			}
			vbin_code.close();
		}
		
	public:
		Vasm(string file_name) 
		{
			// Step 0.
			program_counter = 0;
			// Step 1.
			tokens = tokenize_lines(file_name);
			// Step 2.
			/* { "load": {"4", "1"} } */
			vasm_instructions["load"].push_back("4");      // bytes
			vasm_instructions["load"].push_back("0x01");   // code
			/* { "loadl": {"9", "2"} } */
			vasm_instructions["loadl"].push_back("9");     // bytes 
			vasm_instructions["loadl"].push_back("0x02");  // code
			/* { "store": {"4", "3"} } */
			vasm_instructions["store"].push_back("4");     // bytes
			vasm_instructions["store"].push_back("0x03");  // code
			/* { "add": {"1", "4"} } */
			vasm_instructions["add"].push_back("1");       // bytes 
			vasm_instructions["add"].push_back("0x04");    // code
			/* { "sub": {"1", "5"} } */
			vasm_instructions["sub"].push_back("1");       // bytes
			vasm_instructions["sub"].push_back("0x05");    // code
			/* { "mult": {"1", "6"} } */
			vasm_instructions["mult"].push_back("1");      // bytes
			vasm_instructions["mult"].push_back("0x06");   // code
			/* { "equal": {"1", "7"} } */
			vasm_instructions["equal"].push_back("1");     // bytes
			vasm_instructions["equal"].push_back("0x07");  // code
			/* { "jmp": {"4", "8"} } */
			vasm_instructions["jmp"].push_back("4");       // bytes
			vasm_instructions["jmp"].push_back("0x08");    // code
			/* { "jmpz": {"4", "9"} } */
			vasm_instructions["jmpz"].push_back("4");      // bytes 
			vasm_instructions["jmpz"].push_back("0x09");   // code
			/* { "jmpnz": {"4" "10"} } */
			vasm_instructions["jmpnz"].push_back("4");     // bytes   
			vasm_instructions["jmpnz"].push_back("0x0A");  // code
			/* { "edit": {"2", "11"} } */
			vasm_instructions["edit"].push_back("2");      // bytes
			vasm_instructions["edit"].push_back("0x1N");   // code
			/* { "print": {"1", "12"} } */
			vasm_instructions["print"].push_back("1");     // bytes 
			vasm_instructions["print"].push_back("0x0C");  // code
			/* { "halt": {"1", "13"} } */
			vasm_instructions["halt"].push_back("1");      // bytes
			vasm_instructions["halt"].push_back("0x0D");   // code
			/* { "space": {"1", "14"} } */
			vasm_instructions["space"].push_back("1");     // bytes 
			vasm_instructions["space"].push_back("0x2N");  // code
			/* { "block": {"1", "0"} } */
			vasm_instructions["block"].push_back("8");     // bytes  
			vasm_instructions["block"].push_back("");      // code
			/* { "end": {"1", "0"} } */
			vasm_instructions["end"].push_back("1");       // bytes  
			vasm_instructions["end"].push_back("");        // code
		}
		
		void run() 
		{
			generate_addresses();
			save_labels_addresses();
			generate_code();
			show_tokens();
			save_vbin_code();
		}	
		
};

int main(int argc, char *argv[]) 
{
	auto v = Vasm("example.vasm");
	v.run();
}
