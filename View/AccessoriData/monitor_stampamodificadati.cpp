#include "monitor_stampamodificadati.h"

Monitor_StampaModificaDati::Monitor_StampaModificaDati(QWidget *p):
    QWidget (p),
    datoRisoluzioneA(new QLabel(this)),
    risoluzioneA(new QLabel("Risoluzione:",this)),
    datoRapportoDAspettoA(new QLabel(this)),
    rapportoDAspettoA(new QLabel("Rapporto d'aspetto:",this)),
    datoPolliciA(new QLabel(this)),
    polliciA(new QLabel("Pollici:",this)),
    datoRefreshRateA(new QLabel(this)),
    refreshRateA(new QLabel("Refresh Rate(msec):",this)),
    datoFrameRateA(new QLabel(this)),
    frameRateA(new QLabel("Frame Rate(Hz):",this)),
    datoFreeSyncA(new QLabel(this)),
    freeSyncA(new QLabel("Free-Sync:",this)),
    datoGSyncA(new QLabel(this)),
    gSyncA(new QLabel("G-Sync:",this)),
    datoDynamicRangeA(new QLabel(this)),
    dynamicRangeA(new QLabel("Dynamic Range:",this)),
    datoCasseA(new QLabel(this)),
    casseA(new QLabel("Casse:",this)),

    modifica_risoluzione(new CBRisoluzioneMonitor(this)),
    modifica_rappDAsp(new CBRapportDAspettoMonitor(this)),
    modifica_pollici(new QDoubleSpinBox(this)),
    modifica_refreshRate(new QLineEdit(this)),
    modifica_frameRate(new QLineEdit(this)),
    modifica_freeSync(new QCheckBox(this)),
    modifica_gSync(new QCheckBox(this)),
    modifica_dynamicRange(new CBDR(this)),
    modifica_casse(new QCheckBox(this))
{
    QVBoxLayout *layoutDati = new QVBoxLayout(this);

    QGridLayout *monitorDataGL = new QGridLayout;

    monitorDataGL->addWidget(risoluzioneA,0,0);
    monitorDataGL->addWidget(datoRisoluzioneA,0,1);
    monitorDataGL->addWidget(modifica_risoluzione,0,2);

    monitorDataGL->addWidget(rapportoDAspettoA,1,0);
    monitorDataGL->addWidget(datoRapportoDAspettoA,1,1);
    monitorDataGL->addWidget(modifica_rappDAsp,1,2);

    monitorDataGL->addWidget(polliciA,2,0);
    monitorDataGL->addWidget(datoPolliciA,2,1);
    monitorDataGL->addWidget(modifica_pollici,2,2);

    monitorDataGL->addWidget(refreshRateA,3,0);
    monitorDataGL->addWidget(datoRefreshRateA,3,1);
    QValidator* vRR = new QIntValidator(1, 5, this);
    modifica_refreshRate->setValidator(vRR);
    modifica_refreshRate->setPlaceholderText("(1-5 msec)");
    monitorDataGL->addWidget(modifica_refreshRate,3,2);

    monitorDataGL->addWidget(frameRateA,4,0);
    monitorDataGL->addWidget(datoFrameRateA,4,1);
    QValidator* vFR = new QIntValidator(30, 240, this);
    modifica_frameRate->setValidator(vFR);
    modifica_frameRate->setPlaceholderText("(30-240 Hz)");
    monitorDataGL->addWidget(modifica_frameRate,4,2);

    monitorDataGL->addWidget(freeSyncA,5,0);
    monitorDataGL->addWidget(datoFreeSyncA,5,1);
    monitorDataGL->addWidget(modifica_freeSync,5,2);

    monitorDataGL->addWidget(gSyncA,6,0);
    monitorDataGL->addWidget(datoGSyncA,6,1);
    monitorDataGL->addWidget(modifica_gSync,6,2);

    monitorDataGL->addWidget(dynamicRangeA,7,0);
    monitorDataGL->addWidget(datoDynamicRangeA,7,1);
    monitorDataGL->addWidget(modifica_dynamicRange,7,2);

    monitorDataGL->addWidget(casseA,8,0);
    monitorDataGL->addWidget(datoCasseA,8,1);
    monitorDataGL->addWidget(modifica_casse,8,2);

    monitorDataGL->setSpacing(10);

    modifica_risoluzione->hide();
    modifica_rappDAsp->hide();
    modifica_pollici->hide();
    modifica_refreshRate->hide();
    modifica_frameRate->hide();
    modifica_freeSync->hide();
    modifica_gSync->hide();
    modifica_dynamicRange->hide();
    modifica_casse->hide();

    layoutDati->addItem(monitorDataGL);
    setLayout(layoutDati);
}

QLabel *Monitor_StampaModificaDati::getDatoRis() const
{
    return datoRisoluzioneA;
}

QLabel *Monitor_StampaModificaDati::getDatoRDA() const
{
    return datoRapportoDAspettoA;
}

QLabel *Monitor_StampaModificaDati::getDatoPol() const
{
    return datoPolliciA;
}

QLabel *Monitor_StampaModificaDati::getDatoRR() const
{
    return datoRefreshRateA;
}

QLabel *Monitor_StampaModificaDati::getDatoFR() const
{
    return datoFrameRateA;
}

QLabel *Monitor_StampaModificaDati::getDatoFS() const
{
    return datoFreeSyncA;
}

QLabel *Monitor_StampaModificaDati::getDatoGS() const
{
    return datoGSyncA;
}

QLabel *Monitor_StampaModificaDati::getDatoDR() const
{
    return datoDynamicRangeA;
}

QLabel *Monitor_StampaModificaDati::getDatoCas() const
{
    return datoCasseA;
}

std::string Monitor_StampaModificaDati::getModifRisoluzione() const
{
    std::string r;
    if(modifica_risoluzione->currentIndex()!=0)
        r=modifica_risoluzione->currentText().toStdString();
    /*switch(modifica_risoluzione->currentIndex()){
    case 1:
        r="1280×720";
    case 2:
        r="1360×768";
    case 3:
        r="1366×768";
    case 4:
        r="1920×1080";
    case 5:
        r="2048×1080";
    case 6:
        r="4096×2160";
    case 7:
        r="7680×4320";
    }*/
    return r;
}

std::string Monitor_StampaModificaDati::getModifRappDAsp() const
{
    std::string r;
    if(modifica_rappDAsp->currentIndex()!=0)
        r=modifica_rappDAsp->currentText().toStdString();
    /*switch(modifica_rappDAsp->currentIndex()){
    case 1:
        r="16:9";
    case 2:
        r="1,8962:1";
    }*/
    return r;
}

double Monitor_StampaModificaDati::getModifPollici() const
{
    return modifica_pollici->value();
}

unsigned int Monitor_StampaModificaDati::getModifRefreshRate() const
{
    return modifica_refreshRate->text().toUInt();
}

unsigned int Monitor_StampaModificaDati::getModifFrameRate() const
{
    return modifica_frameRate->text().toUInt();
}

bool Monitor_StampaModificaDati::getModifFreeSync() const
{
    return modifica_freeSync->isChecked();
}

bool Monitor_StampaModificaDati::getModifGSync() const
{
    return modifica_gSync->isChecked();
}

std::string Monitor_StampaModificaDati::getModifDynamicRange() const
{
    std::string r;
    if(modifica_dynamicRange->currentIndex()!=0)
        r=modifica_dynamicRange->currentText().toStdString();
    /*switch(modifica_dynamicRange->currentIndex()){
    case 1:
        r="DR";
    case 2:
        r="HDR";
    }*/
    return r;
}

bool Monitor_StampaModificaDati::getModifCasse() const
{
    return modifica_casse->isChecked();
}

bool Monitor_StampaModificaDati::modifySomething()
{
    bool modificatoQualcosa=1;
    if(modifica_risoluzione->currentIndex()==0 && modifica_rappDAsp->currentIndex()==0 && getModifPollici()==0.00 &&
       getModifRefreshRate()==0 && getModifFrameRate()==0 &&
       ((getModifFreeSync()==0 && datoFreeSyncA->text()=="No") || (getModifFreeSync()==1 && datoFreeSyncA->text()=="Si"))&&
       ((getModifGSync()==0 && datoGSyncA->text()=="No") || (getModifGSync()==1 && datoGSyncA->text()=="Si"))&&
       modifica_dynamicRange->currentIndex()==0 &&
       ((getModifCasse()==0 && datoCasseA->text()=="No") || (getModifCasse()==1 && datoCasseA->text()=="Si")))
               modificatoQualcosa=0;
    return modificatoQualcosa;
}

void Monitor_StampaModificaDati::showModificatori()
{
    datoRisoluzioneA->hide();
    datoRapportoDAspettoA->hide();
    datoPolliciA->hide();
    datoRefreshRateA->hide();
    datoFrameRateA->hide();
    datoFreeSyncA->hide();
    datoGSyncA->hide();
    datoDynamicRangeA->hide();
    datoCasseA->hide();

    modifica_risoluzione->show();
    modifica_rappDAsp->show();
    modifica_pollici->show();
    modifica_refreshRate->show();
    modifica_frameRate->show();
    modifica_freeSync->show();
    modifica_gSync->show();
    modifica_dynamicRange->show();
    modifica_casse->show();
}

void Monitor_StampaModificaDati::showDati()
{
    datoRisoluzioneA->show();
    datoRapportoDAspettoA->show();
    datoPolliciA->show();
    datoRefreshRateA->show();
    datoFrameRateA->show();
    datoFreeSyncA->show();
    datoGSyncA->show();
    datoDynamicRangeA->show();
    datoCasseA->show();

    modifica_risoluzione->hide();
    modifica_rappDAsp->hide();
    modifica_pollici->hide();
    modifica_refreshRate->hide();
    modifica_frameRate->hide();
    modifica_freeSync->hide();
    modifica_gSync->hide();
    modifica_dynamicRange->hide();
    modifica_casse->hide();
}

void Monitor_StampaModificaDati::slotReset()
{
    modifica_risoluzione->setCurrentIndex(0);
    modifica_rappDAsp->setCurrentIndex(0);
    modifica_pollici->setValue(0.00);
    modifica_refreshRate->setText("");
    modifica_frameRate->setText("");
    modifica_freeSync->setChecked(false);
    modifica_gSync->setChecked(false);
    modifica_dynamicRange->setCurrentIndex(0);
    modifica_casse->setChecked(false);
}
