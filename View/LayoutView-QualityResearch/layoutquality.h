#ifndef LAYOUTQUALITY_H
#define LAYOUTQUALITY_H

#include <QVBoxLayout>
#include <QLabel>

class LayoutQuality: public QWidget
{
    Q_OBJECT
private:
    QLabel* accE;
    QLabel* accO;
    QLabel* accB;
    QLabel* accS;
    QLabel* accP;
public:
    LayoutQuality(QWidget* = nullptr);

public slots:
    QLabel* slotAccEcc()const;
    QLabel* slotAccOtt()const;
    QLabel* slotAccBuo()const;
    QLabel* slotAccSuff()const;
    QLabel* slotAccPes()const;
};

#endif // LAYOUTQUALITY_H
