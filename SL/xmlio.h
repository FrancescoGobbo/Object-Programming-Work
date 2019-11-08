#ifndef XMLIO_H
#define XMLIO_H

#include<iostream>
#include <QString>
#include "Contenitore/container.h"
#include "Contenitore/deepptr.h"
#include "Contenitore/AccessoriPc/accessori.h"
#include "Contenitore/AccessoriPc/cuffie.h"
#include "Contenitore/AccessoriPc/monitor.h"
#include "Contenitore/AccessoriPc/mouse.h"
#include "Contenitore/AccessoriPc/tastiera.h"
#include "Contenitore/AccessoriPc/webcam.h"
#include "readerxmltag.h"

class XmlIO {
private:
    QString filename;
public:
    XmlIO(const QString&);
    static Accessori* tagTypeXML(QXmlStreamReader&,const std::string&);
    Container<Deepptr<Accessori>> read() const;//lettura dati
    void write(const Container<Deepptr<Accessori>>&) const;//salvataggio dati
};

#endif // XMLIO_H
