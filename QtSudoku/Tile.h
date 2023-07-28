#ifndef TILE_H
#define TILE_H

struct Tile
{
    unsigned int value;
    unsigned int row;
    unsigned int column;
    void eraseTile()
    {
        value=0;
    }
};


#endif // TILE_H
