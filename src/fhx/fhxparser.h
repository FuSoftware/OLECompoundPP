#ifndef FHXPARSER_H
#define FHXPARSER_H

#include <string>
#include <vector>

namespace FHX
{

class FHXItem;
class FHXParameter;

class FHXParser
{
public:
    FHXParser();
    static std::vector<FHXItem*> parseItems(std::string data);
    static std::vector<FHXParameter*> parseParameters(std::string data);

private:
    static const std::string patternItems;

};

}

#endif // FHXPARSER_H
