#pragma once

#include <QWidget>
#include <QPushButton>

#include "ChartData.h"

class ChartsView : public QWidget
{
	Q_OBJECT
public:
	ChartsView(QWidget* parent);

public slots:
	void onFileReadSucceed(const ChartData& data);
	void onFileReadFailed(const QString& error);

private slots:
	void onSaveClicked();

private:
	QChartView *chart_view;
	QLabel *state_label;
	QPushButton *save_button;

	ChartData chart_data;
};