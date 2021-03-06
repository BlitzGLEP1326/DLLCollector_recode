#ifndef SELECTPROCESS_H
#define SELECTPROCESS_H

//STL

//Native

//Qt
#include <QDialog>

//Project

namespace Ui {
    class SelectProcess;
}

class SelectProcess : public QDialog {
    Q_OBJECT

private:
    Ui::SelectProcess *ui;
    uint m_PID = -1;

public:
    explicit SelectProcess(QWidget *parent = 0);
    ~SelectProcess();
    qint64 getPID() const;

signals:
    void processSelected(uint PID);

private slots:
    void on_pushButton_Update_clicked();
    void on_processList_itemSelectionChanged();
    void on_pushButton_Ok_clicked();

private:
    void updateProcessList();
};

#endif // SELECTPROCESS_H
