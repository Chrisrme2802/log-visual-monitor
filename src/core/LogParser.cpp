#include "LogParser.h"

LogParser::LogParser() {
    m_logRegex.setPattern(R"(^\[([^\]]+)\]\s+\[([^\]]+)\]\s+\[([^\]]+)\]\s+(.*)$)");
}

LogEntry LogParser::parseLine(const QString& rawLine) {
    LogEntry entry;
    entry.rawText = rawLine;    // guardar linea original por respaldo para unknown

    QRegularExpressionMatch match = m_logRegex.match(rawLine);
    if (match.hasMatch()) {
        // date
        entry.timestamp = QDateTime::fromString(match.captured(1), "yyyy-MM-dd HH:mm:ss");

        // level
        QString levelStr = match.captured(2).toUpper();
        if (levelStr == "ERROR" || levelStr == "ERR") {
            entry.level = LogLevel::Error;
        } else if (levelStr == "WARN" || levelStr == "WARNING") {
            entry.level = LogLevel::Warning;
        } else if (levelStr == "INFO") {
            entry.level = LogLevel::Info;
        } else if (levelStr == "DEBUG") {
            entry.level = LogLevel::Debug;
        } else {
            entry.level = LogLevel::Unknown;
        }

        // source model
        entry.source = match.captured(3);
        // message
        entry.message = match.captured(4);
    } else {
        // si la linea no cumple el formato
        entry.timestamp = QDateTime::currentDateTime();
        entry.level = LogLevel::Unknown;
        entry.source = "System";
        entry.message = rawLine;
    }

    return entry;
 }