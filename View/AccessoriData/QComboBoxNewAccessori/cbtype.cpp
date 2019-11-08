#include "cbtype.h"

CBType::CBType(QWidget* parent):
    QComboBox (parent)
{
    addItem("Tipo di Accessorio");
    addItem("Cuffie");
    addItem("Monitor");
    addItem("Mouse");
    addItem("Tastiera");
    addItem("Webcam");
}
