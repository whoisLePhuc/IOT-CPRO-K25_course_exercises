#include <stdio.h>
#include <stdlib.h>
#include "smart_home_facade/smart_home_facade.c"

int main(){
    SmartHomeFacade* smartHome = createSmartHomeFacade();
    
    printf(">>> Activating morning routine:\n");
    activateMorningRoutine(smartHome);
    
    printf("\n>>> Activating away mode:\n");
    activateAwayMode(smartHome);
    
    printf("\n>>> Setting movie night scene:\n");
    setMovieNightScene(smartHome);
    
    free(smartHome->security);
    free(smartHome->light);
    free(smartHome->hvac);
    free(smartHome);
    
    return 0;
}