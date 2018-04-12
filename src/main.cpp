#include <iostream>
#include <vector>
#include "ole/oleutils.h"
#include "ole/oleheader.h"
#include "ole/olemsat.h"
#include "ole/olefile.h"

void testFile(std::string path)
{
    OLE::OLEFile *f = new OLE::OLEFile(path);
    std::cout << f->getHeader()->getRevision() << " : " <<  f->getHeader()->getVersion() << std::endl;
}

void testHeader(std::string path)
{
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
    std::cout << "HE : " << sizeof(*header) << " bytes" << std::endl;
    std::cout << "62 : " << header->getRevision() << std::endl;
    std::cout << "03 : " << header->getVersion() << std::endl;

    delete header;
}

int main()
{
    testFile("E:\\Prog\\Data\\Syno\\C_DRAIN.grf");

    return 0;
}
