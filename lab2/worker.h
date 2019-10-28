#include <map>
#include <iostream>
#include "Iblock.h"

class worker {
private:
    std::map<std::string, std::vector<std::string>> blocks;
    std::vector<std::string> sequence;
    std::vector<std::string> text;

public:
    void parce(const std::string &fileName) {
        std::ifstream in(fileName);

        if (!in.is_open()) {
            throw std::invalid_argument("Can not open file");
        }

        std::string buffer;
        std::string id;

        in >> buffer;
        if (buffer != "desc") {
            throw std::logic_error("Wrong file content");
        }

        while (!in.eof()) {
            in >> id;

            if (id == "csed") {
                break;
            }

            do {
                in >> buffer;
                
                if (buffer != "=") {
                    blocks[id].push_back(buffer);
                }
            } while (in.get() != '\n' && !in.eof());
        }
        
        if (id != "csed"){
            throw std::logic_error("Wrong file content");
        }

        do {
            in >> buffer;

            if (buffer != "->") {
                sequence.push_back(buffer);
            }
        } while (in.get() != '\n' && !in.eof());
    }

    void makeSequence(){
        for (const std::string &id : sequence){
            if (id == "0"){
                Readfile r;
                r.execute(&blocks[id], &text);
            }

            if (id == "1"){
                Writefile w;
                w.execute(&blocks[id], &text);
            }

            if (id == "4"){
                Replace r;
                r.execute(&blocks[id], &text);
            }
        }
    }
};