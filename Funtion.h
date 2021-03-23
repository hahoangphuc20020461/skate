#ifndef FUNTION_H_
#define FUNTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <SDL_mixer.h>
#include <vector>
#include <ctime>
#include <SDL_ttf.h>
#include <cstdlib>

#define MAX_HEIGHT 250
#define ENEMY_MAX_HEIGHT 300
#define ENEMY_MIN_HEIGHT 350
#define ENEMY_POSITION_RANGE 250
#define BASE_OFFSET_SPEED 0


const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 785;

bool init();

//tải media
bool loadMedia();

//giải phóng media và thoát SDL
void close();


SDL_Window* gWindow = NULL;


SDL_Renderer* gRenderer = NULL;

#endif
