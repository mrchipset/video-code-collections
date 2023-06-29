#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file(qApp->applicationDirPath() + "/version.txt");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QByteArray version = file.readAll().trimmed();
        qDebug() << QString("Version:").append(version);
    } else {
        qDebug() << "Open file error!";
    }
    return a.exec();
}
