//
//  vasm_to_vbin.cpp
//  Problem #2: Vasm To Vbin
//
//  Converts vasm to vbin.
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
		map<string, vector<string>> asm_instructions;
		
		vector<vector<string>> get_tokens() 
		{
			return tokens;
		}
		
		void print_tokens() 
		{
			cout_tokens(tokens);
		}
		
		map<string, vector<string>> get_asm_instructions() 
		{
			return asm_instructions;
		}
		
		template<typename T>
		string int_to_hex(T i)
		{
			stringstream stream;
			stream << "0x" 
				   << setfill('0') 
				   << setw(sizeof(T)*2) 
				   << hex 
				   << i;
			return stream.str();
		}
		
		void generate_addresses() 
		{
			for (auto& tokens_vector: tokens) {
				string first_instruction = tokens_vector[0];
				auto search = asm_instructions.find(first_instruction);
				// push program counter current value to tokens_vector
				tokens_vector.push_back(
					// instruction address
					int_to_hex(program_counter)
				);
				// if first instruction is an asm instruction
				if (search != asm_instructions.end()) {
					// add asm instruction bytes to program counter
					program_counter += stoi(asm_instructions[first_instruction][0]);
				}
			}
		}
		
		void generate_code() 
		{
			for (auto& tokens_vector: tokens) {
				string first_instruction = tokens_vector[0];
				auto search = asm_instructions.find(first_instruction);
				// if first instruction is an asm instruction
				if (search != asm_instructions.end()) {
					// push instruction code to tokens_vector
					tokens_vector.push_back(
						// asm instruction code
						asm_instructions[first_instruction][1]
					);
					// TODO
				}
			}
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
			asm_instructions["load"].push_back("4");    // bytes
			asm_instructions["load"].push_back("01");   // code
			/* { "loadl": {"9", "2"} } */
			asm_instructions["loadl"].push_back("9");   // bytes 
			asm_instructions["loadl"].push_back("02");  // code
			/* { "store": {"4", "3"} } */
			asm_instructions["store"].push_back("4");   // bytes
			asm_instructions["store"].push_back("03");  // code
			/* { "add": {"1", "4"} } */
			asm_instructions["add"].push_back("1");     // bytes 
			asm_instructions["add"].push_back("04");    // code
			/* { "sub": {"1", "5"} } */
			asm_instructions["sub"].push_back("1");     // bytes
			asm_instructions["sub"].push_back("05");    // code
			/* { "mult": {"1", "6"} } */
			asm_instructions["mult"].push_back("1");    // bytes
			asm_instructions["mult"].push_back("06");   // code
			/* { "equal": {"1", "7"} } */
			asm_instructions["equal"].push_back("1");   // bytes
			asm_instructions["equal"].push_back("07");  // code
			/* { "jmp": {"4", "8"} } */
			asm_instructions["jmp"].push_back("4");     // bytes
			asm_instructions["jmp"].push_back("08");    // code
			/* { "jmpz": {"4", "9"} } */
			asm_instructions["jmpz"].push_back("4");    // bytes 
			asm_instructions["jmpz"].push_back("09");   // code
			/* { "jmpnz": {"4" "10"} } */
			asm_instructions["jmpnz"].push_back("4");   // bytes   
			asm_instructions["jmpnz"].push_back("0A");  // code
			/* { "edit": {"2", "11"} } */
			asm_instructions["edit"].push_back("2");    // bytes
			asm_instructions["edit"].push_back("1N");   // code
			/* { "print": {"1", "12"} } */
			asm_instructions["print"].push_back("1");   // bytes 
			asm_instructions["print"].push_back("0C");  // code
			/* { "halt": {"1", "13"} } */
			asm_instructions["halt"].push_back("1");    // bytes
			asm_instructions["halt"].push_back("0D");   // code
			/* { "space": {"1", "14"} } */
			asm_instructions["space"].push_back("1");   // bytes 
			asm_instructions["space"].push_back("2N");  // code
			/* { "block": {"1", "0"} } */
			asm_instructions["block"].push_back("8");   // bytes  
			asm_instructions["block"].push_back("");    // code
			/* { "end": {"1", "0"} } */
			asm_instructions["end"].push_back("1");     // bytes  
			asm_instructions["end"].push_back("");      // code
		}
		
		void run() 
		{
			generate_addresses();
			generate_code();
			print_tokens();
		}
		
		
		
};

int main(int argc, char *argv[]) 
{
	auto v = Vasm("example2.vasm");
	v.run();
}
