#ifndef MOUSE_H
#define MOUSE_H

#include"accessori.h"


class Mouse: public Accessori
{
private://dati Mouse
    unsigned int dpimin;
    unsigned int dpimax;
    unsigned int pollingRate;//comunicazione posizione al pc
    unsigned int trackingSpeed;//velocita' tracciamento
    bool angleSnapping;//capacita' di tracciare una linea retta
    std::string sensore;//ottico o laser
    unsigned int pulsanti;
    std::string ergonomia;//verticale o orizzontale
    double peso;

public:
    Mouse(std::string, std::string, double, unsigned int, unsigned int,
          std::string, std::string,
          unsigned int, unsigned int, unsigned int, unsigned int, bool, std::string, unsigned int, std::string, double);
    virtual bool operator==(const Accessori&) const;
    virtual Mouse* clone() const;
    virtual ~Mouse() override=default;

    //stampa dati
    unsigned int getDPImin()const;
    unsigned int getDPImax()const;
    unsigned int getPollingRate()const;
    unsigned int getTrackingSpeed()const;
    bool getAngleSnapping()const;
    std::string getSensore()const;
    unsigned int getPulsanti()const;
    std::string getErgonomia()const;
    double getPeso()const;

    //method valutazione tipologia mouse
    std::string typeMouse() const;

    //Valutazione Qualita'
    double rangeDPI(unsigned int, unsigned int) const;
    double valPollingRate(unsigned int) const;
    int valTrackingSpeed (unsigned int) const;
    double bAngleSnapping (bool) const;
    double valSensore(std::string) const;

    std::string qualita() const;

    //modifica dati
        void changeDPImin(unsigned int);
        void changeDPImax(unsigned int);
        void changePollingRate(unsigned int);
        void changeTrackingSpeed(unsigned int);
        void changeAngleSnapping(bool);
        void changeSensore(std::string);
        void changePulsanti(unsigned int);
        void changeErgonomia(std::string);
        void changePeso(double);

    //method rapporto Qualita' Prezzo
    std::string rapportoQualitaPrezzo() const;

    virtual void scritturaDatiXML(QXmlStreamWriter&) const;

    static Accessori* readerXML(QXmlStreamReader&);
    static void letturaDatiXML(QXmlStreamReader&,
                               std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&);
};

#endif // MOUSE_H
