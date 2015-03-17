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

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define WIDTH 640
#define HEIGHT 480

#define BLOC_WIDTH 16
#define BLOC_HEIGHT BLOC_WIDTH

#define NB_TILE_WIDTH ((WIDTH)/(BLOC_WIDTH))
#define NB_TILE_HEIGHT ((HEIGHT)/(BLOC_HEIGHT))

#endif
