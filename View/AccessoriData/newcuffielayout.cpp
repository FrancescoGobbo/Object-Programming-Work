#include "newcuffielayout.h"

#include <QVBoxLayout>
#include <QValidator>

NewCuffieLayout::NewCuffieLayout(QWidget *p):
    QWidget (p),
    microfono(new QCheckBox("Microfono",this)),
    rifC(new QLineEdit(this)),
    impedenza(new QLineEdit(this)),
    rifM(new QLineEdit(this)),
    sensM(new QLineEdit(this)),
    cancellazRum(new QCheckBox("Cancellazione Rumore",this)),
    sensC(new QLineEdit(this)),
    peso(new QDoubleSpinBox(this))
{
    QVBoxLayout *layoutCuffie = new QVBoxLayout();

    layoutCuffie->addWidget(microfono);

    QValidator* vRifC = new QIntValidator(100, 50000, this);
    rifC->setValidator(vRifC);
    rifC->setPlaceholderText("Risposta in frequenza Cuffie  (100-50000 Hz)");
    layoutCuffie->addWidget(rifC);

    QValidator* vImp = new QIntValidator(1, 250, this);
    impedenza->setValidator(vImp);
    impedenza->setPlaceholderText("Impedenza    (1-250 Ohm)");
    layoutCuffie->addWidget(impedenza);

    QValidator* vRifM = new QIntValidator(0, 20000, this);
    rifM->setValidator(vRifM);
    rifM->setPlaceholderText("Risposta in frequenza Microfono   (20-20000 Hz)");
    rifM->setEnabled(false);
    layoutCuffie->addWidget(rifM);

    QValidator* vSensM = new QIntValidator(0, 124, this);
    sensM->setValidator(vSensM);
    sensM->setPlaceholderText("Sensibilità Microfono    (40-124 dB)");
    layoutCuffie->addWidget(sensM);
    sensM->setEnabled(false);
    layoutCuffie->addWidget(cancellazRum);

    QValidator* vSensC = new QIntValidator(10, 110, this);
    sensC->setValidator(vSensC);
    sensC->setPlaceholderText("Sensibilità Cuffie   (10-110 dB)");
    layoutCuffie->addWidget(sensC);

    peso->setSuffix("kg");
    peso->setPrefix("Peso:  ");
    layoutCuffie->addWidget(peso);

    setLayout(layoutCuffie);
    connect(microfono,SIGNAL(clicked()),this,SLOT(slotDisableMic()));
}

bool NewCuffieLayout::getMicrofono() const
{
    return microfono->isChecked();
}

unsigned int NewCuffieLayout::getRifC() const
{
    return rifC->text().toUInt();
}

unsigned int NewCuffieLayout::getImpedenza() const
{
    return impedenza->text().toUInt();
}

unsigned int NewCuffieLayout::getRifM() const
{
        return rifM->text().toUInt();
}

unsigned int NewCuffieLayout::getSensM() const
{
    return sensM->text().toUInt();
}

bool NewCuffieLayout::getCancellazRum() const
{
    return cancellazRum->isChecked();
}

unsigned int NewCuffieLayout::getSensC() const
{
    return sensC->text().toUInt();
}

double NewCuffieLayout::getPeso() const
{
    return peso->value();
}

void NewCuffieLayout::slotDisableMic() const
{
    if(microfono->isChecked()){
        rifM->setEnabled(true);
        sensM->setEnabled(true);
    }
    else{
        rifM->setEnabled(false);
        sensM->setEnabled(false);
    }
}

void NewCuffieLayout::slotResetCuffie() const
{
    microfono->setChecked(false);
    rifC->setText("");
    impedenza->setText("");
    rifM->setText("");
    sensM->setText("");
    cancellazRum->setChecked(false);
    sensC->setText("");
    peso->setValue(0.00);
}
