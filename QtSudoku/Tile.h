#ifndef TILE_H
#define TILE_H

struct Tile
{
    unsigned int value;
    unsigned int row;
    unsigned int column;
    Tile(unsigned int v, unsigned int r, unsigned int c):value(v), row(r),column(c){}
    Tile()=default;
    void eraseTile()
    {
        value=0;
    }
};


#endif // TILE_H
