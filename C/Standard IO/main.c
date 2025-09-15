#include <stdio.h>
#include "logger.h"

int main(){
    loggerInit(LOG_INFO, "log_file.txt");

    logMessage(LOG_DEBUG, "This is an debug message.");
    logMessage(LOG_INFO, "This is an info message.");
    logMessage(LOG_ERROR, "Something went wrong: %s", "File not found");
    logMessage(LOG_WARNING, "This is a warning message.");

    loggerSetLevel(LOG_DEBUG);
    logMessage(LOG_DEBUG, "This is another debug message after setting level to DEBUG."); 

    loggerClose();
    return 0;
}