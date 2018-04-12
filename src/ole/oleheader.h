#ifndef OLEHEADER_H
#define OLEHEADER_H

#include <vector>
#include <string>
#include <iostream>

namespace OLE
{

class OLEHeader
{
public:
    OLEHeader(std::vector<unsigned char> data);

    void load(std::vector<unsigned char> data);
    static bool isLittleEndian(std::vector<unsigned char> data);

    int getRevision() const;
    int getVersion() const;
    bool getIsLittleEndian() const;

    int getSectorSize() const;
    int getShortSectorSize() const;

    std::vector<unsigned char> getMSAT() const;

    bool isMSATinSAT() const;
    int getFirstMSATSecID() const;

    int getSectorOffset(int sec_id) const;

private:
    std::string id; //0 : 8 bytes (DO CF 11 E0 A1 B1 1A E1)
    std::string uid; //8 : 16 bytes, usually all 0s
    int rev; //24 : 2 bytes (00 3E)
    int version; //26 : 2 bytes (00 03)
    bool little_endian; //28 : 2 bytes (FE FF Big | FF FE Little)
    int sec_pow; //30 : 2 bytes, size of a sector as 2^sec_pow
    int sec_size;
    int short_sec_pow; //32 : 2 bytes, size of a short sector as 2^sec_pow
    int short_sec_size;
    //10 bytes, not used
    int sector_alloc_table; //44 : 4 bytes, N sectors for allocation table
    int first_sector_id; //48 : 4 bytes, SecID of the first sector of the Root Directory
    //4 bytes, not used
    int sec_size_def;//56 : 4 bytes, minimum size of a "sector", everything under is a "short sector"
    int first_short_sector_id; //60 : 4 bytes, SecID of the first short sector in the short alloc table
    int n_short_sect; //64 : 4 bytes, Total number of sectors used in the short alloc table
    int first_master_sector_id; //68 : 4 bytes, First sector of the master allocation table
    int n_master_sect; //72 : 4 bytes, number of sectors in master table
    std::vector<unsigned char> msat; //76 : 436, 109 first sectors of the MSAT
};

}


#endif // OLEHEADER_H
