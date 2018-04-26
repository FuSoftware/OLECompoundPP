#ifndef OLEUTILS_H
#define OLEUTILS_H

#include <vector>
#include <string>

namespace OLE
{
    enum SpecialSectorID
    {
        SECID_FREE = -1,
        SECID_EOC = -2,
        SECID_SAT = -3,
        SECID_MSAT = -4
    };

    std::vector<unsigned char> *split(std::vector<unsigned char> *data, int offset, int length, bool reverse = false);
    std::vector<unsigned char> join(std::vector<unsigned char> v1, std::vector<unsigned char> v2);

    unsigned short toUShort(std::vector<unsigned char> *data, bool reverse = false, int offset = 0);
    unsigned long toULong(std::vector<unsigned char> *data, bool reverse = false, int offset = 0);

    std::string toString(std::vector<unsigned char> *data, int offset = 0, int length = -1);

    std::vector<unsigned char> *readFile(std::string path);
}

#endif // OLEUTILS_H
