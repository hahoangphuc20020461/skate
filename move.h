#ifndef MOVE_H_
#define MOVE_H_
#include "LTexture.h"

#define JUMP 1
#define FALL 2


class Skate
{
    public:
		//The dimensions of the dot
		static const int JUMP_VEL = 1;
		static const int FALL_VEL = 1;
		static const int GROUND = 625;

		//Maximum axis velocity of the dot
		//static const int SKATE_VEL = 5;

		//Initializes the variables
		Skate();

		bool OnGround();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the backgr
		void move();

		//Shows the character on the screen
		void render();

    private:
		//The X and Y offsets of the char
		int mPosX, mPosY;

		int status;

};

Skate::Skate()
{
    //Initialize the offsets
    mPosX = SCREEN_WIDTH - 900;
    mPosY = 630;

    status = 0;
}

void Skate::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                {

                if(OnGround()){
                    status = JUMP;
                }
            }
        }
    }

}

void Skate::move()
{

    if( status == JUMP&&mPosY >= MAX_HEIGHT )
    {
        mPosY -= JUMP_VEL;
    }
    if(mPosY <=MAX_HEIGHT){
        status = FALL;
    }
    if(status == FALL&& mPosY < GROUND)
    {
        mPosY+=FALL_VEL;
    }
}

void Skate::render()
{
	gFooTexture.render( mPosX, mPosY );
}

bool Skate::OnGround()
{
    mPosY = GROUND;
}
#endif // MOVE_H_
