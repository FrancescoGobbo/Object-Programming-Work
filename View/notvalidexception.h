#ifndef NOTVALIDEXCEPTION_H
#define NOTVALIDEXCEPTION_H

#include <QString>

class NotValidException
{
private:
    QString error;
public:
    NotValidException(QString ="");

    QString getError()const;
};

#endif // NOTVALIDEXCEPTION_H
