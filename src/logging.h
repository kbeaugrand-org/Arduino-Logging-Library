#ifndef LOGGING_H
#define LOGGING_H

#define LOG_LEVEL_VERBOSE 0
#define LOG_LEVEL_DEBUG 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARNING 3
#define LOG_LEVEL_ERROR 4

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_ERROR
#endif

typedef enum LOG_CATEGORY
{
    LOG_CATEGORY_ERROR = 4,
    LOG_CATEGORY_WARNING = 3,
    LOG_CATEGORY_INFO = 2,
    LOG_CATEGORY_DEBUG = 1,
    LOG_CATEGORY_TRACE = 0
} LOG_CATEGORY;

#ifdef __cplusplus
extern "C"{
#endif

void LOGGING_LOG(LOG_CATEGORY category, const char *format, ...);

#ifdef __cplusplus
} // extern "C"
#endif

#define LOG(category, FORMAT, ...) LOGGING_LOG(category, FORMAT, ##__VA_ARGS__ )

#if LOG_LEVEL == LOG_LEVEL_VERBOSE
#define LogTrace(FORMAT, ...) LOG(LOG_CATEGORY_TRACE, FORMAT, ##__VA_ARGS__ )
#define LogDebug(FORMAT, ...) LOG(LOG_CATEGORY_DEBUG, FORMAT, ##__VA_ARGS__ )
#define LogInfo(FORMAT, ...) LOG(LOG_CATEGORY_INFO, FORMAT, ##__VA_ARGS__)
#define LogWarn(FORMAT, ...) LOG(LOG_CATEGORY_WARNING, FORMAT, ##__VA_ARGS__ )
#define LogErr(FORMAT, ...) LOG(LOG_CATEGORY_ERROR, FORMAT, ##__VA_ARGS__ )
#endif

#if LOG_LEVEL == LOG_LEVEL_DEBUG
#define LogTrace(FORMAT, ...) 
#define LogDebug(FORMAT, ...) LOG(LOG_CATEGORY_DEBUG, FORMAT, ##__VA_ARGS__ )
#define LogInfo(FORMAT, ...) LOG(LOG_CATEGORY_INFO, FORMAT, ##__VA_ARGS__)
#define LogWarn(FORMAT, ...) LOG(LOG_CATEGORY_WARNING, FORMAT, ##__VA_ARGS__ )
#define LogErr(FORMAT, ...) LOG(LOG_CATEGORY_ERROR, FORMAT, ##__VA_ARGS__ )
#endif


#if LOG_LEVEL == LOG_LEVEL_INFO
#define LogTrace(FORMAT, ...)
#define LogDebug(FORMAT, ...) 
#define LogInfo(FORMAT, ...) LOG(LOG_CATEGORY_INFO, FORMAT, ##__VA_ARGS__)
#define LogWarn(FORMAT, ...) LOG(LOG_CATEGORY_WARNING, FORMAT, ##__VA_ARGS__)
#define LogErr(FORMAT, ...) LOG(LOG_CATEGORY_ERROR, FORMAT, ##__VA_ARGS__)
#endif

#if LOG_LEVEL == LOG_LEVEL_WARNING
#define LogTrace(FORMAT, ...)
#define LogDebug(FORMAT, ...) 
#define LogInfo(FORMAT, ...)
#define LogWarn(FORMAT, ...) LOG(LOG_CATEGORY_WARNING, FORMAT, ##__VA_ARGS__)
#define LogErr(FORMAT, ...) LOG(LOG_CATEGORY_ERROR, FORMAT, ##__VA_ARGS__)
#endif

#if LOG_LEVEL == LOG_LEVEL_ERROR
#define LogTrace(FORMAT, ...)
#define LogDebug(FORMAT, ...) 
#define LogInfo(FORMAT, ...)
#define LogWarn(FORMAT, ...) 
#define LogErr(FORMAT, ...) LOG(LOG_CATEGORY_ERROR, FORMAT, ##__VA_ARGS__)
#endif

#endif