#include "layoutquality.h"
#include <QIcon>
#include <QGroupBox>

LayoutQuality::LayoutQuality(QWidget *p):
    QWidget (p),
    accE (new QLabel(this)),
    accO (new QLabel(this)),
    accB (new QLabel(this)),
    accS (new QLabel(this)),
    accP (new QLabel(this))
{
    QVBoxLayout* layoutquality= new QVBoxLayout();

    QVBoxLayout* layoutq= new QVBoxLayout;

    QGridLayout* gQualita= new QGridLayout;

    QLabel* phEcc = new QLabel(this);
    QIcon iE = QIcon(":/img/IMG/eccellente.png");
    QPixmap logE = iE.pixmap(QSize(80, 80));
    phEcc->setPixmap(logE);

    QLabel* phOtt = new QLabel(this);
    QIcon iO = QIcon (":/img/IMG/ottimo.png");
    QPixmap logO = iO.pixmap(QSize(80, 80));
    phOtt->setPixmap(logO);

    QLabel* phBuo = new QLabel(this);
    QIcon iB = QIcon (":/img/IMG/buono.png");
    QPixmap logB = iB.pixmap(QSize(80, 80));
    phBuo->setPixmap(logB);

    QLabel* phSuff = new QLabel(this);
    QIcon iS = QIcon (":/img/IMG/sufficiente.png");
    QPixmap logS = iS.pixmap(QSize(80, 80));
    phSuff->setPixmap(logS);

    QLabel* phP = new QLabel(this);
    QIcon iP = QIcon (":/img/IMG/pessimo.png");
    QPixmap logP = iP.pixmap(QSize(80, 80));
    phP->setPixmap(logP);

    gQualita->addWidget(phEcc,0,0);
    gQualita->addWidget(accE,0,1);
    gQualita->addWidget(phOtt,1,0);
    gQualita->addWidget(accO,1,1);
    gQualita->addWidget(phBuo,2,0);
    gQualita->addWidget(accB,2,1);
    gQualita->addWidget(phSuff,3,0);
    gQualita->addWidget(accS,3,1);
    gQualita->addWidget(phP,4,0);
    gQualita->addWidget(accP,4,1);

    gQualita->setVerticalSpacing(30);

    layoutq->addItem(gQualita);

    QGroupBox* GBQual = new QGroupBox(tr("Qualità"));
    GBQual->setLayout(layoutq);
    layoutquality->addWidget(GBQual);

    //setFixedSize(230,200);

    setLayout(layoutquality);
}

QLabel* LayoutQuality::slotAccEcc() const
{
    return accE;
}

QLabel* LayoutQuality::slotAccOtt() const
{
    return accO;
}

QLabel* LayoutQuality::slotAccBuo() const
{
    return accB;
}

QLabel* LayoutQuality::slotAccSuff() const
{
    return accS;
}

QLabel* LayoutQuality::slotAccPes() const
{
    return accP;
}
