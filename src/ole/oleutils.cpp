#include "oleutils.h"
#include <algorithm>
#include <iostream>
#include <fstream>

std::vector<unsigned char> *OLE::split(std::vector<unsigned char> *data, int offset, int length, bool reverse)
{
    if(data->size() < offset + length){
        std::cerr << "Tried to read a vector of " << data->size() << " bytes from byte " << offset << " to " << offset + length << std::endl;
        return 0;
    }

    std::vector<unsigned char> *result = new std::vector<unsigned char>(data->begin() + offset, data->begin() + offset + length);

    //We need to reverse it in case it's little endian
    //We want the first byte of the vector to be least significant
    if(reverse)
        std::reverse(result->begin(), result->end());

    return result;
}

std::vector<unsigned char> OLE::join(std::vector<unsigned char> v1, std::vector<unsigned char> v2)
{
    std::vector<unsigned char> v(v1.size() + v2.size());
    v.insert(v.end(), v1.begin(), v1.end());
    v.insert(v.end(), v2.begin(), v2.end());
    return v;
}

unsigned short OLE::toUShort(std::vector<unsigned char> *data, bool reverse, int offset)
{
    unsigned short result = 0;
    int c_offset = 0;
    int l = offset;
    int h = offset + 2;

    if(reverse)
    {
        for(int i=h-1;i>=l;i--){
            result += (data->at(i) << c_offset);
            c_offset += 8;
        }
    }
    else
    {
        for(int i=l;i<h;i++){
            result += (data->at(i) << c_offset);
            c_offset += 8;
        }
    }
    return result;
}

unsigned long OLE::toULong(std::vector<unsigned char> *data, bool reverse, int offset)
{
    unsigned long result = 0;
    int c_offset = 0;

    int l = offset;
    int h = offset + 4;

    if(reverse)
    {
        for(int i=h-1;i>=l;i--){
            result += (data->at(i) << c_offset);
            c_offset += 8;
        }
    }
    else
    {
        for(int i=l;i<h;i++){
            result += (data->at(i) << c_offset);
            c_offset += 8;
        }
    }
    return result;
}

std::string OLE::toString(std::vector<unsigned char> *data, int offset, int length)
{
    std::string s;
    if(length < 0)
        s = std::string(data->begin() + offset, data->end());
    else
        s = std::string(data->begin() + offset, data->begin() + offset + length);

    return s;
}

std::vector<unsigned char> *OLE::readFile(std::string path)
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

    if(data.size() == 0)
    {
        std::cerr << "File " << path << " has returned 0 bytes" << std::endl;
    }

    std::vector<unsigned char> *bytes = new std::vector<unsigned char>(data.begin(), data.end());
    return bytes;
}
