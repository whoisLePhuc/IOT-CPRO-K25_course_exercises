#include <stdio.h>
#include <stdlib.h>
#include "../inc/PlayingState.h"
#include "../inc/StopState.h"
#include "../inc/PauseState.h"
#include "../inc/MusicPlayer.h"


static void pressPlay(PlayerState *state){
    printf("Music is playing\n");
    state->player->setState(state->player, playingStateCreate());
}

static void pressPause(PlayerState *state){
    printf("Pausing music\n");
}

static void pressStop(PlayerState *state){
    printf("Stopping music\n");
}

static void setContext(PlayerState *state, MusicPlayer *player){
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

