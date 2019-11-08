#ifndef NEWCUFFIELAYOUT_H
#define NEWCUFFIELAYOUT_H

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>

class NewCuffieLayout : public QWidget
{
    Q_OBJECT
private:
    QCheckBox* microfono;
    QLineEdit* rifC;
    QLineEdit* impedenza;
    QLineEdit* rifM;
    QLineEdit* sensM;
    QCheckBox* cancellazRum;
    QLineEdit* sensC;
    QDoubleSpinBox* peso;
public:
    NewCuffieLayout(QWidget * =nullptr);

    bool getMicrofono() const;
    unsigned int getRifC() const;
    unsigned int getImpedenza() const;
    unsigned int getRifM() const;
    unsigned int getSensM() const;
    bool getCancellazRum() const;
    unsigned int getSensC() const;
    double getPeso() const;

public slots:
    void slotDisableMic() const;
    void slotResetCuffie()const;
};

#endif // NEWCUFFIELAYOUT_H
