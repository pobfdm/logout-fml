#ifndef MANAGECLIENTS_H
#define MANAGECLIENTS_H

#include <QWidget>

namespace Ui {
class ManageClients;
}

class ManageClients : public QWidget
{
    Q_OBJECT

public:
    explicit ManageClients(QWidget *parent = 0);
    ~ManageClients();

private:
    Ui::ManageClients *ui;
};

#endif // MANAGECLIENTS_H
