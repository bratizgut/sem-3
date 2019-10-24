#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

class parcer{
private:
    std::map<std::string, std::list<std::string>> blocks;
    std::list<std::string> sequence;

public:
    parcer(const std::string &fileName){

        std::ifstream in(fileName);

        if (!in.is_open()){
            throw std::invalid_argument("Can not open file");
        }

        std::string buffer;
        std::string id;
        in >> buffer;

        if (buffer != "desc"){
            throw std::logic_error("Wrong file content");
        }

        while (!in.eof()){
            in >> id;

            if (id == "csed"){
                break;
            }

            do {
                in >> buffer;

                if (buffer != "="){
                    blocks[id].push_back(buffer);
                }
            } while (in.get() != '\n' && !in.eof());
        }

        if (id != "csed"){
            throw std::logic_error("Wrong file content");
        }

        do {
            in >> buffer;

            if (buffer != "->"){
                sequence.push_back(buffer);
            }
        } while (in.get() != '\n' && !in.eof());
    }
};