#include "oleutils.h"
#include <algorithm>
#include <iostream>
#include <fstream>

std::vector<unsigned char> OLE::split(std::vector<unsigned char> data, int offset, int length, bool reverse)
{
    if(data.size() < offset + length){
        std::cerr << "Tried to read a vector of " << data.size() << " bytes from byte " << offset << " to " << offset + length << std::endl;
        std::vector<unsigned char> result;
        return result;
    }

    std::vector<unsigned char> result(data.begin() + offset, data.begin() + offset + length);

    //We need to reverse it in case it's little endian
    //We want the first byte of the vector to be least significant
    if(reverse)
        std::reverse(result.begin(), result.end());

    return result;
}

std::vector<unsigned char> OLE::join(std::vector<unsigned char> v1, std::vector<unsigned char> v2)
{
    std::vector<unsigned char> v(v1.size() + v2.size());
    v.insert(v.end(), v1.begin(), v1.end());
    v.insert(v.end(), v2.begin(), v2.end());
    return v;
}

int OLE::toInt(std::vector<unsigned char> data)
{
    int result = 0;
    int offset = 0;

    for(int i=0;i<data.size();i++){
        result += (data[i] << offset);
        offset += 8;
    }

    return result;
}

std::string OLE::toString(std::vector<unsigned char> data)
{
    std::string s(data.begin(), data.end());
    return s;
}


std::vector<unsigned char> OLE::readFile(std::string path)
{
    std::vector<char> data;
    std::streampos size;

    std::ifstream file(path, std::ios::in|std::ios::binary|std::ios::ate);

    if (file.is_open())
    {
        size = file.tellg();
        data.resize(size);
        file.seekg (0, std::ios::beg);
        file.read (&data[0], size);
        file.close();
    }

    std::vector<unsigned char> bytes(data.begin(), data.end());
    return bytes;
}
