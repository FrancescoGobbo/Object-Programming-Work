#ifndef CBMICWEBCAM_H
#define CBMICWEBCAM_H

#include <QComboBox>
#include <QWidget>

class CBMicWebcam : public QComboBox
{
    Q_OBJECT
public:
    CBMicWebcam(QWidget * = nullptr);
};

#endif // CBMICWEBCAM_H
