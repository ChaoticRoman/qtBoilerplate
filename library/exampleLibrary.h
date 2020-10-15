#ifndef EXAMPLELIBRARY_H
#define EXAMPLELIBRARY_H

#include <QObject>
#include <QString>
#include <QTimerEvent>

class ExampleLibrary : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ExampleLibrary)
    friend class TestExampleLibrary;

public:
    ExampleLibrary(QObject *parent = nullptr);
    ~ExampleLibrary() = default;
    ExampleLibrary(ExampleLibrary&&) = delete;
    ExampleLibrary& operator=(ExampleLibrary&&) = delete;

    QString message() const;

public slots:
    void setMessage(QString message = "");

signals:
    void tick(QString message) const;

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    QString message_ = "";

    bool timerStarted_ = false;
    int timerId_;
};

#endif // EXAMPLELIBRARY_H
