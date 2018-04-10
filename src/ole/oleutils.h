#ifndef OLEUTILS_H
#define OLEUTILS_H

#include <vector>
#include <string>

namespace OLE
{
    std::vector<unsigned char> split(std::vector<unsigned char> data, int offset, int length, bool reverse = false);
    int toInt(std::vector<unsigned char> data);

    std::vector<unsigned char> readFile(std::string path);
}

#endif // OLEUTILS_H
