#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
class QComboBox;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QLabel *serialPortLabel;
    QComboBox *serialPortComboBox;
    QLabel *waitResponseLabel;
    QSpinBox *waitResponseSpinBox;
    QLabel *requestLabel;
    QLineEdit *requestLineEdit;
    QLabel *trafficLabel;
    QLabel *statusLabel;
    QPushButton *runButton;
};

#endif // DIALOG_H
