#include <stdio.h>
#include <stdlib.h>
#include "../inc/MusicPlayer.h"

// Button event implemetations
static void clickPlayButton(MusicPlayer *player){
    if(player->currentState && player->currentState->pressPlay)
        player->currentState->pressPlay(player->currentState);
}

static void clickStopButton(MusicPlayer *player){
    if(player->currentState && player->currentState->pressStop)
        player->currentState->pressStop(player->currentState);
} 

static void clickPauseButton(MusicPlayer *player){
    if(player->currentState && player->currentState->pressPause)
        player->currentState->pressPause(player->currentState);
}

// Function for changing state
static void setState(MusicPlayer *player, PlayerState *newState){
    // free old state
    if(player->currentState) 
        free(player->currentState);
    player->currentState = newState;
    if(player->currentState && player->currentState->setContext)
        player->currentState->setContext(player->currentState, player);
}

// Function to create music player
MusicPlayer* musicPlayerCreate(PlayerState *initialState){
    MusicPlayer *musicPlayer = (MusicPlayer*)malloc(sizeof(MusicPlayer));
    musicPlayer->currentState = initialState;
    musicPlayer->clickPlayButton = clickPlayButton;
    musicPlayer->clickPauseButton = clickPauseButton;
    musicPlayer->clickStopButton = clickStopButton;
    if(initialState && initialState->setContext)
        initialState->setContext(initialState, musicPlayer);
    return musicPlayer;
}

// Function to destroy music player
void musicPlayerDestroy(MusicPlayer *player){
    if(player){
        if(player->currentState)
            free(player->currentState);
        free(player);
    }
}


