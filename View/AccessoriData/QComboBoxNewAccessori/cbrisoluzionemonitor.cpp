#include "cbrisoluzionemonitor.h"

CBRisoluzioneMonitor::CBRisoluzioneMonitor(QWidget* parent) :
    QComboBox (parent)
{
    addItem("Seleziona Risoluzione");
    addItem("1280×720");
    addItem("1360×768");
    addItem("1366×768");
    addItem("1920×1080");
    addItem("2048×1080");
    addItem("4096×2160");
    addItem("7680×4320");
}
