#include "webserver.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QDebug>
#include <clientconnection.h>

QT_USE_NAMESPACE

Webserver::Webserver(quint16 port, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
                                            QWebSocketServer::NonSecureMode, this)),
    m_clients()
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &Webserver::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &Webserver::closed);
    }
}

Webserver::~Webserver()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void Webserver::onNewConnection()
{
    QWebSocket* pSocket = m_pWebSocketServer->nextPendingConnection();
    ClientConnection* connection = new ClientConnection(pSocket);
    connect(pSocket, &QWebSocket::disconnected, this, &Webserver::socketDisconnected);
    m_clients.insert(pSocket, connection);
    qDebug()<< "onNewConnection; Socket = " << pSocket;
}

void Webserver::socketDisconnected()
{
    //почему возник? почему упал?
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        //m_connection->deleteLater(); //?
        m_clients.remove(pClient);
        pClient->deleteLater();
    }
    qDebug() << "socketDisconnected";
}
