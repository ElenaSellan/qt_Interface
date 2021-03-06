#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void buttonDilatationClick();
    void buttonErosionClick();
    void buttonResizingClick();
    void buttonLightenDarkenClick();
    void buttonPaStiClick();
    void buttonCaEdgeClick();

    void on_pushButton_clicked();
         void openImage (const QString & fileName1); // Abre el archivo de imagen


};
#endif // MAINWINDOW_H
