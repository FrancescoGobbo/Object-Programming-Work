#include "mouse.h"

Mouse::Mouse(std::string n, std::string m, double c, unsigned int mU, unsigned int aU,
             std::string tip, std::string tIn,
             unsigned int dmin, unsigned int dmax, unsigned int pR, unsigned int trS, bool aS, std::string sens,
             unsigned int button, std::string ergonomia, double kg) :
             Accessori(n, m, c, mU, aU, tip, tIn),
             dpimin(dmin), dpimax(dmax), pollingRate(pR), trackingSpeed(trS),angleSnapping(aS), sensore(sens),
             pulsanti(button), ergonomia(ergonomia), peso(kg){}

bool Mouse::operator==(const Accessori & a) const
{
    Mouse* m= dynamic_cast<Mouse*> (const_cast<Accessori*>(&a));
    return Accessori::operator== (a) &&
        dpimin == (m)->getDPImin() &&
        dpimax == (m)->getDPImax() &&
        pollingRate == (m)->getPollingRate() &&
        trackingSpeed == (m)->getTrackingSpeed() &&
        angleSnapping == (m)->getAngleSnapping() &&
        sensore == (m)->getSensore() &&
        pulsanti == (m)->getPulsanti() &&
        ergonomia == (m)->getErgonomia() &&
        peso == (m)->getPeso();
}

Mouse *Mouse::clone() const
{
    return new Mouse(*this);
}

//stampa dati
unsigned int Mouse::getDPImin() const
{
    return dpimin;
}

unsigned int Mouse::getDPImax() const
{
    return dpimax;
}

unsigned int Mouse::getPollingRate() const
{
    return pollingRate;
}

unsigned int Mouse::getTrackingSpeed() const
{
    return trackingSpeed;
}

bool Mouse::getAngleSnapping() const
{
    return angleSnapping;
}

std::string Mouse::getSensore() const
{
    return sensore;
}

unsigned int Mouse::getPulsanti() const
{
    return pulsanti;
}

std::string Mouse::getErgonomia() const
{
    return ergonomia;
}

double Mouse::getPeso() const
{
    return peso;
}

//modifica dati
void Mouse::changeDPImin(unsigned int k)
{
    if(k!=0)
        dpimin=k;
}

void Mouse::changeDPImax(unsigned int k)
{
    if(k!=0)
        dpimax=k;
}

void Mouse::changePollingRate(unsigned int k)
{
    if(k!=0)
        pollingRate=k;
}

void Mouse::changeTrackingSpeed(unsigned int k)
{
    if(k!=0)
        trackingSpeed=k;
}

void Mouse::changeAngleSnapping(bool k)
{
    angleSnapping=k;
}

void Mouse::changeSensore(std::string k)
{
    if(k!="")
        sensore=k;
}

void Mouse::changePulsanti(unsigned int k)
{
    if(k!=0)
        pulsanti=k;
}

void Mouse::changeErgonomia(std::string k)
{
    if(k!="")
        ergonomia=k;
}

void Mouse::changePeso(double k)
{
    if(k!=0)
        peso=k;
}

//method valutazione tipologia mouse
std::string Mouse::typeMouse() const
{
    std::string tipo;
    if(pulsanti>=3 && dpimax!=dpimin && trackingSpeed>96 && rangeDPI(dpimin, dpimax)>=3.5)
        tipo="Gaming";
    if(angleSnapping)
        tipo="Precision";
    else
        tipo="Standard";
    return tipo;
}

//Valutazione Qualita'
double Mouse::rangeDPI(unsigned int dmn, unsigned int dMx) const
{
    double valmin=5-((dmn*5)/10000);
    double valmax=(dMx*5)/16000;
    if(valmin<1)
        valmin=1;
    if(valmax<1)
        valmax=1;
    return (valmax+valmin)/2;
}

double Mouse::valPollingRate(unsigned int vPR) const
{
    if(vPR>500)
        return 5;
    else if(vPR<=500 && vPR>100)
        return 3.5;
    else
        return 1;
}

int Mouse::valTrackingSpeed(unsigned int vTS) const
{
    int value=1;
    if(vTS>=112)
        value=5;
    else if (vTS<112 && vTS>=104)
        value=4;
    else if (vTS<104 && vTS>=96)
        value=3;
    else if (vTS<96 && vTS>=88)
        value=2;
    else if (vTS<88 && vTS>=80)
        value=1;
    return value;
}

double Mouse::bAngleSnapping(bool as) const
{
    if(as)
        return 3;
    else
        return 2;
}

double Mouse::valSensore(std::string vS) const
{
    if(vS=="ottico")
        return 5;
    else if(vS=="laser")
        return 2.5;
    else
        return 1;
}

std::string Mouse::qualita() const
{
    double k= rangeDPI(dpimax,dpimin) + valPollingRate(pollingRate) + valTrackingSpeed(trackingSpeed)+bAngleSnapping(angleSnapping) + valSensore(sensore);
    std::string value;
    if(k/5>4)
        value= "Eccezionale";
    else if(k/5>3 && k/5<=4)
        value= "Ottima";
    else if(k/5>2 && k/5<=3)
        value= "Buona";
    else if(k/5>1 && k/5<=2)
        value= "Sufficiente";
    else if(k/5>0 && k/5<=1)
        value= "Pessima";

    return value;
}

//method rapporto Qualita' Prezzo
std::string Mouse::rapportoQualitaPrezzo() const
{
    std::string value;
    if(getCosto()<40)
        value="Economiche";
    else if(getCosto()>40 && getCosto()<75)
        value="Fascia Media";
    else
        value="Fascia Alta";
    return value;
}

void Mouse::scritturaDatiXML(QXmlStreamWriter &opXML) const
{
    Accessori::scritturaDatiXML(opXML);
    opXML.writeTextElement("dpimin", QString::number(getDPImin()));
    opXML.writeTextElement("dpimax", QString::number(getDPImax()));
    opXML.writeTextElement("pollingRate", QString::number(getPollingRate()));
    opXML.writeTextElement("trackingSpeed", QString::number(getTrackingSpeed()));
    opXML.writeTextElement("angleSnapping", getAngleSnapping()?"1":"0");
    opXML.writeTextElement("sensore", QString::fromStdString(getSensore()));
    opXML.writeTextElement("pulsanti", QString::number(getPulsanti()));
    opXML.writeTextElement("ergonomia", QString::fromStdString(getErgonomia()));
    opXML.writeTextElement("peso", QString::number(getPeso()));
}

Accessori * Mouse::readerXML(QXmlStreamReader &ipDataXML)
{
    std::string datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput;
    Accessori::letturaDatiXML(ipDataXML,datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput);

    std::string datadmin, datadmax, datapR, datatrS, dataaS, datasens, databutton, dataergonomia, datakg;
    Mouse::letturaDatiXML(ipDataXML, datadmin, datadmax, datapR, datatrS, dataaS, datasens, databutton, dataergonomia, datakg);
    bool aS = (dataaS == "1"? true : false);

    return new Mouse(datanome, datamarca, stod(datacosto), stoul(datameseUscita), stoul(dataannoUscita), datatipologia, datatipoInput,
                      stoul(datadmin), stoul(datadmax), stoul(datapR), stoul(datatrS), aS, datasens, stoul(databutton), dataergonomia, stod(datakg));
}

void Mouse::letturaDatiXML(QXmlStreamReader &ipDataXML, std::string &dmin, std::string &dmax, std::string &pR, std::string &trS,
                                std::string &aS, std::string &sens, std::string &button, std::string &ergonomia, std::string &kg)
{
    readerXMLTag(ipDataXML, dmin, "dpimin");
    readerXMLTag(ipDataXML, dmax, "dpimax");
    readerXMLTag(ipDataXML, pR, "pollingRate");
    readerXMLTag(ipDataXML, trS, "trackingSpeed");
    readerXMLTag(ipDataXML, aS, "angleSnapping");
    readerXMLTag(ipDataXML, sens, "sensore");
    readerXMLTag(ipDataXML, button, "pulsanti");
    readerXMLTag(ipDataXML, ergonomia, "ergonomia");
    readerXMLTag(ipDataXML, kg, "peso");
}
