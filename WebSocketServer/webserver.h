#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <clientconnection.h>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QMap>

class Webserver : public QObject
{
    Q_OBJECT
public:
    Webserver(quint16 port, QObject *parent = Q_NULLPTR);
    ~Webserver();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onNewConnection();
    void socketDisconnected();

private:
    QWebSocket* m_webSocket;
    QWebSocketServer* m_pWebSocketServer;
    QMap<QWebSocket*, ClientConnection*> m_clients;

};
#endif // WEBSOCKET_H
