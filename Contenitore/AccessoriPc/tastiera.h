#ifndef TASTIERA_H
#define TASTIERA_H

#include "accessori.h"

class Tastiera: public Accessori
{
private://dati Tastiera
    bool retroilluminazione;
    std::string layout;
    std::string confort;//qualita' confort
    unsigned int pollingRate;
    std::string categoria;//meccanica o membrana
    bool trackpad;

public:
    Tastiera(std::string, std::string, double, unsigned int, unsigned int,
             std::string, std::string,
             bool, std::string, std::string, unsigned int, std::string, bool);
    virtual bool operator==(const Accessori&) const;
    virtual Tastiera* clone() const;
    virtual ~Tastiera() override=default;

    //stampa dati
    bool getRetroIlluminazione()const;
    std::string getLayout()const;
    std::string getConfort()const;
    unsigned int getPollingRate()const;
    std::string getCategoria()const;
    bool getTrackPad()const;

    //Valutazione Qualita'
    int qualitaConfort(std::string) const;
    int qualitaVelocita(int) const;

    std::string qualita() const;

    //modifica dati
        void changeRetroIlluminazione(bool);
        void changeLayout(std::string);
        void changeConfort(std::string);
        void changePollingRate(unsigned int);
        void changeCategoria(std::string);
        void changeTrackPad(bool);

    //method rapporto Qualita' Prezzo
    std::string rapportoQualitaPrezzo() const;

    virtual void scritturaDatiXML(QXmlStreamWriter&) const;

    static Accessori* readerXML(QXmlStreamReader&);
    static void letturaDatiXML(QXmlStreamReader&,
                               std::string&,std::string&,std::string&,std::string&,std::string&,std::string&);
};

#endif // TASTIERA_H
