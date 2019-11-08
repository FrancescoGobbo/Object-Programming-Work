#ifndef LAYOUTRESEARCH_H
#define LAYOUTRESEARCH_H

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

#include "View/AccessoriData/QComboBoxNewAccessori/cbtype.h"

class LayoutResearch: public QWidget
{
    Q_OBJECT
private:
    CBType* tipo;
    QLineEdit* nome;
    QLineEdit* marca;
    QDoubleSpinBox* prezzoMin;
    QDoubleSpinBox* prezzoMax;
    QPushButton *btnSearch;
    QPushButton *btnResetSearch;
public:
    LayoutResearch(QWidget* =nullptr);

    CBType* getTipologia()const;
    QLineEdit* getNome()const;
    QLineEdit* getMarca()const;
    QDoubleSpinBox* getPrezzoMin()const;
    QDoubleSpinBox* getPrezzoMax()const;

    QPushButton* getBSearch() const;
    QPushButton* getBResetSearch() const;


    void reset()const;
};

#endif // LAYOUTRESEARCH_H
