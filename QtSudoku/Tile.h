#ifndef TILE_H
#define TILE_H

struct Tile
{
    int value;
    int row;
    int column;
    Tile(int v, int r, int c):value(v), row(r),column(c){}
    Tile()=default;
    void eraseTile()
    {
        value=0;
    }
};


#endif // TILE_H
