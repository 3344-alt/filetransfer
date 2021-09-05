#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>
#include <QDateTime>
#include <QDataStream>
#include <QMessageBox>
#include <QString>
#include <QByteArray>
#include <QFileDialog>
#include <QHostAddress>
#include <QHostInfo>
#include <QtNetwork>
namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();
    QTcpServer *serve;
    QTcpSocket *socket;
    QTcpServer *fileserver;
    QTcpSocket *filesocket;
    void getIp();
private slots:
    void sendMessage();
    void acceptConnection();
    //接收客户端发送的数据
    void receiveData();

    void acceptFileConnection();
    void updateFileProgress();
    void displayError(QAbstractSocket::SocketError socketError);

    //选择发送的文件
    void selectFile();
    void sendFile();
    //更新文件传送进度
    void updateFileProgress(qint64);


    void on_toolButton_clicked();

private:
    Ui::server *ui;
    QList<QTcpSocket*> tcpClient;
    //传送文件相关变量
    qint64 totalBytes;
    qint64 bytesReceived;
    qint64 bytestoWrite;
    qint64 bytesWritten;
    qint64 filenameSize;
    QString filename;
    QString filename_test;
    //每次发送数据大小
    qint64 perDataSize;
    QFile *localFile;
    //本地缓冲区
    QByteArray inBlock;
    QByteArray outBlock;

    //系统时间
    QDateTime current_date_time;
    QString str_date_time;
};

#endif // SERVER_H
