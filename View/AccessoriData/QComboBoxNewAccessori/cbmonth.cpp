#include "cbmonth.h"

CBMonth::CBMonth(QWidget* parent):
    QComboBox(parent)
{
    addItem("Mese d'uscita");
    addItem("Gennaio");
    addItem("Febbraio");
    addItem("Marzo");
    addItem("Aprile");
    addItem("Maggio");
    addItem("Giugno");
    addItem("Luglio");
    addItem("Agosto");
    addItem("Settembre");
    addItem("Ottobre");
    addItem("Novembre");
    addItem("Dicembre");
}
