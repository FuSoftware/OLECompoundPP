#include <iostream>
#include <vector>
#include "ole/oleutils.h"
#include "ole/oleheader.h"
#include "ole/olemsat.h"
#include "ole/olefile.h"

void testFile(std::string path)
{
    OLE::OLEFile *f = new OLE::OLEFile(path);
    std::cout << f->getHeader()->getRevision() << " : " <<  f->getHeader()->getVersion() << std::endl;
}

int main()
{
    //testFile("E:\\Prog\\Data\\Syno\\C_DRAIN.grf");
    testFile("/home/florent/Prog/Data/Syno/C_DRAIN.grf");
    return 0;
}
