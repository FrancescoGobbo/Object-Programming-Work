#include "cbsensoremouse.h"

CBSensoreMouse::CBSensoreMouse(QWidget* parent):
    QComboBox (parent)
{
    addItem("Seleziona Sensore");
    addItem("ottico");
    addItem("laser");
}
