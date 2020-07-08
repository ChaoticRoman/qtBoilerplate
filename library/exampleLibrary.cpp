#include "exampleLibrary.h"

#include <QDebug>

ExampleLibrary::ExampleLibrary(QObject *parent) : QObject(parent) {}

void ExampleLibrary::set_message(QString message) {
    message_ = message;
    if (message.isEmpty()) {
        if  (timerStarted_) {
            killTimer(timerId_);
            timerStarted_ = false;
        }
    }
    else {
        timerId_ = startTimer(100);
        timerStarted_ = true;
    }
}

void ExampleLibrary::timerEvent(QTimerEvent *event) {
    event->accept();
    emit tick(message_);
}
