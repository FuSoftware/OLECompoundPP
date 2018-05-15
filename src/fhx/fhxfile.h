#ifndef FHXFILE_H
#define FHXFILE_H

#include <vector>
#include <string>

namespace FHX
{

class FHXItem;
class FHXFile
{
public:
    FHXFile(std::string path);
    void loadFile(std::string path);
    void load(std::string str);

private:
    std::vector<FHXItem*> items;
};

}

#endif // FHXFILE_H
