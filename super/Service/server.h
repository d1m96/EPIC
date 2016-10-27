#ifndef SERVER_H
#define SERVER_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;
QT_END_NAMESPACE

//! [0]
class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = Q_NULLPTR);

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QLabel *statusLabel;
    QTcpServer *tcpServer;
    QStringList fortunes;
    QNetworkSession *networkSession;
};
//! [0]

#endif
