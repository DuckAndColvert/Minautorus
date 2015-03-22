#ifndef GLOBAL_HPP
#define GLOBAL_HPP

/**
 * \file Global.hpp
 *
 * \brief All the macros and constante values
 *
 **/
#define DATA_PATH "data/"
#define IMG_PATH "img/"

#define TILE_WIDTH 16
#define TILE_HEIGHT TILE_WIDTH

#define NB_BLOC_WIDTH 10
#define NB_BLOC_HEIGHT 10
#define BLOC_SIZE 5

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define WIDTH SCREEN_WIDTH * 3
#define HEIGHT SCREEN_HEIGHT * 3
 
#define NB_VISIBLE_TILE_WIDTH ((SCREEN_WIDTH)/(TILE_WIDTH))
#define NB_VISIBLE_TILE_HEIGHT ((SCREEN_HEIGHT)/(TILE_HEIGHT))

#define NB_TILE_WIDTH ((WIDTH)/(TILE_WIDTH))
#define NB_TILE_HEIGHT ((HEIGHT)/(TILE_HEIGHT))

#endif
