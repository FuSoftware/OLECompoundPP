#ifndef FHXFILE_H
#define FHXFILE_H

#include <vector>

namespace FHX
{

class FHXItem;
class FHXFile
{
public:
    FHXFile(std::vector<unsigned char> *data);

private:
    std::vector<FHXItem*> items;
};

}

#endif // FHXFILE_H
