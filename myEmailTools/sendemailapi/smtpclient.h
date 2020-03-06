#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QtNetwork/QSslSocket>

#include "mimemessage.h"


class SmtpClient : public QObject
{
    Q_OBJECT
public:    

    enum AuthMethod      /*客户端发送一个 AUTH 认证命令进行用户登录*/
    {
        AuthPlain,
        AuthLogin
    };

    enum SmtpError
    {
        ConnectionTimeoutError,
        ResponseTimeoutError,
        AuthenticationFailedError,
        ServerError,    // 4xx smtp error
        ClientError     // 5xx smtp error
    };

    enum ConnectionType
    {
        TcpConnection,    //传输控制协议     Telnet协议是TCP/IP协议族中的一员，是Internet远程登陆服务的标准协议和主要方式。
        SslConnection,    //安全套接层协议
        TlsConnection       // STARTTLS   //安全传输层协议
    };   

    SmtpClient(const QString & host = "locahost", int port = 25, ConnectionType ct = TcpConnection);    /*"locahost"--本地主机*/

    ~SmtpClient();   

    const QString& getHost() const;
    void setHost(QString &host);

    int getPort() const;
    void setPort(int port);

    const QString& getName() const;
    void setName(const QString &name);

    ConnectionType getConnectionType() const;
    void setConnectionType(ConnectionType ct);

    const QString & getUser() const;
    void setUser(const QString &host);

    const QString & getPassword() const;
    void setPassword(const QString &password);

    SmtpClient::AuthMethod getAuthMethod() const;
    void setAuthMethod(AuthMethod method);

    const QString & getResponseText() const;
    int getResponseCode() const;

    int getConnectionTimeout() const;
    void setConnectionTimeout(int msec);

    int getResponseTimeout() const;
    void setResponseTimeout(int msec);

    QTcpSocket* getSocket();

    bool connectToHost();
    bool login();
    bool login(const QString &user, const QString &password, AuthMethod method = AuthLogin);

    bool sendMail(MimeMessage& email);
    void quit();

protected:    
    QTcpSocket *socket;
    QString host;
    int port;
    ConnectionType connectionType;
    QString name;

    QString user;
    QString password;
    AuthMethod authMethod;

    int connectionTimeout;
    int responseTimeout;

    QString responseText;
    int responseCode;


    class ResponseTimeoutException {};
    void waitForResponse() throw (ResponseTimeoutException);
    void sendMessage(const QString &text);    

protected slots:
    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketError(QAbstractSocket::SocketError error);
    void socketReadyRead();

signals:
    void smtpError(SmtpError e);    

};

#endif // SMTPCLIENT_H
