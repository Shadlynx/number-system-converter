#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcontext.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AppContext context;

    void initContext();
    void readUiToContext();
    void updateUiFromContext();

    void onInputChanged();
    void onConvertClicked();
    void onSourceBaseChanged();
    void onTargetBaseChanged();
};

#endif
