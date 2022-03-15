# Pac-Man
Northwestern CS 211 Final Project: Pac-Man level 1

## Description:<br/>
This is a copy of Pac-Man the arcade game modeled after Level 1.

## Instructions:<br/>
- Use the up/down/left/right arrow keys to control the movement of the Pac-Man sprite<br/>
- Each game initializes with three lives<br/>
- Player loses one life every time Pac-Man collides with a ghost sprite<br/>
- Respawn back into the game at Pac-Man's starting position with the space key<br/>
- Each small dot in the maze is worth 10 points<br/>
- Each big dot in the maze is worth 50 points<br/>
- If Pac-Man eats a big dot, the ghosts will be "edible" for 10 seconds–player gains 100 points for every ghost "eaten"<br/>
- The ghosts will respawn at their starting positions<br/>
- Player wins the game if all the big and small dots and eaten, and Pac-Man has at least one life left<br/>
- "q" key on keyboard quits the game

## Specifications:<br/>
- Maze is constructed as a 2D array with each entry as empty space, wall, small dot or big dot and perfectly outlines the original Pac-Man arcade game dimensions<br/>
- Background is added as a picture sprite sized to the maze dimensions<br/>
- Pac-Man moves on controller arrow keys, turning 90 * x degrees with specified key<br/>
- Ghost movements did not use A* Algorithm<br/>
- Red Ghost minimizes the distance with Pac-Man and is initialized outside the cage<br/>
- Blue Ghost maximizes the distance with Pac-Man and is initialized inside the cage<br/>
- Pink Ghost moves randomly and is initialized inside the cage<br/>
- Yellow Ghost moves sometimes to minimize the distance and other times to maximize the distance with Pacman and is initialized inside the cage<br/>
- Cherry sprite is for decoration<br/>
- Background siren music plays continuously<br/>
