#include "cbcategoriatastiera.h"

CBCategoriaTastiera::CBCategoriaTastiera(QWidget* parent) :
    QComboBox (parent)
{
    addItem("Seleziona categoria");
    addItem("meccanica");
    addItem("membrana");
}
