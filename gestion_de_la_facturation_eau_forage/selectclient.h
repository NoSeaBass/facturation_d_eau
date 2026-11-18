#ifndef SELECTCLIENT_H
#define SELECTCLIENT_H

#include <QDialog>

namespace Ui {
class SelectClient;
}

class SelectClient : public QDialog
{
    Q_OBJECT

public:
    explicit SelectClient(QWidget *parent = nullptr);
    ~SelectClient();

    int clientIdSelectionne() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SelectClient *ui;
    int m_clientIdSelectionne = -1;
};

#endif // SELECTCLIENT_H
