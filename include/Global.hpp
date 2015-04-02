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

#define TILE_WIDTH 32
#define TILE_HEIGHT TILE_WIDTH

/* blocs */
#define NB_BLOC_WIDTH 7
#define NB_BLOC_HEIGHT 7
#define BLOC_SIZE 4

/* screen */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define WIDTH SCREEN_WIDTH*5
#define HEIGHT SCREEN_HEIGHT*5
 
#define NB_VISIBLE_TILE_WIDTH (((SCREEN_WIDTH)/(TILE_WIDTH)) + 1)
#define NB_VISIBLE_TILE_HEIGHT (((SCREEN_HEIGHT)/(TILE_HEIGHT)) + 1)

#define NB_TILE_WIDTH ((WIDTH)/(TILE_WIDTH))
#define NB_TILE_HEIGHT ((HEIGHT)/(TILE_HEIGHT))

/* chunks */
#define CHUNK_WIDTH (NB_TILE_WIDTH/4)
#define CHUNK_HEIGHT (NB_TILE_HEIGHT/4)

#define NB_CHUNK_WIDTH NB_TILE_WIDTH/CHUNK_WIDTH
#define NB_CHUNK_HEIGHT NB_TILE_HEIGHT/CHUNK_HEIGHT

/* tileset */
#define TILESET_WIDTH 8
#define TILESET_HEIGHT TILESET_WIDTH
#endif
