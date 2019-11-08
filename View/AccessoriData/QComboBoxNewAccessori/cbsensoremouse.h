#ifndef CBSENSOREMOUSE_H
#define CBSENSOREMOUSE_H

#include <QComboBox>
#include <QWidget>

class CBSensoreMouse : public QComboBox
{
    Q_OBJECT
public:
    CBSensoreMouse(QWidget * = nullptr);
};

#endif // CBSENSOREMOUSE_H
