#include <iostream>
#include <vector>
#include "ole/oleutils.h"
#include "ole/oleheader.h"
#include "ole/olemsat.h"
#include "ole/olefile.h"

#include "fhx/fhxfile.h"

void testFile(std::string path)
{
    OLE::OLEFile *f = new OLE::OLEFile(path);
    std::cout << f->getHeader()->getRevision() << " : " <<  f->getHeader()->getVersion() << std::endl;
}

void testFhx(std::string path)
{
    FHX::FHXFile *f = new FHX::FHXFile(path);
}

int main()
{
    //testFile("E:\\Prog\\Data\\Syno\\C_DRAIN.grf");
    //testFile("/home/florent/Prog/Data/Syno/C_DRAIN.grf");
    //testFhx("D:\\Prog\\Data\\CHARM S21.fhx");
    testFhx("D:\\Prog\\Data\\CLM_041217.fhx");

    return 0;
}
