#include "layoutlistaricercaaccessori.h"

LayoutListaRicercaAccessori::LayoutListaRicercaAccessori(QWidget *p):
    QWidget (p),
    btnTornaHome(new QPushButton(this)),
    tipoAcc (new QLabel(this)),
    lista (new QListWidget(this)),
    qualita (new LayoutQuality(this)),
    ricerca (new LayoutResearch(this)),
    btnElimina(new QPushButton("Elimina",this)),
    btnInserisci (new QPushButton("Inserisci",this))
{
    QVBoxLayout *layoutLRAcc = new QVBoxLayout(this);

    QGridLayout* GBLRAcc = new QGridLayout;

    QHBoxLayout* intro= new QHBoxLayout();

    QIcon icon = QIcon(":/img/IMG/home.png");
    btnTornaHome->setIcon(icon);
    btnTornaHome->setStyleSheet("background-color: white");
    btnTornaHome->setIconSize(QSize(30,30));
    btnTornaHome->setFixedSize(40,40);
    intro->addWidget(btnTornaHome);

    tipoAcc->setStyleSheet("Color: green; font: bold 14px;  min-width: 25em;");
    tipoAcc->setAlignment(Qt::AlignCenter);
    intro->addWidget(tipoAcc);

    layoutLRAcc->addLayout(intro);

    lista->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    GBLRAcc->addWidget(lista,0,0);

    QVBoxLayout* layoutright= new QVBoxLayout();

    layoutright->addWidget(qualita);

    layoutright->addWidget(ricerca);

    QGridLayout* grindButton = new QGridLayout;
    grindButton->addWidget(btnElimina,0,0);
    grindButton->addWidget(btnInserisci,1,0);
    grindButton->setSpacing(10);
    layoutright->addItem(grindButton);

    GBLRAcc->addItem(layoutright,0,1);

    layoutLRAcc->addItem(GBLRAcc);

    setLayout(layoutLRAcc);

    setMinimumWidth(550);
}

LayoutListaRicercaAccessori::~LayoutListaRicercaAccessori(){
    delete btnElimina;
}

QPushButton *LayoutListaRicercaAccessori::getReturnHome() const
{
    return btnTornaHome;
}

QLabel *LayoutListaRicercaAccessori::getIntro() const
{
    return tipoAcc;
}

void LayoutListaRicercaAccessori::aggRiga(QString s)
{
    QListWidgetItem* riga = new QListWidgetItem;
    riga->setText(s);
    lista->addItem(riga);
}

void LayoutListaRicercaAccessori::resetLista() const
{
    lista->clear();
}

QListWidget *LayoutListaRicercaAccessori::getLista() const
{
    return lista;
}

QLabel *LayoutListaRicercaAccessori::getNAccEcc() const
{
    return qualita->slotAccEcc();
}

QLabel *LayoutListaRicercaAccessori::getNAccOtt() const
{
    return qualita->slotAccOtt();
}

QLabel *LayoutListaRicercaAccessori::getNAccBuo() const
{
    return qualita->slotAccBuo();
}

QLabel *LayoutListaRicercaAccessori::getNAccSuf() const
{
    return qualita->slotAccSuff();
}

QLabel *LayoutListaRicercaAccessori::getNAccPes() const
{
    return qualita->slotAccPes();
}

int LayoutListaRicercaAccessori::getTipo() const
{
    return ricerca->getTipologia()->currentIndex();
}

string LayoutListaRicercaAccessori::getNome() const
{
    return ricerca->getNome()->text().toStdString();
    //return ricerca->getNome();
}

string LayoutListaRicercaAccessori::getMarca() const
{
    return ricerca->getMarca()->text().toStdString();
    //return ricerca->getMarca();
}

double LayoutListaRicercaAccessori::getPrezzoMin() const
{
    return ricerca->getPrezzoMin()->value();
}

double LayoutListaRicercaAccessori::getPrezzoMax() const
{
    return ricerca->getPrezzoMax()->value();
}

QPushButton *LayoutListaRicercaAccessori::getBtnRicerca() const
{
    return ricerca->getBSearch();
}

QPushButton *LayoutListaRicercaAccessori::getBtnResetRicerca() const
{
    return ricerca->getBResetSearch();
}

void LayoutListaRicercaAccessori::azzeraRicerca() const
{
    return ricerca->reset();
}

QPushButton *LayoutListaRicercaAccessori::getBtnInserisci() const
{
    return btnInserisci;
}

QPushButton *LayoutListaRicercaAccessori::getBtnElimina() const
{
    return btnElimina;
}



/*void LayoutListaRicercaAccessori::listwiew(Model*)
{
    list->clear();
    for(auto i = modello.cbegin();i!=modello.cend();i++)
    {
        QListWidgetItem* riga = new QListWidgetItem;
        riga->setText(QString::fromStdString((*i)->getName()));
        list->addItem(riga);
    }
    //se c'è un file selezionato ne mostra la descrizione
    //showInfoFile();
    //emit filterSearch();
}*/

/*
void LayoutListaRicercaAccessori::signalElementoSelezionato(bool t)const
{

}
*/
