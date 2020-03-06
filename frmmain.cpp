#include "frmmain.h"
#include "ui_frmmain.h"
#include <QFileDialog>
#include <QMessageBox>
#include "myEmailTools/sendemailapi/smtpmime.h"

frmMain::frmMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);
}

frmMain::~frmMain()
{
    delete ui;
}

/******选择附件******/
void frmMain::on_btnSelect_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);   //从当前已存在目录中进行附件选择

    if (dialog.exec()){      /*关闭窗口之后，变量清空*/
        ui->txtAtta->clear();
        QStringList files=dialog.selectedFiles();
        foreach (QString file, files) {
            ui->txtAtta->setText(ui->txtAtta->text()+file+";");
        }
    }
}

bool frmMain::Check()
{
    if (ui->txtSender->text()==""){
        QMessageBox::critical(this,"错误","用户名不能为空!");
        ui->txtSender->setFocus();
        return false;
    }
    if (ui->txtSenderPwd->text()==""){
        QMessageBox::critical(this,"错误","用户密码不能为空!");
        ui->txtSenderPwd->setFocus();
        return false;
    }
    if (ui->txtSenderAddr->text()==""){
        QMessageBox::critical(this,"错误","发件人不能为空!");
        ui->txtSenderAddr->setFocus();
        return false;
    }
    if (ui->txtReceiverAddr->text()==""){
        QMessageBox::critical(this,"错误","收件人不能为空!");
        ui->txtReceiverAddr->setFocus();
        return false;
    }
    if (ui->txtTitle->text()==""){
        QMessageBox::critical(this,"错误","邮件标题不能为空!");
        ui->txtTitle->setFocus();
        return false;
    }
    return true;
}


/*****点击发送键执行内容*****/
void frmMain::on_btnSend_clicked()
{
    if (!Check()){return;}

    //实例化发送邮件对象
    SmtpClient smtp(ui->cboxServer->currentText(),
                    ui->cboxPort->currentText().toInt(),
                    ui->ckSSL->isChecked()?SmtpClient::SslConnection:SmtpClient::TcpConnection);
    smtp.setUser(ui->txtSender->text());
    smtp.setPassword(ui->txtSenderPwd->text());

    //构建邮件主题,包含发件人收件人附件等.
    MimeMessage message;
    message.setSender(new EmailAddress(ui->txtSenderAddr->text()));

    //逐个添加收件人
    QStringList receiver = ui->txtReceiverAddr->text().split(';');
    for (int i = 0; i < receiver.size(); i++){
        message.addRecipient(new EmailAddress(receiver.at(i)));
    }
    //构建邮件标题
    message.setSubject(ui->txtTitle->text());

    //构建邮件正文
    MimeHtml text;
    text.setHtml(ui->txtContent->toHtml());

    //    //如果直接发送简单文本,使用以下方法
    //    MimeText text;
    //    text.setText("测试简单文本发送!");

    message.addPart(&text);

    //构建附件
    QString atta=ui->txtAtta->text();
    if (atta!=""){
        QStringList attas=atta.split(";");
        foreach (QString tempAtta, attas) {
            QFile *file=new QFile(tempAtta);
            if (file->exists()){
                message.addPart(new MimeAttachment(file));
            }
        }
    }

    if (!smtp.connectToHost()){
        QMessageBox::critical(this,"错误","服务器连接失败!");
        return;
    }
    if (!smtp.login()){
        QMessageBox::critical(this,"错误","用户登录失败!");
        return;
    }
    if (!smtp.sendMail(message)){
        QMessageBox::critical(this,"错误","邮件发送失败!");
        return;
    }else{
        QMessageBox::information(this,"错误","邮件发送成功!");
    }
    smtp.quit();
}

void frmMain::on_cboxServer_currentIndexChanged(int index)
{
    if (index==2){
        ui->cboxPort->setCurrentIndex(1);
        ui->ckSSL->setChecked(true);
    }else{
        ui->cboxPort->setCurrentIndex(0);
        ui->ckSSL->setChecked(false);
    }
}
