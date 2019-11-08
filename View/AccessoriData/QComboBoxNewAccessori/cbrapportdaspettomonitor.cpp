#include "cbrapportdaspettomonitor.h"

CBRapportDAspettoMonitor::CBRapportDAspettoMonitor(QWidget* parent) :
    QComboBox (parent)
{
    addItem("Seleziona Rapport d'Aspetto");
    addItem("16:9");
    addItem("1,8962:1");
}
