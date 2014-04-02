space_invaders
==============

The project is a 3d clone of space invaders. It uses cubes to draw the
sprites.

Keyboard input is implemented through glut keyboard handlers. The controls
are: w - shoot
     a - move left
     d - move right

Text is drawn using glut's glutStrokeString. We use this for the score,
game over screen, and start screen.

File Structure
==============

main.cpp
main entry point. Initializes the game class and runs it.

game.cpp
Contains the initialization, and game logic code.

enemy.cpp bullet.cpp particle.cpp player.cpp
Game objects. Include draw and update calls.
