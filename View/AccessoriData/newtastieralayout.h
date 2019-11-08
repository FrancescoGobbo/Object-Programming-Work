#ifndef NEWTASTIERALAYOUT_H
#define NEWTASTIERALAYOUT_H

#include <QLineEdit>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbcategoriatastiera.h"
#include "QComboBoxNewAccessori/cblayouttastiera.h"
#include "QComboBoxNewAccessori/cbconforttastiera.h"

class NewTastieraLayout : public QWidget
{
    Q_OBJECT
private:
    QCheckBox* retroIlluminazione;
    CBLayoutTastiera* layout;
    CBConfortTastiera* confort;
    QLineEdit* pollingRate;
    CBCategoriaTastiera* categoria;
    QCheckBox* trackPad;
public:
    NewTastieraLayout(QWidget * =nullptr);

    bool getRetroIlluminazione() const;
    CBLayoutTastiera* getLayout() const;
    std::string getLayouttxt() const;
    CBConfortTastiera* getConfort() const;
    std::string getConforttxt() const;
    unsigned int getPollingRate() const;
    CBCategoriaTastiera* getCategoria() const;
    std::string getCategoriatxt() const;
    bool getTrackPad() const;

public slots:
    void slotResetTastiera()const;
};

#endif // NEWTASTIERALAYOUT_H
