#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>
#include <QDataStream>
#include <QDateTime>
#include <QFileDialog>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>
namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();

    void initTCP();
    void newConnect();
    void getIp();

private slots:
        //连接和断开服务器
        void connect_Disconnect_Server();
        //接收服务器发送的数据
        void receiveData();
        //向服务器发送数据
        void sendData();

        //浏览文件
        void selectFile();
        //发送文件
        void sendFile();
        //更新文件发送进度
        void updateFileProgress(qint64);
        //更新文件接收进度
        void updateFileProgress();
        void on_toolButton_clicked();

private:
        Ui::client *ui;
        QTcpSocket *tcpSocket;
        QTcpSocket *fileSocket;

        ///文件传送
        QFile *localFile;
        ///文件大小
        qint64 totalBytes;      //文件总字节数
        qint64 bytesWritten;    //已发送的字节数
        qint64 bytestoWrite;    //尚未发送的字节数
        qint64 filenameSize;    //文件名字的字节数
        qint64 bytesReceived;   //接收的字节数
        ///每次发送数据大小
        qint64 perDataSize;
        QString filename;
        QString filename_test;
        ///数据缓冲区
        QByteArray inBlock;
        QByteArray outBlock;
        bool flag;
        //系统时间
        QDateTime current_date_time;
        QString str_date_time;
};

#endif // CLIENT_H
