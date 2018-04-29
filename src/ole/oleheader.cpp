#include "oleheader.h"
#include "oleutils.h"
#include "olefile.h"

#include <cmath>

OLE::OLEHeader::OLEHeader(OLE::OLEFile *parent)
{
    this->parent = parent;
    this->load(parent->getData());
}

void OLE::OLEHeader::load(std::vector<unsigned char> *data)
{
    this->little_endian = OLEHeader::isLittleEndian(OLE::split(data, 28, 2, false)); //28 : 2 bytes (FE FF Big | FF FE Little)

    this->id = OLE::toString(data, 0, 8);
    this->uid = OLE::toString(data, 8, 16);

    this->rev = OLE::toUShort(data, this->little_endian, 24);
    this->version = OLE::toUShort(data, this->little_endian, 26);

    this->sec_pow = OLE::toUShort(data, this->little_endian, 30);
    this->short_sec_pow = OLE::toUShort(data, this->little_endian, 32);

    this->sec_size = (int)pow(2, this->sec_pow);
    this->short_sec_size = (int)pow(2, this->short_sec_pow);

    this->sector_alloc_table = OLE::toULong(data, this->little_endian, 44);
    this->first_sector_id = OLE::toULong(data, this->little_endian, 48);
    this->sec_size_def = OLE::toULong(data, this->little_endian, 56);
    this->first_short_sector_id = OLE::toULong(data, this->little_endian, 60);
    this->n_short_sect = OLE::toULong(data, this->little_endian, 64);
    this->first_master_sector_id = OLE::toULong(data, this->little_endian, 68);
    this->n_master_sect = OLE::toULong(data, this->little_endian, 72);
    this->msat = OLE::split(data, 76, 436, this->little_endian);
}

bool OLE::OLEHeader::isLittleEndian(std::vector<unsigned char> *data)
{
    return ((*data)[0] == 0xFF) && ((*data)[1] == 0xFE);
}

unsigned short OLE::OLEHeader::getRevision() const
{
    return this->rev;
}

bool OLE::OLEHeader::getIsLittleEndian() const
{
    return this->little_endian;
}

unsigned short OLE::OLEHeader::getVersion() const
{
    return this->version;
}

unsigned short OLE::OLEHeader::getSectorSize() const
{
    return this->sec_size;
}

unsigned short OLE::OLEHeader::getShortSectorSize() const
{
    return this->short_sec_size;
}

std::vector<unsigned char> *OLE::OLEHeader::getMSAT() const
{
    return this->msat;
}

bool OLE::OLEHeader::isMSATinSAT() const
{
    return this->first_master_sector_id != -2;
}

unsigned OLE::OLEHeader::getFirstMSATSecID() const
{
    return this->first_master_sector_id;
}

unsigned short OLE::OLEHeader::getSectorOffset(int sec_id) const
{
    return 512 + sec_id * this->sec_size;
}

