#include "olesat.h"
#include "olemsat.h"
#include "olefile.h"
#include "oleutils.h"

OLE::OLESAT::OLESAT(OLE::OLEFile *file)
{
    this->load(file);
}

void OLE::OLESAT::load(OLE::OLEFile *file)
{
    this->file = file;
    this->sectors.clear();

    std::vector<int> msat = this->file->getMSAT()->getSecIds();

    for(int i=0;i<msat.size();i++)
    {
        if(msat[i] < 0) break;
        this->sectors.push_back(file->getSector(msat[i]));
    }
}
