#ifndef OLEMSAT_H
#define OLEMSAT_H

#include <vector>

namespace OLE
{
    class OLEFile;

    class OLEMSAT
    {
    public:
        OLEMSAT(OLEFile *file);
        void load();
        void addSecID(int id);

        int getSecId(int index);
        std::vector<int> getSecIds();

    private:
        OLEFile *file;

        std::vector<int> sec_ids;
    };

}

#endif // OLEMSAT_H
