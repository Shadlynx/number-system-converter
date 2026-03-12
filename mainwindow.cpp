#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "entrypoint.h"

#include <cstdlib>
#include <cstring>
#include <QString>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initContext();

    connect(ui->inputLineEdit, &QLineEdit::textChanged, this, &MainWindow::onInputChanged);

    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::onConvertClicked);

    connect(ui->sourceBaseComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onSourceBaseChanged);

    connect(ui->targetBaseComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTargetBaseChanged);

    updateUiFromContext();
}

MainWindow::~MainWindow()
{
    if (context.inputValue)
        free(context.inputValue);

    if (context.outputValue)
        free(context.outputValue);

    if (context.errorMessage)
        free(context.errorMessage);

    delete ui;
}

void MainWindow::initContext()
{
    context.sourceBase = 10;
    context.targetBase = 2;

    context.inputValue = NULL;
    context.outputValue = NULL;

    context.parsedValue = 0;

    context.hasError = 0;
    context.errorMessage = NULL;
}

void MainWindow::readUiToContext()
{
    context.sourceBase = ui->sourceBaseComboBox->currentText().toInt();
    context.targetBase = ui->targetBaseComboBox->currentText().toInt();

    if (context.inputValue)
    {
        free(context.inputValue);
        context.inputValue = NULL;
    }

    QByteArray arr = ui->inputLineEdit->text().toLocal8Bit();
    context.inputValue = (char*)malloc(arr.size() + 1);
    strcpy(context.inputValue, arr.constData());
}

void MainWindow::updateUiFromContext()
{
    if (context.outputValue)
        ui->outputLineEdit->setText(QString::fromLocal8Bit(context.outputValue));
    else
        ui->outputLineEdit->clear();

    if (context.hasError && context.errorMessage)
        ui->errorLineEdit->setText(QString::fromLocal8Bit(context.errorMessage));
    else
        ui->errorLineEdit->clear();
}

void MainWindow::onInputChanged()
{
    readUiToContext();
    doOperation(ValidateInput, &context);
    updateUiFromContext();
}

void MainWindow::onConvertClicked()
{
    readUiToContext();
    doOperation(ConvertValue, &context);
    updateUiFromContext();
}

void MainWindow::onSourceBaseChanged()
{
    readUiToContext();
    doOperation(ValidateInput, &context);
    updateUiFromContext();
}

void MainWindow::onTargetBaseChanged()
{
    readUiToContext();
    updateUiFromContext();
}
