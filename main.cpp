//STL

//Native

//Qt
#include <QApplication>
#include <QTextStream>
#include <QTime>
#include <QDebug>

//Project
#include "mainwindow.h"
#include "info.h"

static MainWindow *local;
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream cerr(stderr);
    const QString LS = "\n";
    const QString BEGIN = "====== %1 ======" + LS;
    const QString time = "Time: " + QTime::currentTime().toString("H:m:s") + LS;
    const QString file = "File: " + QString(context.file) + LS;
    const QString function = "Function: " + QString(context.function) + LS;
    const QString line = "Line: " + QString::number(context.line) + LS;
    const QString message = "Message: " + msg + LS;

    const QString formatedMessage = BEGIN + time + file + line + function + message;

    auto makeMessage = [&](const QString &prefix) {
        cerr << formatedMessage.arg(prefix) << endl;

        if(local != nullptr) {
            local->_addLog(context.function, prefix + ": " + msg);
        }
    };

    switch (type) {
    case QtDebugMsg:
        makeMessage("debug");
        break;
    case QtWarningMsg:
        makeMessage("warning");
        break;
    case QtCriticalMsg:
        makeMessage("critical");
        break;
    case QtFatalMsg:
        makeMessage("fatal");
        abort();
    }
}

int main(int argc, char *argv[])
{

    qInstallMessageHandler(myMessageOutput);
    setlocale(LC_ALL, "Russian");

    QApplication a(argc, argv);

    //!!! Информация о программе !!!
    a.setApplicationName(Info::ApplicationName);
    a.setApplicationVersion(QString("%1.%2").arg(Info::MAJOR).arg(Info::MINOR));
    a.setOrganizationName(Info::OrganizationName);

    MainWindow w;
    local = &w;
    w.show();

    return a.exec();
}
