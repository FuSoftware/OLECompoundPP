#ifndef FHXITEM_H
#define FHXITEM_H

#include <string>
#include <vector>

namespace FHX
{

class FHXParameter;
class FHXItem
{
public:
    FHXItem(std::string data);

protected:
    std::vector<FHXItem*> chilren;
    std::vector<FHXParameter*> parameters;
    FHXItem *parent;
};
}

#endif // FHXITEM_H
