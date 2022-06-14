#ifndef LOGGING_H
#define LOGGING_H

#define LOG_LEVEL_NONE 0
#define LOG_LEVEL_VERBOSE 1
#define LOG_LEVEL_DEBUG 2
#define LOG_LEVEL_INFO 3
#define LOG_LEVEL_WARNING 4
#define LOG_LEVEL_ERROR 5

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_NONE
#endif

typedef enum LOG_CATEGORY
{
    LOG_CATEGORY_ERROR = 4,
    LOG_CATEGORY_WARNING = 3,
    LOG_CATEGORY_INFO = 2,
    LOG_CATEGORY_DEBUG = 1,
    LOG_CATEGORY_TRACE = 0
} LOG_CATEGORY;

#define LOGGING_TRACE_STRING    "\033[35mTRACE: "
#define LOGGING_DEBUG_STRING    "\033[34mDEBUG: "
#define LOGGING_INFO_STRING     "\033[32mINFO: "
#define LOGGING_WARNING_STRING  "\033[33mWARNING: "
#define LOGGING_ERROR_STRING    "\033[31mERROR: "

#define LOGGING_END_COLOR       "\033[0m"

#define LOGGING_BUFFER_SIZE 256

extern char LOGGING_BUFFER[LOGGING_BUFFER_SIZE];

#define LOG(category, FORMAT, ...) do { \
    Serial.print(LOGGING_TRACE_STRING); \
    sprintf(LOGGING_BUFFER, FORMAT, ##__VA_ARGS__); \
    Serial.print(LOGGING_BUFFER); \
    Serial.println(LOGGING_END_COLOR); \
} while (0);

#if LOG_LEVEL == LOG_LEVEL_VERBOSE
#define LogTrace(FORMAT, ...) LOG(LOGGING_TRACE_STRING, FORMAT, ##__VA_ARGS__ )
#define LogDebug(FORMAT, ...) LOG(LOGGING_DEBUG_STRING, FORMAT, ##__VA_ARGS__ )
#define LogInfo(FORMAT, ...) LOG(LOGGING_INFO_STRING, FORMAT, ##__VA_ARGS__)
#define LogWarn(FORMAT, ...) LOG(LOGGING_WARNING_STRING, FORMAT, ##__VA_ARGS__ )
#define LogErr(FORMAT, ...) LOG(LOGGING_ERROR_STRING, FORMAT, ##__VA_ARGS__ )
#endif

#if LOG_LEVEL == LOG_LEVEL_DEBUG
#define LogTrace(FORMAT, ...) do { (void)0; } while (0)
#define LogDebug(FORMAT, ...) LOG(LOGGING_DEBUG_STRING, FORMAT, ##__VA_ARGS__ )
#define LogInfo(FORMAT, ...) LOG(LOGGING_INFO_STRING, FORMAT, ##__VA_ARGS__)
#define LogWarn(FORMAT, ...) LOG(LOGGING_WARNING_STRING, FORMAT, ##__VA_ARGS__ )
#define LogErr(FORMAT, ...) LOG(LOGGING_ERROR_STRING, FORMAT, ##__VA_ARGS__ )
#endif


#if LOG_LEVEL == LOG_LEVEL_INFO
#define LogTrace(FORMAT, ...) do { (void)0; } while (0)
#define LogDebug(FORMAT, ...) do { (void)0; } while (0)
#define LogInfo(FORMAT, ...) LOG(LOGGING_INFO_STRING, FORMAT, ##__VA_ARGS__)
#define LogWarn(FORMAT, ...) LOG(LOGGING_WARNING_STRING, FORMAT, ##__VA_ARGS__)
#define LogErr(FORMAT, ...) LOG(LOGGING_ERROR_STRING, FORMAT, ##__VA_ARGS__)
#endif

#if LOG_LEVEL == LOG_LEVEL_WARNING
#define LogTrace(FORMAT, ...) do { (void)0; } while (0)
#define LogDebug(FORMAT, ...) do { (void)0; } while (0)
#define LogInfo(FORMAT, ...) do { (void)0; } while (0)
#define LogWarn(FORMAT, ...) LOG(LOGGING_WARNING_STRING, FORMAT, ##__VA_ARGS__)
#define LogErr(FORMAT, ...) LOG(LOGGING_ERROR_STRING, FORMAT, ##__VA_ARGS__)
#endif

#if LOG_LEVEL == LOG_LEVEL_ERROR
#define LogTrace(FORMAT, ...) do { (void)0; } while (0)
#define LogDebug(FORMAT, ...) do { (void)0; } while (0)
#define LogInfo(FORMAT, ...) do { (void)0; } while (0)
#define LogWarn(FORMAT, ...) do { (void)0; } while (0)
#define LogErr(FORMAT, ...) LOG(LOGGING_ERROR_STRING, FORMAT, ##__VA_ARGS__)
#endif

#if LOG_LEVEL == LOG_LEVEL_NONE
#define LogTrace(FORMAT, ...) do { (void)0; } while (0)
#define LogDebug(FORMAT, ...) do { (void)0; } while (0)
#define LogInfo(FORMAT, ...) do { (void)0; } while (0)
#define LogWarn(FORMAT, ...) do { (void)0; } while (0)
#define LogErr(FORMAT, ...) do { (void)0; } while (0)
#endif

#endif