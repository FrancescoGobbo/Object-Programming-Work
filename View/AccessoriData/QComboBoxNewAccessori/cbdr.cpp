#include "cbdr.h"

CBDR::CBDR(QWidget* parent) :
    QComboBox (parent)
{
    addItem("Seleziona Dynamic Range");
    addItem("DR");
    addItem("HDR");
}
