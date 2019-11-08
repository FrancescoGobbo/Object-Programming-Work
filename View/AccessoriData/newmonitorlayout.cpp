#include "newmonitorlayout.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QValidator>

NewMonitorLayout::NewMonitorLayout(QWidget *p):
    QWidget (p),
    risoluzione(new CBRisoluzioneMonitor(this)),
    rappDAsp(new CBRapportDAspettoMonitor(this)),
    pollici(new QDoubleSpinBox(this)),
    refreshRate(new QLineEdit(this)),
    frameRate(new QLineEdit(this)),
    freeSync(new QCheckBox("Free-Sync", this)),
    gSync(new QCheckBox("G-Sync", this)),
    dynamicRange(new CBDR(this)),
    casse(new QCheckBox("Casse", this))
{
    QVBoxLayout *layoutMonitor = new QVBoxLayout();

    QGridLayout *grindRisoluzione = new QGridLayout;
    QLabel* text1 = new QLabel("Risoluzione");
    grindRisoluzione->addWidget(text1,0,0);
    grindRisoluzione->addWidget(risoluzione,0,1);
    layoutMonitor->addItem(grindRisoluzione);

    QGridLayout *grindRDA = new QGridLayout;
    QLabel* text2 = new QLabel("Rapporto d'aspetto");
    grindRDA->addWidget(text2,0,0);
    grindRDA->addWidget(rappDAsp,0,1);
    layoutMonitor->addItem(grindRDA);

    pollici->setPrefix("Pollici   ");
    layoutMonitor->addWidget(pollici);

    QValidator* vRR = new QIntValidator(1, 5, this);
    refreshRate->setValidator(vRR);
    refreshRate->setPlaceholderText("Refresh Rate   (1-5 msec)");
    layoutMonitor->addWidget(refreshRate);

    QValidator* vFR = new QIntValidator(30, 240, this);
    frameRate->setValidator(vFR);
    frameRate->setPlaceholderText("Frame Rate (30-240 Hz)");
    layoutMonitor->addWidget(frameRate);

    QGridLayout *grindSync = new QGridLayout;
    grindSync->addWidget(freeSync,0,0);
    grindSync->addWidget(gSync,0,1);
    layoutMonitor->addItem(grindSync);

    QGridLayout *grindDynamicRange = new QGridLayout;
    QLabel* text3 = new QLabel("Dynamic Range");
    grindDynamicRange->addWidget(text3,0,0);
    grindDynamicRange->addWidget(dynamicRange,0,1);
    layoutMonitor->addItem(grindDynamicRange);

    layoutMonitor->addWidget(casse);

    setLayout(layoutMonitor);
}

CBRisoluzioneMonitor *NewMonitorLayout::getRisoluzione() const
{
    return risoluzione;
}

std::string NewMonitorLayout::getRisoluzionetxt() const
{
    std::string r;
    if(risoluzione->currentIndex()!=0)
        r=risoluzione->currentText().toStdString();
    return r;
}

CBRapportDAspettoMonitor *NewMonitorLayout::getRappDAsp() const
{
    return rappDAsp;
}

std::string NewMonitorLayout::getRappDAsptxt() const
{
    std::string r;
    if(rappDAsp->currentIndex()!=0)
        r=rappDAsp->currentText().toStdString();
    return r;
}

double NewMonitorLayout::getPollici() const
{
    return pollici->value();
}

unsigned int NewMonitorLayout::getRefreshRate() const
{
    return refreshRate->text().toUInt();
}

unsigned int NewMonitorLayout::getFrameRate() const
{
    return frameRate->text().toUInt();
}

bool NewMonitorLayout::getFreeSync() const
{
    return freeSync->isChecked();
}

bool NewMonitorLayout::getGSync() const
{
    return gSync->isChecked();
}

CBDR *NewMonitorLayout::getDynamicRange() const
{
    return dynamicRange;
}

std::string NewMonitorLayout::getDynamicRangetxt() const
{
    std::string r;
    if(dynamicRange->currentIndex()!=0)
        r=dynamicRange->currentText().toStdString();
    return r;
}

bool NewMonitorLayout::getCasse() const
{
    return casse->isChecked();
}

void NewMonitorLayout::slotResetMonitor() const
{
    risoluzione->setCurrentIndex(0);
    rappDAsp->setCurrentIndex(0);
    pollici->setValue(0.00);
    refreshRate->setText("");
    frameRate->setText("");
    freeSync->setChecked(false);
    gSync->setChecked(false);
    dynamicRange->setCurrentIndex(0);
    casse->setChecked(false);
}
