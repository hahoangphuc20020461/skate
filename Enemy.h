#ifndef ENEMY_H_
#define ENEMY_H_

#include "LTexture.h"
#include "Funtion.h"

#define ON_SKY 1
#define ON_GROUND 0

class enemy
{
public:
    enemy(int Type = 0);

    ~enemy();

    void loadFromFile(std::string path);

    void free();
    //Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );


    void render(SDL_Renderer* gRenderer ,SDL_Rect* currentClip);

    int GetPosX();

	int GetPosY();

	int GetWidth();

	int GetHeight();

private:
    SDL_Texture* eTexture;
    int ePosX;
    int ePosY;

    int eWidth;
    int eHeight;

    int type;

};



enemy::enemy(int Type)
{
    eTexture = NULL;
    ePosX = 0;
	ePosY = 0;

	eWidth = 0;
	eHeight = 0;
type = Type;
if(type == ON_GROUND){
    ePosX = rand()%(SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
    ePosY = 630;
}
    else{
        ePosX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
    ePosY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT + 1) + ENEMY_MIN_HEIGHT;
    }
}

enemy::~enemy()
{
	ePosX = 0;
	ePosY = 0;

	eWidth = 0;
	eHeight = 0;

	type = 0;
	if (eTexture != NULL)
	{
		eTexture = NULL;
	}
}

void enemy::free()
{
    if( eTexture != NULL )
	{
		SDL_DestroyTexture( eTexture );
		eTexture = NULL;
		eWidth = 0;
		eHeight = 0;
	}
}

void enemy::loadFromFile(std::string path)
{
    free();

    SDL_Texture* tmpTexture = NULL;

    SDL_Surface* tmpSurface = IMG_Load(path.c_str());
    if(tmpSurface == NULL){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
	{
		//Color key image
		SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        tmpTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
		if( tmpTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			eWidth = tmpSurface->w;
			eHeight = tmpSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( tmpSurface );
	}

	//Return success
	eTexture = tmpTexture;

}

void enemy::render(SDL_Renderer* gRenderer ,SDL_Rect* currentClip )
{
    SDL_Rect renderSpace = { ePosX, ePosY, eWidth, eHeight };
	if (currentClip != NULL)
	{
		renderSpace.w = currentClip->w;
		renderSpace.h = currentClip->h;
	}
	SDL_RenderCopy( gRenderer ,eTexture, currentClip, &renderSpace);
}
int enemy::GetPosX()
{
	return ePosX;
}

int enemy::GetPosY()
{
	return ePosY;
}

int enemy::GetWidth()
{
	return eWidth;
}

int enemy::GetHeight()
{
	return eHeight;
}

void enemy::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( eTexture, red, green, blue );
}

void enemy::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( eTexture, blending );
}

void enemy::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( eTexture, alpha );
}
#endif // ENEMY_H_
