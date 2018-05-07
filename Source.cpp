#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

int main() {
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_BITMAP*Sapphire = NULL;
	ALLEGRO_BITMAP*Ruby = NULL;
	ALLEGRO_BITMAP*Diamond = NULL;
	ALLEGRO_BITMAP*Emerald = NULL;

	int map[10][10] = {
		1,4,1,3,2,4,4,3,1,2,
		2,1,4,2,3,1,4,2,3,1,
		1,4,2,1,3,2,3,1,2,4,
		1,2,1,3,4,1,4,3,2,1,
		4,4,2,1,4,2,3,1,4,2,
		1,2,1,4,2,1,2,1,3,1,
		3,4,2,3,1,1,4,2,3,2,
		1,2,1,3,4,3,2,1,2,1,
		1,4,2,1,2,1,3,1,4,3,
		3,1,4,2,4,4,1,2,4,1,
	 };

	al_init();
	al_init_image_addon();

	display = al_create_display(400, 400);

	Sapphire = al_load_bitmap("sapphire_50x50.png");
	Ruby = al_load_bitmap("ruby_50x50.png");
	Diamond = al_load_bitmap("diamond_50x50.png");
	Emerald = al_load_bitmap("emerald_50x50.png");

	

	for (int x = 0; x < 10; x++)  // loop 3 times for three lines
	{
		for (int y = 0; y < 10; y++)  // loop for the three elements on the line
		{
			//check if matrix holds a "1"
			if (map[x][y] == 1)
				al_draw_bitmap(Sapphire, y * 40, x * 40, NULL);
			if (map[x][y] == 2)
				al_draw_bitmap(Ruby, y * 40, x * 40, NULL);
			if (map[x][y] == 3)
				al_draw_bitmap(Diamond, y * 40, x * 40, NULL);
			if (map[x][y] == 4)
				al_draw_bitmap(Emerald, y * 40, x * 40, NULL);


			al_flip_display();

			
			al_rest(.1);
		}
	}
	al_destroy_bitmap(Sapphire);
	al_destroy_bitmap(Ruby);
	al_destroy_bitmap(Diamond);
	al_destroy_bitmap(Emerald);
	al_destroy_display(display);
}