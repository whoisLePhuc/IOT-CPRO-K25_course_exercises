#include <stdio.h>
#include <stdlib.h>
#include "PlayingState.h"
#include "StopState.h"
#include "PauseState.h"
#include "MusicPlayer.h" 

static void pressPlay(PlayerState *state){
    printf("Music is playing\n");
}

static void pressPause(PlayerState *state){
    printf("Pausing music\n");
    state->player->setState(state->player, pauseStateCreate());
}

static void pressStop(PlayerState *state){
    printf("Stopping music\n");
    state->player->setState(state->player, stopStateCreate());
}

static void setContext(PlayerState *state, struct MusicPlayer *player){
    state->player = player;
}

// Function to create Player State
PlayerState *playingStateCreate(){
    PlayerState *playingState = (PlayerState*)malloc(sizeof(PlayerState));
    playingState->pressPause = pressPause;
    playingState->pressPlay = pressPlay;
    playingState->pressStop = pressStop;
    playingState->setContext = setContext;
    playingState->player = NULL;
    return playingState;
}

