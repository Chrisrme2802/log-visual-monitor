#include <QCoreApplication>
#include <QDebug>
#include "core/LogEntry.h"
#include "core/LogParser.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    LogEntry entry;
    entry.timestamp = QDateTime::currentDateTime();
    entry.level = LogLevel::Info;
    entry.message = "prueba";

    qDebug() << "Log creado a las " << entry.timestamp.toString();
    qDebug() << "el mensaje es " << entry.message;

    return 0;
}