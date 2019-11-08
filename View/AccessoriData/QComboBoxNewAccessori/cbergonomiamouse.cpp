#include "cbergonomiamouse.h"

CBErgonomiaMouse::CBErgonomiaMouse(QWidget* parent):
    QComboBox (parent)
{
    addItem("Seleziona Ergonomia");
    addItem("verticale");
    addItem("orizzontale");
}
