#ifndef EXAMPLELIBRARY_H
#define EXAMPLELIBRARY_H

#include <QObject>
#include <QString>
#include <QTimerEvent>

class ExampleLibrary : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ExampleLibrary)

public:
    explicit ExampleLibrary(QObject *parent = nullptr);
    virtual ~ExampleLibrary() = default;
    ExampleLibrary(ExampleLibrary&&) = delete;
    ExampleLibrary& operator=(ExampleLibrary&&) = delete;

public slots:
    void set_message(QString message = "");

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
