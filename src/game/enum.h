#ifndef __ENUM_H__
#define __ENUM_H__


enum TileType
{
	CASTLE,
	ORE_DEPOSIT,
	GRASSLAND
}

enum RoadState
{
    CONSTRUCTION,
    TRADE,
    WAR
};

enum Actions
{
    N, // Nothing
    B, // Build road to another city
    S // Send traders to another city
};


#endif // __ENUM_H__
