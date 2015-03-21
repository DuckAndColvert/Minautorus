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



#define TILE_WIDTH 4
#define TILE_HEIGHT TILE_WIDTH

#define NB_BLOC_WIDTH 30
#define NB_BLOC_HEIGHT 30
#define BLOC_SIZE 5

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define WIDTH SCREEN_WIDTH
#define HEIGHT SCREEN_HEIGHT

#define NB_TILE_WIDTH ((WIDTH)/(TILE_WIDTH))
#define NB_TILE_HEIGHT ((HEIGHT)/(TILE_HEIGHT))

#endif
