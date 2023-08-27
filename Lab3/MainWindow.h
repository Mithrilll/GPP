#pragma once

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "ChartsView.h"
#include "FilesView.h"
#include "Reader.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();

signals:
    void fileReadSucceed(const ChartData& data);
    void fileReadFailed(const QString& error);

private slots:
    void onFileSelected(const QFileInfo& info);

private:
    // views
    FilesView *files_view{nullptr};
    ChartsView *charts_view{nullptr};
};