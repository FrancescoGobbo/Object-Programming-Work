#include "notvalidexception.h"

NotValidException::NotValidException(QString e):
    error(e){}

QString NotValidException::getError() const
{
    return error;
}
