#include "olemsat.h"
#include "oleutils.h"
#include "oleheader.h"
#include "olefile.h"

#include <iostream>

OLE::OLEMSAT::OLEMSAT(OLEFile *file)
{
    this->file = file;
}

void OLE::OLEMSAT::load()
{
    OLEHeader *h = this->file->getHeader();
    std::vector<unsigned char> *data = h->getMSAT();

    //We now that the part from the Header contains 109 SecIDs
    for(int i=0; i<109;i++)
    {
        unsigned long id = OLE::toULong(data, h->getIsLittleEndian(), i*4);
        this->addSecID(id);
    }

    //We check if part of the MSAT is in the SAT
    if(h->isMSATinSAT())
    {
        std::cout << "Loading from the SAT" << std::endl;
        int sec_id = h->getFirstMSATSecID();
    }
    else
    {
        std::cout << "Nothing to load from the SAT" << std::endl;
    }

    std::cout << this->sec_ids.size() << " SecIDs loaded" << std::endl;
}

void OLE::OLEMSAT::addSecID(int id)
{
    this->sec_ids.push_back(id);
}

int OLE::OLEMSAT::getSecId(int index)
{
    return this->getSecIds()[0];
}

std::vector<int> OLE::OLEMSAT::getSecIds()
{
    return this->sec_ids;
}
