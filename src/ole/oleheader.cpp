#include "oleheader.h"

OLE::OLEHeader::OLEHeader(std::vector<unsigned char> data)
{

}

void OLE::OLEHeader::load(std::vector<unsigned char> data)
{
    if(data.size() != 512){
        std::cerr << "Header size should be 512 bytes, found " << data.size() << " bytes"<< std::endl;
        return;
    }


}
