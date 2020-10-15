#include "testExampleLibrary.h"
#include "testExampleLibrary2.h"

#include <QtTest/QtTest>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);

    QTEST_SET_MAIN_SOURCE_PATH

    int status = 0;
    auto EXECUTE_TEST = [&status, argc, argv](QObject* obj)
    {
        status |= QTest::qExec(obj, argc, argv);
        delete obj;
    };

    EXECUTE_TEST(new TestExampleLibrary());
    EXECUTE_TEST(new TestExampleLibrary2());

    return status;
}
