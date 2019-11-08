#ifndef MODEL_H
#define MODEL_H

#include "contenitore/container.h"
#include "contenitore/deepptr.h"

#include "contenitore/AccessoriPc/accessori.h"

#include<typeinfo>
#include<string>

class Model
{
private:
    Container<Deepptr<Accessori>>* goods;//container effettivo
    Container<Deepptr<Accessori>>* listSearch;//per la stampa a video

    string path;
    bool isDataSaved;
public:
    Model(string ="");
    ~Model();

    int getPathSize() const;

    void inserimento(Deepptr<Accessori>);

    unsigned int getDataUsed() const;//dim usata
    unsigned int getDataSize() const;//dim tot disponibile


    void eliminazione(unsigned int);//eliminazione singolo elemento
    void eliminazione(Deepptr<Accessori>);

    bool isDataEmpty() const;
    void clear();

    //Modifica dati
    void modificaCuffie(unsigned int,
                        string, string, double, unsigned int, unsigned int, string,
                        bool, unsigned int, unsigned int, unsigned int, unsigned int, bool, unsigned int, double);
    void modificaMonitor(unsigned int,
                        string, string, double, unsigned int, unsigned int, string,
                        std::string, std::string, double, unsigned int, unsigned int, bool, bool, std::string, bool);
    void modificaMouse(unsigned int,
                        string, string, double, unsigned int, unsigned int, string,
                        unsigned int, unsigned int, unsigned int, unsigned int, bool, std::string, unsigned int, std::string, double);
    void modificaTastiera(unsigned int,
                        string, string, double, unsigned int, unsigned int, string,
                        bool, std::string, std::string, unsigned int, std::string, bool);
    void modificaWebcam(unsigned int,
                        string, string, double, unsigned int, unsigned int, string,
                        unsigned int, bool, bool, unsigned int, bool, std::string, bool, bool);


     void saveToFile();// non e' const poiche' modifica il flag isDataSaved
     void loadFromFile();

     void setNewPath(string );
     bool getIsDataSaved() const;
     void setDataSaved(bool);

     void resetRicerca()const;
     void filtroTipologia(string nome)const ;
     void filtroNome(string nome)const ;
     void filtroMarca(string sesso)const;
     void filtroPrezzoMin(double prezzo)const;
     void filtroPrezzoMag(double prezzo)const;

     unsigned int calcolaValori5() const;
     unsigned int calcolaValori4() const;
     unsigned int calcolaValori3() const;
     unsigned int calcolaValori2() const;
     unsigned int calcolaValori1() const;

     Container<Deepptr<Accessori>>::Iter sBegin();
     Container<Deepptr<Accessori>>::Iter sEnd();
     Container<Deepptr<Accessori>>::ConstIter cBegin()const;
     Container<Deepptr<Accessori>>::ConstIter cEnd()const;
};

#endif // MODEL_H
