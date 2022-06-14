#include "logging.h"

#include <Arduino.h>
#include <stdarg.h>

#define LOGGING_TRACE_STRING    "\033[35mTRACE: "
#define LOGGING_DEBUG_STRING    "\033[34mDEBUG: "
#define LOGGING_INFO_STRING     "\033[32mINFO: "
#define LOGGING_WARNING_STRING  "\033[33mWARNING: "
#define LOGGING_ERROR_STRING    "\033[31mERROR: "

#define LOGGING_END_COLOR       "\033[0m"

/**
 * @brief Returns the string corresponding to the log category in parameter.
 * 
 * @param The log_category 
 * @return const char* representing the corresponding log category; 
 */
const char *logging_get_category_string(LOG_CATEGORY log_category)
{
    switch (log_category)
    {
    case LOG_CATEGORY_ERROR: return LOGGING_ERROR_STRING;
    case LOG_CATEGORY_WARNING: return LOGGING_WARNING_STRING;
    case LOG_CATEGORY_INFO: return LOGGING_INFO_STRING;
    case LOG_CATEGORY_DEBUG: return LOGGING_DEBUG_STRING;
    case LOG_CATEGORY_TRACE: return LOGGING_TRACE_STRING;
    }

    return "";
}

/**
 * @brief Writes the log to the corresponding category.
 * 
 * @param log_category the log category.
 * @param format the log format
 * @param ... the format arguments
 */
void LOGGING_LOG(LOG_CATEGORY category, const char *format, ...)
{
    va_list args;
    char buffer[256];

    Serial.flush();

    Serial.print(logging_get_category_string(category));

    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    Serial.print(buffer);
    Serial.println(LOGGING_END_COLOR);
    Serial.flush();
}