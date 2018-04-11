#ifndef OLEUTILS_H
#define OLEUTILS_H

#include <vector>
#include <string>

namespace OLE
{
    std::vector<unsigned char> split(std::vector<unsigned char> data, int offset, int length, bool reverse = false);
    std::vector<unsigned char> join(std::vector<unsigned char> v1, std::vector<unsigned char> v2);

    int toInt(std::vector<unsigned char> data);
    std::string toString(std::vector<unsigned char> data);

    std::vector<unsigned char> readFile(std::string path);
}

#endif // OLEUTILS_H
