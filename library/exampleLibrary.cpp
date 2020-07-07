#include "exampleLibrary.h"

#include <QDebug>

ExampleLibrary::ExampleLibrary(QObject *parent) : QObject(parent)
{
    Q_UNUSED(parent)
}


ExampleLibrary::~ExampleLibrary() {}


void ExampleLibrary::set_message(QString message)
{
    message_ = message;
    if (message.isEmpty())
    {
        if  (timerStarted_)
        {
            killTimer(timerId_);
            timerStarted_ = false;
        }
    }
    else
    {
        timerId_ = startTimer(100);
        timerStarted_ = true;
    }
}


void ExampleLibrary::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    emit tick(message_);
}

#include "moc_exampleLibrary.cpp"
