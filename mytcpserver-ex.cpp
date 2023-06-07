#include "mytcpserver-ex.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        mTcpSocket = mTcpServer->nextPendingConnection();
        Client* client = new Client(mTcpSocket);
        clnts.insert(client->Socket->socketDescriptor(),client);
        connect(client,&Client::Close, this, &MyTcpServer::slotClientDisconnected);
        mTcpSocket->write("Grasias");
    }
}

void MyTcpServer::slotServerRead(){
    QByteArray array;
    while (mTcpSocket->bytesAvailable() > 0) {
            QByteArray array =mTcpSocket->readAll();
            qDebug() << "[CLIENT]" << array;

        }
}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
    qDebug() << "dis";
}
