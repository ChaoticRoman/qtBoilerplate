#ifndef TESTLIBRARY_H
#define TESTLIBRARY_H

#include <QObject>
#include <QtTest/QtTest>

class testExampleLibrary : public QObject
{
    Q_OBJECT
private slots:
    void testSetMessage();
};

#endif // TESTLIBRARY_H
