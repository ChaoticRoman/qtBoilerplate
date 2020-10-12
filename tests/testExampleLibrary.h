#ifndef TESTLIBRARY_H
#define TESTLIBRARY_H

#include <QObject>
#include <QtTest/QtTest>

class TestExampleLibrary : public QObject
{
    Q_OBJECT
private slots:
    void testInitMessage();
    void testSetMessage();
};

#endif // TESTLIBRARY_H
