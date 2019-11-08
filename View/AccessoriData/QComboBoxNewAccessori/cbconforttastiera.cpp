#include "cbconforttastiera.h"

CBConfortTastiera::CBConfortTastiera(QWidget* parent) :
    QComboBox (parent)
{
    addItem("Seleziona confort");
    addItem("eccezionale");
    addItem("ottima");
    addItem("buona");
    addItem("sufficiente");
    addItem("pessima");
}
