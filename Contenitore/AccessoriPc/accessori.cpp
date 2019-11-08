#include "accessori.h"
#include <ctime>

Accessori::Accessori(std::string n, std::string m, double c, unsigned int mU, unsigned int aU,
                     std::string tip, std::string tIn) :
    nome(n), marca(m), costo(c), meseUscita(mU), annoUscita(aU),
    tipologia(tip), tipoInput(tIn){}

bool Accessori::operator==(const Accessori & gi) const
{
    return  nome == (gi).getNome() &&
            marca == (gi).getMarca() &&
            costo == (gi).getCosto() &&
            meseUscita == (gi).getMeseUscita() &&
            annoUscita == (gi).getAnnoUscita() &&
            tipologia == (gi).getTipologia() &&
            tipoInput == (gi).getTipoInput();
}

//stampa dati Accessori
std::string Accessori::getNome()const
{
    return nome;
}

std::string Accessori::getMarca()const
{
    return marca;
}

double Accessori::getCosto() const
{
    return costo;
}

unsigned int Accessori::getMeseUscita()const
{
    return meseUscita;
}

unsigned int Accessori::getAnnoUscita()const
{
    return annoUscita;
}

std::string Accessori::getTipologia()const
{
    return tipologia;
}

std::string Accessori::getTipoInput()const
{
    return tipoInput;
}


//method modifica dati Accessori
void Accessori::changeNome(std::string k)
{
    if(k!="")
        nome=k;
}

void Accessori::changeMarca(std::string k)
{
    if(k!="")
        marca=k;
}

void Accessori::changeCosto(double k)
{
    if(k!=0)
        costo=k;
}

void Accessori::changeMeseUscita(unsigned int k)
{
    if(k!=0)
        meseUscita=k;
}


void Accessori::changeAnnoUscita(unsigned int k)
{
    if(k!=0)
        annoUscita=k;
}


void Accessori::changeTipoInput(std::string k)
{
    if(k!="")
        tipoInput=k;
}

//metodo valore attuale dell'usato
double Accessori::valoreAttualeUsato() const
{
    time_t now= time(NULL);
    tm *lmt = localtime(&now);

    int m = 12-meseUscita + lmt->tm_mon+1;
    int y = lmt->tm_year+ 1900-annoUscita;

    int totMesi = m + y*12;

    int sconto =0;
    unsigned int mes=lmt->tm_mon+1;
    if(y>0 || meseUscita<mes){
    	for(int k=0; k<=totMesi && sconto<=70; k=k+3){
        if(sconto+5>70)
            sconto=70;
        else
            sconto= sconto+5;
    	}
	}
	

    return (costo*(100-sconto))/100;
}

void Accessori::scritturaDatiXML(QXmlStreamWriter &opXML) const
{
    //Data
    opXML.writeTextElement("nome", QString::fromStdString(getNome()));
    opXML.writeTextElement("marca", QString::fromStdString(getMarca()));
    opXML.writeTextElement("costo", QString::number(getCosto()));
    opXML.writeTextElement("meseUscita", QString::number(getMeseUscita()));
    opXML.writeTextElement("annoUscita", QString::number(getAnnoUscita()));
    opXML.writeTextElement("tipologia", QString::fromStdString(getTipologia()));
    opXML.writeTextElement("tipoInput", QString::fromStdString(getTipoInput()));

}

void Accessori::writerTypeXML(QXmlStreamWriter &opXML) const
{
    opXML.writeStartElement(QString::fromStdString(getTipologia()));
    scritturaDatiXML(opXML);
    opXML.writeEndElement();
}

void Accessori::letturaDatiXML(QXmlStreamReader &ipDataXML, std::string &datanome, std::string &datamarca,
                              std::string &datacosto, std::string &datameseUscita, std::string &dataannoUscita,
                              std::string &datatipologia, std::string &datatipoInput)
{
    readerXMLTag(ipDataXML,datanome,"nome");
    readerXMLTag(ipDataXML,datamarca,"marca");
    readerXMLTag(ipDataXML,datacosto,"costo");
    readerXMLTag(ipDataXML,datameseUscita,"meseUscita");
    readerXMLTag(ipDataXML,dataannoUscita,"annoUscita");
    readerXMLTag(ipDataXML,datatipologia,"tipologia");
    readerXMLTag(ipDataXML,datatipoInput,"tipoInput");
}
