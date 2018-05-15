#include "fhxparser.h"
#include "fhxitem.h"

#include <regex>
#include <iostream>

const std::string FHX::FHXParser::pattern_items = "(.+)\\s{\\s(.*)}\\s{0,1}";
const std::string FHX::FHXParser::pattern_comments = "\\/\\*([\\S\\s]*?)\\*\\/";

FHX::FHXParser::FHXParser()
{

}

std::vector<FHX::FHXItem*> FHX::FHXParser::parseItems(std::string data)
{
    data = FHXParser::removeComments(data);

    std::regex re;
    try{
        re = std::regex("(.+)\\s\\{\\s(.*)\\}\\s{0,1}");
    }catch(std::regex_error& e){
        std::cerr << "Error while loading regex : " << e.code() << ".\n" << std::endl;
        return std::vector<FHXItem*>();
    }

    std::smatch m;
    std::regex_match(data, m, re);

    //Group 1 : Item Header
    //Group 2 : Item Content

    for(int i=0; i<m.size();i++)
    {
        auto v = m[i];
        std::cout << v << std::endl;
    }

    std::vector<FHXItem*> result;
    return result;
}

std::string FHX::FHXParser::removeComments(std::string text)
{
    std::regex re;
    try{
        re = std::regex(FHXParser::pattern_comments);
    }catch(std::regex_error& e){
        std::cerr << "Error while loading regex : " << e.code() << ".\n" << std::endl;
        return "";
    }

    text = std::regex_replace(text, re, "");
    return text;
}

FHX::FHXParameter* FHX::FHXParser::decodeParameter(std::string *data, int *offset)
{
    return 0;
}

FHX::FHXParameter* FHX::FHXParser::decodeDescriptor(std::string *data, int *offset)
{
    return 0;
}

FHX::FHXItem* FHX::FHXParser::decodeItem(std::string *data, int *offset)
{
    return 0;
}
