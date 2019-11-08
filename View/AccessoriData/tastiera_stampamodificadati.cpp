#include "tastiera_stampamodificadati.h"

#include<iostream>

Tastiera_StampaModificaDati::Tastiera_StampaModificaDati(QWidget *p):
    QWidget (p),
    datoRetroIlluminazioneA(new QLabel(this)),
    retroIlluminazioneA(new QLabel("Retro illuminazione:",this)),
    datoLayoutA(new QLabel(this)),
    layoutA(new QLabel("Layout:",this)),
    datoConfortA(new QLabel(this)),
    confortA(new QLabel("Confort:",this)),
    datoPollingRateA(new QLabel(this)),
    pollingRateA(new QLabel("Polling Rate(IPS):",this)),
    datoCategoriaA(new QLabel(this)),
    categoriaA(new QLabel("Categoria:",this)),
    datoTrackPadA(new QLabel(this)),
    trackPadA(new QLabel("TrackPad:",this)),

    modifica_retroIlluminazione(new QCheckBox(this)),
    modifica_layout(new CBLayoutTastiera(this)),
    modifica_confort(new CBConfortTastiera(this)),
    modifica_pollingRate(new QLineEdit(this)),
    modifica_categoria(new CBCategoriaTastiera(this)),
    modifica_trackPad(new QCheckBox(this))
{
    QVBoxLayout *layoutDati = new QVBoxLayout(this);

    QGridLayout *tastieraDataGL = new QGridLayout;

    tastieraDataGL->addWidget(retroIlluminazioneA,0,0);
    tastieraDataGL->addWidget(datoRetroIlluminazioneA,0,1);
    tastieraDataGL->addWidget(modifica_retroIlluminazione,0,2);

    tastieraDataGL->addWidget(layoutA,1,0);
    tastieraDataGL->addWidget(datoLayoutA,1,1);
    tastieraDataGL->addWidget(modifica_layout,1,2);

    tastieraDataGL->addWidget(confortA,2,0);
    tastieraDataGL->addWidget(datoConfortA,2,1);
    tastieraDataGL->addWidget(modifica_confort,2,2);

    tastieraDataGL->addWidget(pollingRateA,3,0);
    tastieraDataGL->addWidget(datoPollingRateA,3,1);
    QValidator* vPR = new QIntValidator(100, 1000, this);
    modifica_pollingRate->setValidator(vPR);
    modifica_pollingRate->setPlaceholderText("(100-1000 IPS)");
    tastieraDataGL->addWidget(modifica_pollingRate,3,2);

    tastieraDataGL->addWidget(categoriaA,4,0);
    tastieraDataGL->addWidget(datoCategoriaA,4,1);
    tastieraDataGL->addWidget(modifica_categoria,4,2);

    tastieraDataGL->addWidget(trackPadA,5,0);
    tastieraDataGL->addWidget(datoTrackPadA,5,1);
    tastieraDataGL->addWidget(modifica_trackPad,5,2);

    tastieraDataGL->setSpacing(10);

    modifica_retroIlluminazione->hide();
    modifica_layout->hide();
    modifica_confort->hide();
    modifica_pollingRate->hide();
    modifica_categoria->hide();
    modifica_trackPad->hide();

    layoutDati->addItem(tastieraDataGL);
    setLayout(layoutDati);
}

QLabel *Tastiera_StampaModificaDati::getDatoRI() const
{
    return datoRetroIlluminazioneA;
}

QLabel *Tastiera_StampaModificaDati::getDatoLay() const
{
    return datoLayoutA;
}

QLabel *Tastiera_StampaModificaDati::getDatoConf() const
{
    return datoConfortA;
}

QLabel *Tastiera_StampaModificaDati::getDatoPR() const
{
    return datoPollingRateA;
}

QLabel *Tastiera_StampaModificaDati::getDatoCat() const
{
    return datoCategoriaA;
}

QLabel *Tastiera_StampaModificaDati::getDatoTP() const
{
    return datoTrackPadA;
}

bool Tastiera_StampaModificaDati::getModifRetroIlluminazione() const
{
    return modifica_retroIlluminazione->isChecked();
}

std::string Tastiera_StampaModificaDati::getModifLayout() const
{
    std::string r;
    if(modifica_layout->currentIndex()!=0)
        r=modifica_layout->currentText().toStdString();
    /*switch(modifica_layout->currentIndex()){
    case 1:
        r="Layout US (Internazionale)";
    case 2:
        r="Layout UK";
    case 3:
        r="Layout tedesco";
    case 4:
        r="Layout francese";
    case 5:
        r="Layout UE";
    }*/
    return r;
}

std::string Tastiera_StampaModificaDati::getModifConfort() const
{
    std::string r;
    if(modifica_confort->currentIndex()!=0)
        r=modifica_confort->currentText().toStdString();
    /*switch(modifica_confort->currentIndex()){
    case 1:
        r="eccezionale";
    case 2:
        r="ottima";
    case 3:
        r="buona";
    case 4:
        r="sufficiente";
    case 5:
        r="pessima";
    }*/
    return r;
}

unsigned int Tastiera_StampaModificaDati::getModifPollingRate() const
{
    return modifica_pollingRate->text().toUInt();
}

std::string Tastiera_StampaModificaDati::getModifCategoria() const
{
    std::string r;
    if(modifica_categoria->currentIndex()!=0)
        r=modifica_categoria->currentText().toStdString();
    /*switch(modifica_categoria->currentIndex()){
    case 1:
        r="meccanica";
    case 2:
        r="membrana";
    }*/
    return r;
}

bool Tastiera_StampaModificaDati::getModifTrackPad() const
{
    return modifica_trackPad->isChecked();
}

bool Tastiera_StampaModificaDati::modifySomething()
{
    bool modificatoQualcosa=1;
    if(((getModifRetroIlluminazione()==0 && datoRetroIlluminazioneA->text()=="No") || (getModifRetroIlluminazione()==1 && datoRetroIlluminazioneA->text()=="Si"))&&
       modifica_layout->currentIndex()==0 && modifica_confort->currentIndex()==0 && getModifPollingRate()==0 && modifica_categoria->currentIndex()==0 &&
       ((getModifTrackPad()==0 && datoTrackPadA->text()=="No") || (getModifTrackPad()==1 && datoTrackPadA->text()=="Si")))
        modificatoQualcosa=0;
    return modificatoQualcosa;
}

void Tastiera_StampaModificaDati::showModificatori()
{
    datoRetroIlluminazioneA->hide();
    datoLayoutA->hide();
    datoConfortA->hide();
    datoPollingRateA->hide();
    datoCategoriaA->hide();
    datoTrackPadA->hide();

    modifica_retroIlluminazione->show();
    modifica_layout->show();
    modifica_confort->show();
    modifica_pollingRate->show();
    modifica_categoria->show();
    modifica_trackPad->show();
}

void Tastiera_StampaModificaDati::showDati()
{
    datoRetroIlluminazioneA->show();
    datoLayoutA->show();
    datoConfortA->show();
    datoPollingRateA->show();
    datoCategoriaA->show();
    datoTrackPadA->show();

    modifica_retroIlluminazione->hide();
    modifica_layout->hide();
    modifica_confort->hide();
    modifica_pollingRate->hide();
    modifica_categoria->hide();
    modifica_trackPad->hide();
}

void Tastiera_StampaModificaDati::slotReset()
{
    modifica_retroIlluminazione->setChecked(false);
    modifica_layout->setCurrentIndex(0);
    modifica_confort->setCurrentIndex(0);
    modifica_pollingRate->setText("");
    modifica_categoria->setCurrentIndex(0);
    modifica_trackPad->setChecked(false);
}
