#include "oleheader.h"
#include "oleutils.h"

#include <cmath>

OLE::OLEHeader::OLEHeader(std::vector<unsigned char> data)
{
    this->load(data);
}

void OLE::OLEHeader::load(std::vector<unsigned char> data)
{
    if(data.size() != 512){
        std::cerr << "Header size should be 512 bytes, found " << data.size() << " bytes"<< std::endl;
        return;
    }

    this->little_endian = OLEHeader::isLittleEndian(OLE::split(data, 28, 2, false)); //28 : 2 bytes (FE FF Big | FF FE Little)

    this->id = OLE::toString(OLE::split(data, 0, 8, false));
    this->uid = OLE::toString(OLE::split(data, 8, 16, false));

    this->rev = OLE::toInt(OLE::split(data, 24, 2, this->little_endian));
    this->version = OLE::toInt(OLE::split(data, 26, 2, this->little_endian));

    this->sec_pow = OLE::toInt(OLE::split(data, 30, 2, this->little_endian));
    this->short_sec_pow = OLE::toInt(OLE::split(data, 32, 2, this->little_endian));

    this->sec_size = (int)pow(2, this->sec_pow);
    this->short_sec_size = (int)pow(2, this->short_sec_pow);

    this->sector_alloc_table = OLE::toInt(OLE::split(data, 44, 4, this->little_endian));
    this->first_sector_id = OLE::toInt(OLE::split(data, 48, 4, this->little_endian));
    this->sec_size_def = OLE::toInt(OLE::split(data, 56, 4, this->little_endian));
    this->first_short_sector_id = OLE::toInt(OLE::split(data, 60, 4, this->little_endian));
    this->n_short_sect = OLE::toInt(OLE::split(data, 64, 4, this->little_endian));
    this->first_master_sector_id = OLE::toInt(OLE::split(data, 68, 4, this->little_endian));
    this->n_master_sect = OLE::toInt(OLE::split(data, 72, 4, this->little_endian));
    this->msat = OLE::split(data, 76, 436, this->little_endian);
}

bool OLE::OLEHeader::isLittleEndian(std::vector<unsigned char> data)
{
    return (data[0] == 0xFF) && (data[1] == 0xFE);
}

int OLE::OLEHeader::getRevision() const
{
    return this->rev;
}

bool OLE::OLEHeader::getIsLittleEndian() const
{
    return this->little_endian;
}

int OLE::OLEHeader::getVersion() const
{
    return this->version;
}

int OLE::OLEHeader::getSectorSize() const
{
    return this->sec_size;
}

int OLE::OLEHeader::getShortSectorSize() const
{
    return this->short_sec_size;
}

std::vector<unsigned char> OLE::OLEHeader::getMSAT() const
{
    return this->msat;
}

bool OLE::OLEHeader::isMSATinSAT() const
{
    return this->first_master_sector_id != -2;
}

int OLE::OLEHeader::getFirstMSATSecID() const
{
    return this->first_master_sector_id;
}

int OLE::OLEHeader::getSectorOffset(int sec_id) const
{
    return 512 + sec_id * this->sec_size;
}

