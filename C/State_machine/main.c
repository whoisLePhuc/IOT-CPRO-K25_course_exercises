#include <stdio.h>
#include "MusicPlayer.h"
#include "StopState.h"

int main(){
    // Create player with inintial state: Stopped
    MusicPlayer *player = musicPlayerCreate(stopStateCreate());

    // Simulate button press
    player->clickStopButton(player);
    player->clickPlayButton(player);
    player->clickPauseButton(player);
    player->clickStopButton(player);

    musicPlayerDestroy(player);
    return 0;
}