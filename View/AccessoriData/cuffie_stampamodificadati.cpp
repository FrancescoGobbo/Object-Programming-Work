#include "cuffie_stampamodificadati.h"

Cuffie_StampaModificaDati::Cuffie_StampaModificaDati(QWidget *p):
    QWidget (p),
    datoMicrofonoA(new QLabel(this)),
    microfonoA(new QLabel("Microfono:",this)),
    datoRispostaInFrequenzaCuffieA(new QLabel(this)),
    rispostaInFrequenzaCuffieA(new QLabel("Risposta in frequenza Cuffie(Hz):",this)),
    datoImpedenzaA(new QLabel(this)),
    impedenzaA(new QLabel("Impedenza(Ohm):",this)),
    datoRispostaInFrequenzaMicrofonoA(new QLabel(this)),
    rispostaInFrequenzaMicrofonoA(new QLabel("Risposta in frequenza Microfono(Hz):",this)),
    datoSensibilitaMicrofonoA(new QLabel(this)),
    sensibilitaMicrofonoA(new QLabel("Sensibilità Microfono(dB):",this)),
    datoCancellazioneRumoreA(new QLabel(this)),
    cancellazioneRumoreA(new QLabel("Cancellazione rumore:",this)),
    datoSensibilitaCuffieA(new QLabel(this)),
    sensibilitaCuffieA(new QLabel("Sensibilità Cuffie(dB):",this)),
    datoPesoA(new QLabel(this)),
    PesoA(new QLabel("Peso(kg):",this)),

    modifica_microfono(new QCheckBox(this)),
    modifica_rifC(new QLineEdit(this)),
    modifica_impedenza(new QLineEdit(this)),
    modifica_rifM(new QLineEdit(this)),
    modifica_sensM(new QLineEdit(this)),
    modifica_cancellazRum(new QCheckBox(this)),
    modifica_sensC(new QLineEdit(this)),
    modifica_peso(new QDoubleSpinBox(this))
{
    QVBoxLayout *layoutDati = new QVBoxLayout(this);

    QGridLayout *cuffieDataGL = new QGridLayout;

    cuffieDataGL->addWidget(microfonoA,0,0);
    cuffieDataGL->addWidget(datoMicrofonoA,0,1);
    cuffieDataGL->addWidget(modifica_microfono,0,2);


    cuffieDataGL->addWidget(rispostaInFrequenzaCuffieA,1,0);
    cuffieDataGL->addWidget(datoRispostaInFrequenzaCuffieA,1,1);
    QValidator* vRifC = new QIntValidator(100, 50000, this);
    modifica_rifC->setValidator(vRifC);
    modifica_rifC->setPlaceholderText("(100-50000 Hz)");
    cuffieDataGL->addWidget(modifica_rifC,1,2);

    cuffieDataGL->addWidget(impedenzaA,2,0);
    cuffieDataGL->addWidget(datoImpedenzaA,2,1);
    QValidator* vImp = new QIntValidator(1, 250, this);
    modifica_impedenza->setValidator(vImp);
    modifica_impedenza->setPlaceholderText("(1-250 Ohm)");
    cuffieDataGL->addWidget(modifica_impedenza,2,2);


    cuffieDataGL->addWidget(sensibilitaCuffieA,3,0);
    cuffieDataGL->addWidget(datoSensibilitaCuffieA,3,1);
    QValidator* vSensC = new QIntValidator(10, 110, this);
    modifica_sensC->setValidator(vSensC);
    modifica_sensC->setPlaceholderText("(10-110 dB)");
    cuffieDataGL->addWidget(modifica_sensC,3,2);


    cuffieDataGL->addWidget(rispostaInFrequenzaMicrofonoA,4,0);
    cuffieDataGL->addWidget(datoRispostaInFrequenzaMicrofonoA,4,1);
    QValidator* vRifM = new QIntValidator(0, 20000, this);
    modifica_rifM->setValidator(vRifM);
    modifica_rifM->setPlaceholderText("(20-20000 Hz)");
    cuffieDataGL->addWidget(modifica_rifM,4,2);


    cuffieDataGL->addWidget(sensibilitaMicrofonoA,5,0);
    cuffieDataGL->addWidget(datoSensibilitaMicrofonoA,5,1);
    QValidator* vSensM = new QIntValidator(0, 124, this);
    modifica_sensM->setValidator(vSensM);
    modifica_sensM->setPlaceholderText("(40-124 dB)");
    cuffieDataGL->addWidget(modifica_sensM,5,2);


    cuffieDataGL->addWidget(cancellazioneRumoreA,6,0);
    cuffieDataGL->addWidget(datoCancellazioneRumoreA,6,1);
    cuffieDataGL->addWidget(modifica_cancellazRum,6,2);


    cuffieDataGL->addWidget(PesoA,7,0);
    cuffieDataGL->addWidget(datoPesoA,7,1);
    modifica_peso->setSuffix("kg");
    cuffieDataGL->addWidget(modifica_peso,7,2);

    cuffieDataGL->setSpacing(10);

    modifica_microfono->hide();
    modifica_rifC->hide();
    modifica_impedenza->hide();
    modifica_rifM->hide();
    modifica_sensM->hide();
    modifica_cancellazRum->hide();
    modifica_sensC->hide();
    modifica_peso->hide();

    layoutDati->addItem(cuffieDataGL);
    setLayout(layoutDati);

}

QLabel *Cuffie_StampaModificaDati::getDatoMic() const
{
    return datoMicrofonoA;
}

QLabel *Cuffie_StampaModificaDati::getDatoRIFC() const
{
    return datoRispostaInFrequenzaCuffieA;
}

QLabel *Cuffie_StampaModificaDati::getDatoImp() const
{
    return datoImpedenzaA;
}

QLabel *Cuffie_StampaModificaDati::getDatoRIFM() const
{
    return datoRispostaInFrequenzaMicrofonoA;
}

QLabel *Cuffie_StampaModificaDati::getDatoSM() const
{
    return datoSensibilitaMicrofonoA;
}

QLabel *Cuffie_StampaModificaDati::getDatoSC() const
{
    return datoSensibilitaCuffieA;
}

QLabel *Cuffie_StampaModificaDati::getDatoCR() const
{
    return datoCancellazioneRumoreA;
}

QLabel *Cuffie_StampaModificaDati::getDatoP() const
{
    return datoPesoA;
}

bool Cuffie_StampaModificaDati::getModifMicrofono() const
{
    return modifica_microfono->isChecked();
}

unsigned int Cuffie_StampaModificaDati::getModifRifC() const
{
    return modifica_rifC->text().toUInt();
}

unsigned int Cuffie_StampaModificaDati::getModifImpedenza() const
{
    return modifica_impedenza->text().toUInt();
}

unsigned int Cuffie_StampaModificaDati::getModifRifM() const
{
    return modifica_rifM->text().toUInt();
}

unsigned int Cuffie_StampaModificaDati::getModifSensM() const
{
    return modifica_sensM->text().toUInt();
}

bool Cuffie_StampaModificaDati::getModifCancellazRum() const
{
    return modifica_cancellazRum->isChecked();
}

unsigned int Cuffie_StampaModificaDati::getModifSensC() const
{
    return modifica_sensC->text().toUInt();
}

double Cuffie_StampaModificaDati::getModifPeso() const
{
    return modifica_peso->value();
}

bool Cuffie_StampaModificaDati::modifySomething()
{
    bool modificatoQualcosa=1;
    if(((getModifMicrofono()==0 && datoMicrofonoA->text()=="No") || (getModifMicrofono()==1 && datoMicrofonoA->text()=="Si"))&&
        getModifRifC()==0 && getModifImpedenza()==0 && getModifRifM()==0 && getModifSensM()==0 &&
        ((getModifCancellazRum()==0 && datoCancellazioneRumoreA->text()=="No") || (getModifCancellazRum()==1 && datoCancellazioneRumoreA->text()=="Si")) &&
        getModifSensC()==0 && getModifPeso()==0.00){
        modificatoQualcosa=0;
    }
    return modificatoQualcosa;
}

void Cuffie_StampaModificaDati::modifyNoMic()
{
    std::string zero="0";
    modifica_rifM->setText(QString::fromStdString(zero));
    modifica_sensM->setText(QString::fromStdString(zero));
}

void Cuffie_StampaModificaDati::showModificatori()
{
    datoMicrofonoA->hide();
    datoRispostaInFrequenzaCuffieA->hide();
    datoImpedenzaA->hide();
    datoRispostaInFrequenzaMicrofonoA->hide();
    datoSensibilitaMicrofonoA->hide();
    datoCancellazioneRumoreA->hide();
    datoSensibilitaCuffieA->hide();
    datoPesoA->hide();

    modifica_microfono->show();
    modifica_rifC->show();
    modifica_impedenza->show();
    modifica_rifM->show();
    modifica_sensM->show();
    modifica_cancellazRum->show();
    modifica_sensC->show();
    modifica_peso->show();
}

void Cuffie_StampaModificaDati::showDati()
{
    datoMicrofonoA->show();
    datoRispostaInFrequenzaCuffieA->show();
    datoImpedenzaA->show();
    datoRispostaInFrequenzaMicrofonoA->show();
    datoSensibilitaMicrofonoA->show();
    datoCancellazioneRumoreA->show();
    datoSensibilitaCuffieA->show();
    datoPesoA->show();

    modifica_microfono->hide();
    modifica_rifC->hide();
    modifica_impedenza->hide();
    modifica_rifM->hide();
    modifica_sensM->hide();
    modifica_cancellazRum->hide();
    modifica_sensC->hide();
    modifica_peso->hide();
}

void Cuffie_StampaModificaDati::slotReset()
{
    modifica_microfono->setChecked(false);
    modifica_rifC->setText("");
    modifica_impedenza->setText("");
    modifica_rifM->setText("");
    modifica_sensM->setText("");
    modifica_cancellazRum->setChecked(false);
    modifica_sensC->setText("");
    modifica_peso->setValue(0.00);
}
