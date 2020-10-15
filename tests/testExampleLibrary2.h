#ifndef TESTLIBRARY2_H
#define TESTLIBRARY2_H

#include <QObject>
#include <QtTest/QtTest>

class TestExampleLibrary2 : public QObject
{
    Q_OBJECT

private slots:
    void testInitMessage();
    void testSetMessage();
};

#endif // TESTLIBRARY2_H
