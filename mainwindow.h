#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define MAINWINDOW_WEBSITE_URL "http://google.com"

#include <QMainWindow>
#include <QThread>
#include "configurator.h"
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QTimer>
#include <QTime>


namespace Ui
{
    class MainWindow;
}

namespace GW2
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void EnableTransparency(bool isAlmostTransparent);
        void LinkToWebsite();
        void UpdateTime(int timeInMsecs);
        void UpdateDmg(unsigned long long dmg);
        void UpdateDps(int dps);
        void UpdateMaxDmg(int maxDmg);

        void connected();
        void disconnected();
        void netWrite(char*);
        void ready2Read();


    private:
        Ui::MainWindow *ui;
        QThread m_ScreenRecorderThread;
        Configurator m_Configurator;

        QTcpSocket *socket;

        /*
        QString PosName[10];
        QString PosDPS[10];
        QString PosDmg[10];
        QString PosAct[10];
        */

        char PosName[10][15];
        int PosDPS[10];
        long PosDmg[10];
        int PosAct[10];

        char SlotName[10][15];
        int SlotDPS[10];
        long SlotDmg[10];
        int SlotAct[10];

        long AllDamageDone;
        int GrpDPS;
        int AvgDPS;

        QByteArray incData;
        int incDataSize;
        char incData2[800];

        int CurrentPos;
        int CurrentMeta;

        char writeBuff[128];
        QByteArray tmp3;
        const char* tmp4;


        char tmp1[20];
        QTimer update_Timer;
private slots:
        void UpdateLabels();

    };

}


#endif // MAINWINDOW_H
