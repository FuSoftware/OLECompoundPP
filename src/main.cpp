#include <iostream>
#include <vector>
#include "ole/oleutils.h"
#include "ole/oleheader.h"

void testHeader(std::string path){
    std::vector<unsigned char> data = OLE::readFile(path);
    std::vector<unsigned char> header_data = OLE::split(data, 0, 512, false);

    std::cout << path << std::endl;
    std::cout << header_data.size() << std::endl;

    //Tests the revision number and the version number of the file (62 and 03 respectively)
    std::cout << "62 : " << OLE::toInt(OLE::split(header_data,24,2)) << std::endl;
    std::cout << "03 : " << OLE::toInt(OLE::split(header_data,26,2)) << std::endl;

    //Properly tests the header
    OLE::OLEHeader *header = new OLE::OLEHeader(header_data);
    //Tests the revision number and the version number of the file (62 and 03 respectively)
    std::cout << "HE : " << sizeof(*header) << std::endl;
    std::cout << "62 : " << header->getRevision() << std::endl;
    std::cout << "03 : " << header->getVersion() << std::endl;

    delete header;
}


void testInt(){
    std::vector<unsigned char> s {0xE8, 0x09, 0x96, 0x05};

    std::vector<unsigned char> s1 = OLE::split(s, 0, 2, false);
    std::vector<unsigned char> s2 = OLE::split(s, 2, 2, false);

    std::cout << "2536 : " << OLE::toInt(s1) << std::endl;
    std::cout << "1430 : " << OLE::toInt(s2) << std::endl;
}

int main()
{
    testHeader("E:\\Doc1.doc");

    return 0;
}
