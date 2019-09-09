#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include "parser.h"

int main(int argc, char **argv){

	std::ifstream in;
	std::ofstream out;
	in.open(argv[1]);
	out.open(argv[2]);
	Parser WordCounter;
	
	
	std::string str;
	while(std::getline(in, str)){
		for(int i = 0; i < str.length(); i++){
			if(isalpha(str[i]) || isdigit(str[i]))
				WordCounter.CurStr += str[i];
			else
				WordCounter.Recount();
		}
	}
	
	WordCounter.Output(out);

	return 0;

}
