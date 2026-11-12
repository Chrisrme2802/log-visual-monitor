/**
 * @file LogEntry.h
 * @brief Define las estructuras de datos base para representar una línea de log procesada.
 */

// evita que se incluya dos veces, siempre para clases .h 
#pragma once

#include <QString>
#include <QDateTime>

/**
 * @enum LogLevel
 * @brief Niveles de severidad soportados por el monitor de logs.
 */
enum class LogLevel {
    Info,    /**< Información general del flujo normal de la aplicación. */
    Warning, /**< Advertencias que no detienen el sistema pero requieren atención. */
    Error,   /**< Errores críticos o fallos en operaciones. */
    Debug,   /**< Información detallada utilizada únicamente para depuración. */
    Unknown  /**< Nivel no reconocido o línea sin formato estándar. */
};

/**
 * @struct LogEntry
 * @brief Representa un registro de log individual ya parseado y estructurado.
 * 
 * Esta estructura es generada por el módulo @c core y consumida por los modelos
 * de la interfaz gráfica (@c LogTableModel) para su renderizado.
 */
struct LogEntry {
    QDateTime timestamp; /**< Fecha y hora exacta en que se generó el evento. */
    LogLevel level;      /**< Nivel de severidad clasificado del registro. */
    QString source;      /**< Módulo, servicio o archivo origen del log (opcional). */
    QString message;     /**< Contenido principal o descripción del evento. */
    QString rawText;     /**< Línea de texto original sin procesar (respaldo). */
};