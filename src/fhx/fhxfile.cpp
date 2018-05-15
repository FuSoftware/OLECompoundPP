#include "fhxfile.h"
#include "fhxparser.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

FHX::FHXFile::FHXFile(std::string path)
{
    this->loadFile(path);
}

void FHX::FHXFile::loadFile(std::string path)
{
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string text = buffer.str();
    this->load(text);
    t.close();
}

void FHX::FHXFile::load(std::string str)
{
    str.erase (std::remove(str.begin(), str.end(), '\0'), str.end());
    std::vector<FHXItem*> items =  FHXParser::parseItems(str);
    std::cout << "Loaded " << items.size() << " items";
}
