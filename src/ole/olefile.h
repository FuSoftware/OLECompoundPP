#ifndef OLEFILE_H
#define OLEFILE_H

#include <string>
#include <vector>

namespace OLE{
    class OLEStorage;
    class OLEStream;
    class OLEHeader;

    class OLEFile
    {
    public:
        OLEFile();
        OLEFile(std::string file_path);
        OLEFile(unsigned char* data);
        OLEFile(std::vector<unsigned char> data);

    private:
        OLEStorage *root;
        OLEHeader *header;
    };
}



#endif // OLEFILE_H
