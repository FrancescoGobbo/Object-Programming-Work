#include "layoutresearch.h"

#include <QGroupBox>

LayoutResearch::LayoutResearch(QWidget *p):
    QWidget (p),
    tipo(new CBType(this)),
    nome(new QLineEdit(this)),
    marca(new QLineEdit(this)),
    prezzoMin(new QDoubleSpinBox(this)),
    prezzoMax(new QDoubleSpinBox(this)),
    btnSearch(new QPushButton("&Ricerca",this)),
    btnResetSearch(new QPushButton("&Cancella",this))
{
    QVBoxLayout* layoutres= new QVBoxLayout();
    QGridLayout* gRes= new QGridLayout;
    QVBoxLayout* layoutr= new QVBoxLayout;

    QLabel* text1 = new QLabel("Tipo accessorio:",this);
    gRes->addWidget(text1,0,0);
    gRes->addWidget(tipo,0,1);

    QLabel* text2 = new QLabel("Nome:",this);
    gRes->addWidget(text2,1,0);
    nome->setFixedHeight(22);
    gRes->addWidget(nome,1,1);

    QLabel* text3 = new QLabel("Marca:",this);
    gRes->addWidget(text3,2,0);
    marca->setFixedHeight(22);
    gRes->addWidget(marca,2,1);

    QLabel* text4 = new QLabel("Costo massimo:",this);
    gRes->addWidget(text4,3,0);
    prezzoMin->setSuffix("€");
    prezzoMin->setMinimum(0.00);
    prezzoMin->setMaximum(50000.00);
    gRes->addWidget(prezzoMin,3,1);

    QLabel* text5 = new QLabel("Costo minimo:",this);
    gRes->addWidget(text5,4,0);
    prezzoMax->setSuffix("€");
    prezzoMax->setMinimum(0.00);
    prezzoMax->setMaximum(50000.00);
    gRes->addWidget(prezzoMax,4,1);

    gRes->setVerticalSpacing(10);

    layoutr->addItem(gRes);

    QGridLayout* bRic= new QGridLayout;
    bRic->addWidget(btnSearch);
    bRic->addWidget(btnResetSearch);

    layoutr->addItem(bRic);

    QGroupBox* GBRes = new QGroupBox(tr("Ricerca"));
    GBRes->setLayout(layoutr);
    layoutres->addWidget(GBRes);

    setLayout(layoutres);
}

CBType *LayoutResearch::getTipologia() const
{
    return tipo;
}

QLineEdit *LayoutResearch::getNome() const
{
    return nome;
}

QLineEdit *LayoutResearch::getMarca() const
{
    return marca;
}

QDoubleSpinBox *LayoutResearch::getPrezzoMin() const
{
    return prezzoMin;
}

QDoubleSpinBox *LayoutResearch::getPrezzoMax() const
{
    return prezzoMax;
}

QPushButton *LayoutResearch::getBSearch() const
{
    return btnSearch;
}

QPushButton *LayoutResearch::getBResetSearch() const
{
    return btnResetSearch;
}

void LayoutResearch::reset() const
{
    tipo->setCurrentIndex(0);
    nome->setText("");
    marca->setText("");
    prezzoMin->setValue(0.00);
    prezzoMax->setValue(0.00);
}
