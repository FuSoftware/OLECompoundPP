#ifndef OLESAT_H
#define OLESAT_H

#include <vector>

namespace OLE
{

class OLEFile;

class OLESAT
{
public:
    OLESAT(OLEFile* file);
    void load(OLEFile *file);

private:
    OLEFile *file;
    std::vector<int> sec_ids;
    std::vector< std::vector<unsigned char> > sectors;
};

}

#endif // OLESAT_H
