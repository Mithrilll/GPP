#pragma once
#include <optional>

#include "ChartData.h"

class IReader
{
public:
	virtual ~IReader() = default;

	virtual std::optional<ChartData> readFile(const QString& path) = 0;
};

class CSVReader : public IReader
{
public:
	std::optional<ChartData> readFile(const QString& path) override;
};
