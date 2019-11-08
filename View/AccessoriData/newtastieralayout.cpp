#include "newtastieralayout.h"

#include <QVBoxLayout>
#include <QValidator>
#include <QLabel>

NewTastieraLayout::NewTastieraLayout(QWidget *p):
    QWidget (p),
    retroIlluminazione(new QCheckBox("Retro Illuminazione",this)),
    layout(new CBLayoutTastiera(this)),
    confort(new CBConfortTastiera(this)),
    pollingRate(new QLineEdit(this)),
    categoria(new CBCategoriaTastiera(this)),
    trackPad(new QCheckBox("TrackPad",this))
{
    QVBoxLayout *layoutTastiera = new QVBoxLayout();

    layoutTastiera->addWidget(retroIlluminazione);

    QGridLayout *grindLayout = new QGridLayout;
    QLabel* text1 = new QLabel("Layout");
    grindLayout->addWidget(text1,0,0);
    grindLayout->addWidget(layout,0,1);
    layoutTastiera->addItem(grindLayout);

    QGridLayout *grindConfort = new QGridLayout;
    QLabel* text2 = new QLabel("Confort");
    grindConfort->addWidget(text2,0,0);
    grindConfort->addWidget(confort,0,1);
    layoutTastiera->addItem(grindConfort);

    QValidator* vPR = new QIntValidator(100, 1000, this);
    pollingRate->setValidator(vPR);
    pollingRate->setPlaceholderText("Polling Rate   (100-1000 IPS)");
    layoutTastiera->addWidget(pollingRate);

    QGridLayout *grindCategoria = new QGridLayout;
    QLabel* text3 = new QLabel("Categoria");
    grindCategoria->addWidget(text3,0,0);
    grindCategoria->addWidget(categoria,0,1);
    layoutTastiera->addItem(grindCategoria);

    layoutTastiera->addWidget(trackPad);

    setLayout(layoutTastiera);
}

bool NewTastieraLayout::getRetroIlluminazione() const
{
    return retroIlluminazione->isChecked();
}

CBLayoutTastiera *NewTastieraLayout::getLayout() const
{
    return layout;
}

std::string NewTastieraLayout::getLayouttxt() const
{
    std::string r;
    if(layout->currentIndex()!=0)
        r=layout->currentText().toStdString();
    return r;
}

CBConfortTastiera *NewTastieraLayout::getConfort() const
{
    return confort;
}

std::string NewTastieraLayout::getConforttxt() const
{
    std::string r;
    if(confort->currentIndex()!=0)
        r=confort->currentText().toStdString();
    return r;
}

unsigned int NewTastieraLayout::getPollingRate() const
{
    return pollingRate->text().toUInt();;
}

CBCategoriaTastiera *NewTastieraLayout::getCategoria() const
{
    return categoria;
}

std::string NewTastieraLayout::getCategoriatxt() const
{
    std::string r;
    if(categoria->currentIndex()!=0)
        r=categoria->currentText().toStdString();
    return r;
}

bool NewTastieraLayout::getTrackPad() const
{
    return trackPad->isChecked();
}

void NewTastieraLayout::slotResetTastiera() const
{
    retroIlluminazione->setChecked(false);
    layout->setCurrentIndex(0);
    confort->setCurrentIndex(0);
    pollingRate->setText("");
    categoria->setCurrentIndex(0);
    trackPad->setChecked(false);
}
