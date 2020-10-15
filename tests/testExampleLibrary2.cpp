#include "testExampleLibrary2.h"

#include "../library/exampleLibrary.h"

void TestExampleLibrary2::testInitMessage()
{
    ExampleLibrary lib(this);
    QCOMPARE(lib.message(), "");
}

void TestExampleLibrary2::testSetMessage()
{
    ExampleLibrary lib(this);
    lib.setMessage("xyz");
    QCOMPARE(lib.message(), "xyz");
}

