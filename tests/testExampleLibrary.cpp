#include "testExampleLibrary.h"

#include "../library/exampleLibrary.h"

void TestExampleLibrary::testInitMessage()
{
    ExampleLibrary lib(this);
    QCOMPARE(lib.message_, "");
}

void TestExampleLibrary::testSetMessage()
{
    ExampleLibrary lib(this);
    lib.setMessage("xyz");
    QCOMPARE(lib.message_, "xyz");
}

QTEST_MAIN(TestExampleLibrary)
