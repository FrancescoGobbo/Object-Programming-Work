#ifndef MONITOR_H
#define MONITOR_H

#include"accessori.h"

class Monitor: public Accessori
{
private://dati Cuffie
    std::string risoluzione;
    std::string rapportoDAspetto;
    double pollici;
    unsigned int refreshRate;
    unsigned int frameRate;
    bool freeSync;
    bool gSync;
    std::string dynamicRange;
    bool casse;

public:
    Monitor(std::string, std::string, double, unsigned int, unsigned int,
            std::string, std::string,
            std::string, std::string, double, unsigned int, unsigned int, bool, bool, std::string, bool);
    virtual bool operator==(const Accessori&) const;
    virtual Monitor* clone() const;
    virtual ~Monitor() override=default;

    //stampa dati
    std::string getRisoluzione()const;
    std::string getRapportoDAspetto()const;
    double getPollici()const;
    unsigned int getRefreshRate()const;
    unsigned int getFrameRate()const;
    bool getFreeSync()const;
    bool getGSync()const;
    std::string getDynamicRange()const;
    bool getCasse()const;

    //Modalita' risoluzione schermo (HD,...)
    std::string modalita() const;

    //Valutazione Qualita'
    int qualitaModalita(std::string) const;
    int qualitaRefreshRate(unsigned int) const;
    int qualitaFrameRate(unsigned int) const;
    double val_FG_Sync(bool, bool) const;

    std::string qualita() const;

    //modifica dati
        void changeRisoluzione(std::string);
        void changeRapportoDAspetto(std::string);
        void changePollici(double);
        void changeRefreshRate(unsigned int);
        void changeFrameRate(unsigned int);
        void changeFreeSync(bool);
        void changeGSync(bool);
        void changeDynamicRange(std::string);
        void changeCasse(bool);

    //method rapporto Qualita' Prezzo
    std::string rapportoQualitaPrezzo() const;

    virtual void scritturaDatiXML(QXmlStreamWriter&) const;

    static Accessori* readerXML(QXmlStreamReader&);
    static void letturaDatiXML(QXmlStreamReader&,
    std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&);
};

#endif // MONITOR_H
