/**
 * @file LogParser.h
 * @brief Declaración de la clase encargada de analizar y estructurar líneas de log.
 */

#pragma once

#include "LogEntry.h"
#include <QRegularExpression>

/**
 * @class LogParser
 * @brief Transforma líneas de texto plano provenientes de archivos de log en estructuras @c LogEntry.
 * 
 * Utiliza expresiones regulares para extraer la marca de tiempo, el nivel de severidad,
 * el módulo de origen y el cuerpo del mensaje. Si una línea no coincide con el formato
 * esperado, la clasifica como @c LogLevel::Unknown conservando el texto original.
 */
class LogParser {
public:
    /**
     * @brief Constructor por defecto. Inicializa las expresiones regulares de análisis.
     */
    LogParser();

    /**
     * @brief Procesa una línea individual de texto y extrae sus componentes.
     * @param rawLine Cadena de texto sin procesar leída directamente del archivo fuente.
     * @return LogEntry Estructura con los campos separados y tipados.
     */
    LogEntry parseLine(const QString& rawLine);

private:
    QRegularExpression m_logRegex; /**< Expresión regular compilada para parsear el formato estándar. */
};