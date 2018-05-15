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
    static std::string removeComments(std::string text);

    FHXParameter* decodeParameter(std::string *data, int *offset);
    FHXParameter* decodeDescriptor(std::string *data, int *offset);
    FHXItem* decodeItem(std::string *data, int *offset);


private:
    static const std::string pattern_items;
    static const std::string pattern_comments;

};

}

#endif // FHXPARSER_H
