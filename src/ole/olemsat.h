#ifndef OLEMSAT_H
#define OLEMSAT_H

#include <vector>

namespace OLE
{
    enum SpecialSectorID
    {
        SECID_FREE = -1,
        SECID_EOC = -2,
        SECID_SAT = -3,
        SECID_MSAT = -4
    };

    class OLEFile;

    class OLEMSAT
    {
    public:
        OLEMSAT(OLEFile *file);
        void load();
        void addSecID(int id);

    private:
        OLEFile *file;

        std::vector<int> sec_ids;
    };

}

#endif // OLEMSAT_H
