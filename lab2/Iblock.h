#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

class Iblock {
public:
    virtual void execute(std::vector<std::string> *args, std::vector<std::string> *text) = 0;
};

class Readfile : public Iblock{
public:

    void execute(std::vector<std::string> *args, std::vector<std::string> *text) override {
        std::ofstream output((*args)[1]);
        std::string buffer;

        for (const std::string &str : *text) {
            output << str << std::endl;
        }
    }
    
};

class Writefile : public Iblock{
public:

    void execute(std::vector<std::string> *args, std::vector<std::string> *text) override {
        std::ifstream input((*args)[1]);
        std::string buffer;

        while (std::getline(input, buffer)) {
            (*text).push_back(buffer);
        }
    }

};

class Sort : public Iblock{
public:

    void execute(std::vector<std::string> *args, std::vector<std::string> *text) override {
        sort((*text).begin(), (*text).end());
    }

};

class Grep : public Iblock{
public:

    void execute(std::vector<std::string> *args, std::vector<std::string> *text) override {
        for (size_t i = 0; i < (*text).size(); i++){
            if (((*text)[i].find((*args)[1]) == std::string::npos)){
                (*text).erase((*text).begin() + i);
                i--;
            }
        }
    }

};

class Dump : public Iblock{
public:

    void execute(std::vector<std::string> *args, std::vector<std::string> *text) override {
        Writefile w;

        w.execute(args, text);
    }

};

class Replace : public  Iblock{
public:

    void execute(std::vector<std::string> *args, std::vector<std::string> *text) override {
        for (auto & i : (*text)){
            for (auto j = i.find((*args)[1]); j != std::string::npos; j = i.find((*args)[1])){
                i.replace(j, j + (*args)[1].length(), (*args)[2]);
            }
        } 
    }

};