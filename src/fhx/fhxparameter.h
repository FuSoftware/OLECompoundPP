#ifndef FHXPARAMETER_H
#define FHXPARAMETER_H

#include <string>
#include <vector>

namespace FHX
{

class FHXParameter
{
public:
    FHXParameter(std::string data);

private:
    std::string name;
    std::vector<unsigned char> data;
};
}

#endif // FHXPARAMETER_H
