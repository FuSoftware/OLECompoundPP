#ifndef OLEFILE_H
#define OLEFILE_H

#include <string>
#include <vector>

namespace OLE{
    class OLEStorage;
    class OLEStream;
    class OLEHeader;
    class OLEMSAT;

    class OLEFile
    {
    public:
        OLEFile();
        OLEFile(std::string file_path);
        OLEFile(std::vector<unsigned char> data);

        void load(std::vector<unsigned char> data);
        OLEHeader *getHeader() const;

        std::vector<unsigned char> getSectorFromID(int sec_id);
        std::vector<unsigned char> getSector(int offset);

    private:
        OLEStorage *root;
        OLEHeader *header;
        OLEMSAT *msat;

        std::vector<unsigned char> raw_data;
    };
}



#endif // OLEFILE_H
