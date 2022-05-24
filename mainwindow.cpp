#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
ui->setupUi(this);
// Crea objetos dinámicos para el manejo de todos los componentes de la interfaz.
// Por cada objeto se crea un puntero para su manejo, con el mismo identificador que
// se utilizó en el diseñador gráfico de interfaces.

//-------------We will relate the interaction with the buutons with funtions------------

connect(ui->buttonDilatation, SIGNAL(released()), this, SLOT(botonOperaClick()));
connect(ui->buttonErosion, SIGNAL(released()), this, SLOT(buttonErosionClick()));
connect(ui->buttonResizing, SIGNAL(released()), this, SLOT(buttonResizingClick()));
connect(ui->buttonLightenDarken, SIGNAL(released()), this, SLOT(buttonLightenDarkenClick()));
connect(ui->buttonPaSti, SIGNAL(released()), this, SLOT(buttonPaStiClick()));
connect(ui->buttonCaEdge, SIGNAL(released()), this, SLOT(buttonCaEdgeClick()));

}

MainWindow::~MainWindow() { // Destructor
delete ui;
}

//-----------Funtions that will be trigger after pressing the button-----------


void MainWindow::buttonDilatationClick() {

}

void MainWindow::buttonErosionClick() {
}


void MainWindow::buttonResizingClick() {

}

void MainWindow::buttonLightenDarkenClick() {

}

void MainWindow::buttonPaStiClick() {

}

void MainWindow::buttonCaEdgeClick() {

}

void MainWindow::on_pushButton_clicked()
{

    // Obtener la ruta del archivo
QString fileName = QFileDialog::getOpenFileName(this,
                                               tr("Excel file"),
                                               "./",
                                                                                                    tr ("Archivos (* .csv) ;; Texto (. txt) ;; Imagen (. jpg * .bmp * .png)"));
if(!fileName.isEmpty())
{
    // Obtener información relacionada con el archivo
QFileInfo info(fileName);
    QString file_suffix = info.suffix (); // Obtener el sufijo del archivo
//qDebug()<<"file_suffix="<<file_suffix;

    // Abrir después de juzgar el tipo de archivo
QStringList stringList;
stringList << "csv" << "txt"<<"jpg";
//0:csv 1:txt 2:jpg
if (stringList.indexOf(file_suffix)==0)
 {
      qDebug () << "Formato = csv";
      ui-> label-> clear ();
      QString result = QString::asprintf("Please select a format valid of image, only jpg");
      ui -> label -> setText(result);
 }
if (stringList.indexOf(file_suffix)==1)
 {
   qDebug () << "Formato = txt";
   ui-> label-> clear ();
   QString result = QString::asprintf("Please select a format valid of image, only jpg");
   ui -> label -> setText(result);
   }

if (stringList.indexOf(file_suffix)==2)
 {
 qDebug () << "Formato = jpg";
      openImage(fileName);
 }
}
}

// Abre la imagen (* .jpg)
void MainWindow::openImage(const QString &fileName1)
{
   ui-> label-> clear (); // Borrar el contenido de la etiqueta primero
QImage img(fileName1);
if(!img.isNull())
{
         // Qt :: KeepAspectRatio tamaño adaptativo, sin deformación
 img=img.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
 ui->label->setPixmap(QPixmap::fromImage(img));
}
}




