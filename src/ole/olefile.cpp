#include "olefile.h"
#include "oleutils.h"
#include "oleheader.h"
#include "olemsat.h"

OLE::OLEFile::OLEFile()
{

}

OLE::OLEFile::OLEFile(std::string file_path)
{
    this->load(readFile(file_path));
}

OLE::OLEFile::OLEFile(std::vector<unsigned char> *data)
{
    this->load(data);
}

void OLE::OLEFile::load(std::vector<unsigned char> *data)
{
    this->raw_data = data;
    this->header = new OLEHeader(this);
    this->msat = new OLEMSAT(this);
}

OLE::OLEHeader *OLE::OLEFile::getHeader() const
{
    return this->header;
}

OLE::OLEMSAT *OLE::OLEFile::getMSAT() const
{
    return this->msat;
}

std::vector<unsigned char> *OLE::OLEFile::getSectorFromID(int sec_id)
{
    return this->getSector(this->getHeader()->getSectorOffset(sec_id));
}

std::vector<unsigned char> *OLE::OLEFile::getSector(int offset)
{
    return OLE::split(this->raw_data, offset, this->getHeader()->getSectorSize(), this->getHeader()->getIsLittleEndian());
}

std::vector<unsigned char> *OLE::OLEFile::getData()
{
    return this->raw_data;
}
