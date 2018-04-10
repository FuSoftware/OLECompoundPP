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

private:
    std::string id; // 8 bytes (DO CF 11 E0 A1 B1 1A E1)
    std::string uid; // 16 bytes, usually all 0s
    int rev; // 2 bytes (00 3E)
    int version; //2 bytes (00 03)
    bool big_endian; //2 bytes (FE FF Big | FF FE Little)
    int sec_pow; //2 bytes, size of a sector as 2^sec_pow
    int short_sec_pow; //2 bytes, size of a short sector as 2^sec_pow
    //10 bytes, not used
    int sector_alloc_table; //4 bytes, N sectors for allocation table
    int first_sector_id; //4 bytes, SecID of the first sector of the Root Directory
    //4 bytes, not used
    int sec_size_def;//4 bytes, minimum size of a "sector", everything under is a "short sector"
    int first_short_sector_id; //4 bytes, SecID of the first short sector in the short alloc table
    int n_short_sect; //4 bytes, Total number of sectors used in the short alloc table
    int first_master_sector_id; //4 bytes, First sector of the master allocation table
    int n_master_sect; //4 bytes, number of sectors in master table



};

}


#endif // OLEHEADER_H
