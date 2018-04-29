#include "fhxparser.h"
#include "fhxitem.h"

#include <regex>

const std::string FHX::FHXParser::patternItems = "(.+)\\s{\\s(.*)}\\s{0,1}";

FHX::FHXParser::FHXParser()
{

}

std::vector<FHX::FHXItem*> FHX::FHXParser::parseItems(std::string data)
{
    std::regex re(patternItems);
    std::smatch m;
    std::regex_search(data, m, re);

    //Group 1 : Item Header
    //Group 2 : Item Content

    for(int i=0; i<m.size();i++)
    {
        auto v = m.at(i);
        std::cout << v << std::endl;
    }

    std::vector<FHXItem*> result;



    return result;
}
