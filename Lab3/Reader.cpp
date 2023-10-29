#include <QFile>
#include <QTextStream>
#include <iostream>

#include "Reader.h"

std::optional<ChartData> CSVReader::readFile(const QString& path)
{
    ChartData data;

    auto file = QFile{ path };
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    auto stream = QTextStream{ &file };

    auto line = stream.readLine().split(',');
    if (line.isEmpty()) 
        return std::nullopt;

    line.first() = line.first().split("\"").last();
    line.last() = line.last().split("\"").first();

    data.setTitle(line.first());

    //line = stream.readLine().split(',');
    //if (line.size() != 2) 
    //    return std::nullopt;

    //data.keyAxisTitle = line.first();
    //data.valueAxisTitle = line.last();

    while (!stream.atEnd()) 
    {
        auto pair = stream.readLine().split(',');
        if (pair.size() != 2) 
            return std::nullopt;

        pair.first() = pair.first().split("\"").last();
        pair.last() = pair.last().split("\"").first();

        data.addPoint({ pair.first(), pair.last() });
    }

    return data;
}
