#ifndef LINESTYLE_H
#define LINESTYLE_H

#include <QLineEdit>
#include <QDialog>

class LineStyle : public QDialog
{
    Q_OBJECT
public:
    LineStyle(QWidget *parent = 0);
    ~LineStyle();

signals:
    /*
    A signal to indicate when the values are updated
    */
    void stylevaluesUpdated(int x);

private:
    QLineEdit *editX;

private slots:
    void getValues();
};

#endif // LINESTYLE_H


