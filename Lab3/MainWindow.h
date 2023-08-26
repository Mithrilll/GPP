#pragma once

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "ChartsView.h"
#include "FilesView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();

private:
    // views
    FilesView *files_view{nullptr};
    ChartsView *charts_view{nullptr};
};