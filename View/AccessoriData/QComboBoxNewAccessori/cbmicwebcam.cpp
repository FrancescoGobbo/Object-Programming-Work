#include "cbmicwebcam.h"

CBMicWebcam::CBMicWebcam(QWidget* parent):
    QComboBox (parent)
{
    addItem("Seleziona tipo Microfono");
    addItem("omnidirezionale");
    addItem("monodirezionale");
}
