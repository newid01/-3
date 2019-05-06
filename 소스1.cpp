
#include <iostream>

#include <stdio.h>

#include <CoalaMOD.h>

#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	int px, py, pz, sx, sy, sz, ex, ey, ez;
	scanf_s("%d %d %d", &px, &py, &pz);
	scanf_s("%d %d %d", &sx, &sy, &sz);
	scanf_s("%d %d %d", &ex, &ey, &ez);

	BlockID stone = createBlock(BLOCK_STONE);
	BlockID air = createBlock(BLOCK_AIR);
	BlockID glass = createBlock(BLOCK_GLASS);
	DoorID door = createDoor(DOOR_OAK, false, HINGE_LEFT);
	TorchID torch = createTorch();


	for (int a = px - (ex - sx) / 2; a <= px + (ex - sx) / 2; a++)
	{
		for (int c = pz - (ez - sz) / 2; c <= pz + (ez - sz) / 2; c++)
		{
			for (int b = py; b <= py + (ey - sy) ; b++)
			{
				locateBlock(stone, a, b, c);
			}
		}
	}


	for (int a = px - (ex - sx) / 2; a <= px + (ex - sx) / 2; a++)
	{
		for (int c = pz - (ez - sz) / 2; c <= pz + (ez - sz) / 2; c++)
		{

			locateBlock(glass, a, py + (ey - sy) / 2, c);

		}
	}


	
	for (int a = px - (ex - sx) / 2 + 1; a <= px + (ex - sx) / 2 - 1; a++)
	{
		for (int c = pz - (ez - sz) / 2 + 1; c <= pz + (ez - sz) / 2 - 1; c++)
		{
			for (int b = py; b <= py + (ey - sy) - 1; b++)
			{
				locateBlock(air, a, b, c);
			}
		}
	}

	locateBlock(stone, px - (ex - sx) / 2, py + (ey - sy) / 2, pz - (ez - sz) / 2);
	locateBlock(stone, px - (ex - sx) / 2, py + (ey - sy) / 2, pz + (ez - sz) / 2);
	locateBlock(stone, px + (ex - sx) / 2, py + (ey - sy) / 2, pz - (ez - sz) / 2);
	locateBlock(stone, px + (ex - sx) / 2, py + (ey - sy) / 2, pz + (ez - sz) / 2);
	locateBlock(air, px, py, pz - (ez - sz) / 2);
	installDoor(door, px, py, pz - (ez - sz) / 2, FACING_SOUTH);

	/*for (int a = px - (ex - sx) / 2 + 1; a <= px + (ex - sx) / 2 - 1; a++)
	{
		for (int c = pz - (ez - sz) / 2 + 1; c <= pz + (ez - sz) / 2 - 1; c++)
		{

			locateBlock(glass, a, py + (ey - sy), c);

		}
	}
	
	for (int a = px - (ex - sx) / 2 + 2; a <= px + (ex - sx) / 2 - 2; a++)
	{
		for (int c = pz - (ez - sz) / 2 + 2; c <= pz + (ez - sz) / 2 - 2; c++)
		{

			locateBlock(stone, a, py + (ey - sy), c);

		}
	}

	for (int a = px - (ex - sx) / 2 + 1; a <= px + (ex - sx) / 2 - 1; a++)
	{
		
			locateBlock(glass, a, py + (ey - sy), pz);

	}

	for (int c = pz - (ez - sz) / 2 + 1; c <= pz + (ez - sz) / 2 - 1; c++)
	{

		locateBlock(glass, px , py + (ey - sy), c);

	}
	*/

	installTorch(torch, px - (ex - sx) / 2 + 1, py + (ey - sy) / 2 - 2, pz, FACING_EAST);
	installTorch(torch, px + (ex - sx) / 2 - 1, py + (ey - sy) / 2 - 2, pz, FACING_WEST);


	return 0;



}