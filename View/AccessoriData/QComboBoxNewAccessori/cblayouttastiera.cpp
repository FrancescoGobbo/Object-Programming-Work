#include "cblayouttastiera.h"

CBLayoutTastiera::CBLayoutTastiera(QWidget* parent) :
    QComboBox (parent)
{
    addItem("Seleziona Layout");
    addItem("Layout US (Internazionale)");
    addItem("Layout UK");
    addItem("Layout tedesco");
    addItem("Layout francese");
    addItem("Layout UE");
}
