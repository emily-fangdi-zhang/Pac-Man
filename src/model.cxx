#include "model.hxx"
#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdio.h>

Model::Model(Game_config const& config)
        : config(config)
{
    // initialize
    for (int i = 0; i <= 27; i++) {

        for (int j = 0; j <= 35; j++) {
            layout[i][j] = 0;
        }
    }

    // top wall
    for (int i = 0; i <= 27; i++) {
        layout[i][3] = 1;
    }

    // bottom wall
    for (int i = 0; i <= 27; i++) {
        layout[i][33] = 1;
    }

    // left wall
    for (int j = 4; j <= 33; j++) {
        if (j == 13 || j == 14 || j == 15 || j == 19 || j == 20 || j == 21 ||
        j == 17) {
            ;
        } else {
            layout[0][j] = 1;
            layout[27][j] = 1;
        }
    }

    // x=10  y=15 to 17, 19
    // box
    for (int i = 10; i <= 16; i++) {
        layout[i][15] = 1;
        layout[i][19] = 1;

    } for (int j = 15; j <= 19; j++) {
        layout[10][j] = 1;
        layout[17][j] = 1;
    }

    // 2,5 to 25,7
    for (int i = 2; i <= 25; i++) {

        for (int j = 5; j <= 7; j++) {

            // empty spots
            if((i == 6 || i == 12 || i ==15 || i ==21)) {
                ;

            } else {
                layout[i][j] = 1;
            }
        }
    }

    // divider
    layout[13][4] = 1;
    layout[14][4] = 1;

    // top obstacles
    // 2, 9 to 25, 10
    for (int i = 2; i <= 25; i++) {

        for (int j = 9; j<=10; j++) {

            if (i == 6 || i == 9 || i ==18 || i == 21) {
                ;
            } else {
                layout[i][j] = 1;
            }
        }
    }

    // left obstacle
    // 7,11 to  8,22
    for (int i = 7; i <= 8; i++) {

        for(int j = 11; j <= 31; j++) {

            if (j == 17|| j == 23 || j == 26) {
                ;
            } else {
                layout[i][j] =1;
            }
        }
    }

    // right obstacle
    for (int i = 19; i <= 20; i++) {

        for(int j = 11; j <= 31; j++) {

            if (j == 17|| j == 23 || j == 26) {
                ;
            } else {
                layout[i][j] =1;
            }
        }
    }

    // bottom obstacle
    // 2, 30 to 25,31
    for (int i = 2; i <=25; i++) {

        for (int j = 30; j <=31; j++) {

            if (i ==12|| i ==15) {
                ;
            } else {
                layout[i][j] = 1;
            }
        }
    }

    // top bottom obstacle
    // 2,24 to 25, 25
    for (int i = 2; i <= 25; i++) {

        for (int j = 24; j <= 25; j++) {

            if (i == 6 || i == 12 || i == 15 || i ==21) {
                ;
            } else {
                layout[i][j] = 1;
            }
        }
    }
    // from 0,12 to 27,13
    for (int i = 0; i <= 27; i++) {

        for (int j = 12; j <= 13; j++) {

            if (i == 6 || i == 12 || i == 15 || i ==21) {
                ;

            } else {
                layout[i][j] = 1;
            }
        }
    }

    // from 0,21 to 27,22
    for (int i = 0; i <= 27; i++) {

        for (int j = 21; j <= 22; j++) {

            if (i == 6 || i == 9 || i == 18 || i ==21) {
                ;
            } else {
                layout[i][j] = 1;
            }
        }
    }

    // from 4，14 to 5, 28
    for (int i = 4; i <= 5; i++) {

        for (int j = 14; j <= 28; j++) {

            if (j == 17 || j == 23) {
                ;
            } else {
                layout[i][j] = 1;
            }
        }
    }

    // from 22，14 to 23, 28
    for (int i = 22; i <= 23; i++) {

        for (int j = 14; j <= 28; j++) {

            if (j == 17 || j == 23) {
                ;

            } else {
                layout[i][j] = 1;
            }
        }
    }

    // connect entrance and obstacles
    for (int i = 0; i <= 5; i++) {
        layout[i][16] = 1;
    }
    for (int i = 0; i <= 5; i++) {
        layout[i][18] = 1;
    }

    for (int i = 22; i <= 27; i++) {
        layout[i][16] = 1;
    }
    for (int i = 22; i <= 27; i++) {
        layout[i][18] = 1;
    }

    // bottom obstacle
    for (int i = 10; i <= 17; i++) {
        layout[i][27] = 1;
        layout[i][28] = 1;
    }

    layout[13][11] = 1;
    layout[14][11] = 1;
    layout[13][23] = 1;
    layout[14][23] = 1;
    layout[13][29] = 1;
    layout[14][29] = 1;

    layout[1][27] = 1;
    layout[2][27] = 1;
    layout[1][28] = 1;
    layout[2][28] = 1;

    layout[25][27] = 1;
    layout[26][27] = 1;
    layout[25][28] = 1;
    layout[26][28] = 1;

    layout[1][27] = 1;
    layout[2][27] = 1;
    layout[1][28] = 1;
    layout[2][28] = 1;

    // clear excess wall
    for (int i = 0; i <= 4; i++) {
        layout[i][13] = 0;
        layout[i][14] = 0;
        layout[i][15] = 0;
        layout[i][19] = 0;
        layout[i][20] = 0;
        layout[i][21] = 0;
    }

    for (int i = 23; i <= 27; i++) {
        layout[i][13] = 0;
        layout[i][14] = 0;
        layout[i][15] = 0;
        layout[i][19] = 0;
        layout[i][20] = 0;
        layout[i][21] = 0;
    }

    // add big dot
    layout[1][6] = 3;
    layout[26][6] = 3;
    layout[1][26] = 3;
    layout[26][26] = 3;

    // add dots
    // 1:23, 25:34
    for (int i = 1; i <= 26; i++) {

        for (int j = 23; j <= 33; j++) {

            if (layout[i][j] != 1 && layout[i][j] != 3) {
                layout[i][j] = 2;
            }
        }
    }

    // 1:4, 26:11
    for (int i = 1; i <= 26; i++) {

        for (int j = 4; j <= 11; j++) {

            if (layout[i][j] != 1 && layout[i][j] != 3) {
                layout[i][j] = 2;
            }
        }
    }

    // 6:12 , 6:22
    for (int j = 12; j <= 22; j++) {
        layout[6][j] = 2;
    }

    // 21:12 , 21:22
    for (int j = 12; j <= 22; j++) {
        layout[21][j] = 2;
    }

    // clear dot for pacman
    layout[13][26] = 0;
    layout[14][26] = 0;

    // prison
    for (int i = 0; i <= 4; i++) {
        layout[i][14] = 1;
    }

    layout[2][13] = 1;
    layout[2][15] = 1;
}

float
Model::distance(Position pos_1, Position pos_2)
{
    return pow(pow((pos_1.x - pos_2.x), 2) +
    pow((pos_1.y - pos_2.y), 2), 0.5);
}

bool
Model::is_in_bound(Position pos_player)
{
    if (pos_player.x < 28 && pos_player.y < 36 && pos_player.x >= 0 &&
        pos_player.y >= 0) {
        return true;

    } else {
        return false;
    }
}

bool
Model::is_win()
{
    if (lives >= 0) {
        if (dots + big_dots == 0) {
            is_game_over = true;
            return true;
        }
    }

    return false;
}

void
Model::move_pacman(char dir)
{

    if (dir == 'u' &&
        !is_collision({pos_pacman.x, pos_pacman.y - 1})) {
        pos_pacman.y = pos_pacman.y - 1;

    } else if (dir == 'd' &&
        !is_collision({pos_pacman.x, pos_pacman.y + 1})) {
        pos_pacman.y = pos_pacman.y + 1;

    } else if (dir == 'l' &&
        !is_collision({pos_pacman.x - 1, pos_pacman.y})) {

        if (!is_in_bound({pos_pacman.x - 1, pos_pacman.y})) {
            pos_pacman = {pos_pacman.x + 27, pos_pacman.y};

        } else {
            pos_pacman.x = pos_pacman.x - 1;
        }

    } else if (dir == 'r' &&
        !is_collision({pos_pacman.x + 1, pos_pacman.y})) {

        if (!is_in_bound({pos_pacman.x + 1, pos_pacman.y})) {
            pos_pacman = {pos_pacman.x % 27, pos_pacman.y};

        } else {
            pos_pacman.x = pos_pacman.x + 1;
        }
    }
}

void
Model::move_red_ghost()
{
    int curr_dist = distance(pos_pacman, pos_red_ghost);

    Position pos_red_ghost_up = {pos_red_ghost.x, pos_red_ghost.y - 1};
    Position pos_red_ghost_down = {pos_red_ghost.x, pos_red_ghost.y + 1};
    Position pos_red_ghost_left = {pos_red_ghost.x - 1, pos_red_ghost.y};
    Position pos_red_ghost_right = {pos_red_ghost.x + 1, pos_red_ghost.y};

        if (distance(pos_pacman, pos_red_ghost_up) <= curr_dist &&
            !is_ghost_collision(pos_red_ghost_up)) {
            is_red_ghost_moving = true;
            red_ghost_desired_x = pos_red_ghost_up.x;
            red_ghost_desired_y = pos_red_ghost_up.y;

        } else if (distance(pos_pacman, pos_red_ghost_down) <=
            curr_dist && !is_ghost_collision(pos_red_ghost_down)) {
            is_red_ghost_moving = true;
            red_ghost_desired_x = pos_red_ghost_down.x;
            red_ghost_desired_y = pos_red_ghost_down.y;

        } else if (distance(pos_pacman, pos_red_ghost_left) <=
            curr_dist && !is_ghost_collision(pos_red_ghost_left)) {
            is_red_ghost_moving = true;
            red_ghost_desired_x = pos_red_ghost_left.x;
            red_ghost_desired_y = pos_red_ghost_left.y;

        } else if (distance(pos_pacman, pos_red_ghost_right) <=
        curr_dist && !is_ghost_collision(pos_red_ghost_right)) {
            is_red_ghost_moving = true;
            red_ghost_desired_x = pos_red_ghost_right.x;
            red_ghost_desired_y = pos_red_ghost_right.y;
        }
}

void
Model::move_blue_ghost()
{
    int curr_dist = distance(pos_pacman, pos_blue_ghost);

    Position pos_blue_ghost_up = {pos_blue_ghost.x,
                                  pos_blue_ghost.y - 1};
    Position pos_blue_ghost_down = {pos_blue_ghost.x,
                                    pos_blue_ghost.y + 1};
    Position pos_blue_ghost_left = {pos_blue_ghost.x - 1,
                                    pos_blue_ghost.y};
    Position pos_blue_ghost_right = {pos_blue_ghost.x + 1,
                                     pos_blue_ghost.y};

    if (distance(pos_pacman, pos_blue_ghost_up) >= curr_dist &&
        !is_ghost_collision(pos_blue_ghost_up)) {
        pos_blue_ghost.x = pos_blue_ghost_up.x;
        pos_blue_ghost.y = pos_blue_ghost_up.y;

    } else if (distance(pos_pacman, pos_blue_ghost_down) >=
        curr_dist && !is_ghost_collision(pos_blue_ghost_down)) {
        pos_blue_ghost.x = pos_blue_ghost_down.x;
        pos_blue_ghost.y = pos_blue_ghost_down.y;

    } else if (distance(pos_pacman, pos_blue_ghost_left) >=
        curr_dist && !is_ghost_collision(pos_blue_ghost_left)) {
        pos_blue_ghost.x = pos_blue_ghost_left.x;
        pos_blue_ghost.y = pos_blue_ghost_left.y;

    } else if (distance(pos_pacman, pos_blue_ghost_right) >=
        curr_dist && !is_ghost_collision(pos_blue_ghost_right)) {
        pos_blue_ghost.x = pos_blue_ghost_right.x;
        pos_blue_ghost.y = pos_blue_ghost_right.y;
    }
}

void
Model::move_pink_ghost()
{
    double prob = (double) rand() / (RAND_MAX);

    Position pos_pink_ghost_up = {pos_pink_ghost.x,
                                  pos_pink_ghost.y - 1};
    Position pos_pink_ghost_down = {pos_pink_ghost.x,
                                    pos_pink_ghost.y + 1};
    Position pos_pink_ghost_left = {pos_pink_ghost.x - 1,
                                    pos_pink_ghost.y};
    Position pos_pink_ghost_right = {pos_pink_ghost.x + 1,
                                     pos_pink_ghost.y};

    if (0.0 <= prob && prob <= 0.25 && !is_ghost_collision(pos_pink_ghost_up)) {
        pos_pink_ghost.x = pos_pink_ghost_up.x;
        pos_pink_ghost.y = pos_pink_ghost_up.y;

    } else if (0.25 < prob && prob <= 0.50 &&
        !is_ghost_collision(pos_pink_ghost_down)) {
        pos_pink_ghost.x = pos_pink_ghost_down.x;
        pos_pink_ghost.y = pos_pink_ghost_down.y;

    } else if (0.50 < prob && prob <= 0.75 &&
        !is_ghost_collision(pos_pink_ghost_left)) {
        pos_pink_ghost.x = pos_pink_ghost_left.x;
        pos_pink_ghost.y = pos_pink_ghost_left.y;

    } else if (!is_ghost_collision(pos_pink_ghost_right)) {
        pos_pink_ghost.x = pos_pink_ghost_right.x;
        pos_pink_ghost.y = pos_pink_ghost_right.y;
    }
}

void
Model::move_yellow_ghost()
{
    double prob = (double) rand() / (RAND_MAX);

    if (0.0 <= prob && prob < 0.10) {
        int curr_dist = distance(pos_pacman, pos_yellow_ghost);

        Position pos_yellow_ghost_up = {pos_yellow_ghost.x,
                                        pos_yellow_ghost.y - 1};
        Position pos_yellow_ghost_down = {pos_yellow_ghost.x,
                                          pos_yellow_ghost.y + 1};
        Position pos_yellow_ghost_left = {pos_yellow_ghost.x - 1,
                                          pos_yellow_ghost.y};
        Position pos_yellow_ghost_right = {pos_yellow_ghost.x + 1,
                                           pos_yellow_ghost.y};

        if (distance(pos_pacman, pos_yellow_ghost_up) <= curr_dist
            && !is_ghost_collision(pos_yellow_ghost_up)) {
            pos_yellow_ghost.x = pos_yellow_ghost_up.x;
            pos_yellow_ghost.y = pos_yellow_ghost_up.y;

        } else if (distance(pos_pacman, pos_yellow_ghost_down) <=
            curr_dist && !is_ghost_collision(pos_yellow_ghost_down)) {
            pos_yellow_ghost.x = pos_yellow_ghost_down.x;
            pos_yellow_ghost.y = pos_yellow_ghost_down.y;

        } else if (distance(pos_pacman, pos_yellow_ghost_left) <=
            curr_dist && !is_ghost_collision(pos_yellow_ghost_left)) {
            pos_yellow_ghost.x = pos_yellow_ghost_left.x;
            pos_yellow_ghost.y = pos_yellow_ghost_left.y;

        } else if (distance(pos_pacman, pos_yellow_ghost_right) <=
            curr_dist && !is_ghost_collision(pos_yellow_ghost_right)) {
            pos_yellow_ghost.x = pos_yellow_ghost_right.x;
            pos_yellow_ghost.y = pos_yellow_ghost_right.y;
        }

    } else {
        int curr_dist = distance(pos_pacman, pos_yellow_ghost);

        Position pos_yellow_ghost_up = {pos_yellow_ghost.x,
                                        pos_yellow_ghost.y - 1};
        Position pos_yellow_ghost_down = {pos_yellow_ghost.x,
                                          pos_yellow_ghost.y + 1};
        Position pos_yellow_ghost_left = {pos_yellow_ghost.x - 1,
                                          pos_yellow_ghost.y};
        Position pos_yellow_ghost_right = {pos_yellow_ghost.x + 1,
                                           pos_yellow_ghost.y};

        if (distance(pos_pacman, pos_yellow_ghost_up) >= curr_dist
            && !is_ghost_collision(pos_yellow_ghost_up)) {
            pos_yellow_ghost.x = pos_yellow_ghost_up.x;
            pos_yellow_ghost.y = pos_yellow_ghost_up.y;

        } else if (distance(pos_pacman, pos_yellow_ghost_down) >=
            curr_dist && !is_ghost_collision(pos_yellow_ghost_down)) {
            pos_yellow_ghost.x = pos_yellow_ghost_down.x;
            pos_yellow_ghost.y = pos_yellow_ghost_down.y;

        } else if (distance(pos_pacman, pos_yellow_ghost_left) >=
            curr_dist && !is_ghost_collision(pos_yellow_ghost_left)) {
            pos_yellow_ghost.x = pos_yellow_ghost_left.x;
            pos_yellow_ghost.y = pos_yellow_ghost_left.y;

        } else if (distance(pos_pacman, pos_yellow_ghost_right) >=
            curr_dist && !is_ghost_collision(pos_yellow_ghost_right)) {
            pos_yellow_ghost.x = pos_yellow_ghost_right.x;
            pos_yellow_ghost.y = pos_yellow_ghost_right.y;
        }
    }
}

bool
Model::is_collision(Position pos_player)
{
    if (pos_player.x > 27 || pos_player.x < 0) {
        return false;

    } else if (layout[pos_player.x][pos_player.y] == 1) {
        return true;

    } else if (layout[pos_player.x][pos_player.y] == 2) {
        layout[pos_player.x][pos_player.y] = 0;
        points = points + 10;
        dots -= 1;
        return false;

    } else if (layout[pos_player.x][pos_player.y] == 3) {
        layout[pos_player.x][pos_player.y] = 0;
        points = points + 50;
        is_big_dot_eaten = true;
        big_dots -= 1;
        return false;

    } else {
        return false;
    }
}

bool
Model::is_ghost_collision(Position pos_player)
{
    // if (pos_player.x > 27) {
    //     pos_player.x = 0;
    //     return false;
    //
    // } else if (pos_player.x < 0) {
    //     pos_player.x = 27;
    //     return false;

    if (pos_player.x > 27 || pos_player.x < 0) {
        return false;

    } else if (layout[pos_player.x][pos_player.y] == 1) {
        return true;

    } else {
        return false;
    }
}

bool
Model::pacman_ghost_collision()
{
    if (!is_big_dot_eaten) {

        if (pos_pacman.x == pos_red_ghost.x
        && pos_pacman.y == pos_red_ghost.y) {
            return true;
        }

        if (pos_pacman.x == pos_yellow_ghost.x
        && pos_pacman.y == pos_yellow_ghost.y) {
            return true;
        }

        if (pos_pacman.x == pos_blue_ghost.x
        && pos_pacman.y == pos_blue_ghost.y) {
            return true;
        }

        if (pos_pacman.x == pos_pink_ghost.x
        && pos_pacman.y == pos_pink_ghost.y) {
            return true;
        }

        return false;

    } else if (is_big_dot_eaten) {

        if (pos_pacman.x == pos_red_ghost.x
            && pos_pacman.y == pos_red_ghost.y) {
            points += 100;
            pos_red_ghost = {13, 14};
            // is_red_in_pos = true;
            // red_time_elapsed = 0.0;
            is_red_ghost_moving = false;
            return false;
        }

        if (pos_pacman.x == pos_yellow_ghost.x
            && pos_pacman.y == pos_yellow_ghost.y) {
            points += 100;
            pos_yellow_ghost = {int(11.5), 17};
            is_yellow_in_cage = true;
            yellow_time_elapsed = 0.0;
            is_yellow_ghost_moving = false;
            return false;
        }

        if (pos_pacman.x == pos_blue_ghost.x
            && pos_pacman.y == pos_blue_ghost.y) {
            points += 100;
            pos_blue_ghost = {13, 17};
            is_blue_in_cage = true;
            blue_time_elapsed = 0.0;
            is_blue_ghost_moving = false;
            return false;
        }

        if (pos_pacman.x == pos_pink_ghost.x
            && pos_pacman.y == pos_pink_ghost.y) {
            points += 100;
            pos_pink_ghost = {int(15.5), 17};
            is_pink_in_cage = true;
            pink_time_elapsed = 0.0;
            is_pink_ghost_moving = false;
            return false;
        }
    }

    return false;
}

void
Model::kill_pacman()
{
    if (lives > 0) {
        lives -= 1;
        pos_pacman = {2, 14};

    } else {
        pos_pacman = { 2, 14};
        is_game_over = true;
    }
}

void
Model::revive()
{
    pos_pacman = {13, 26};
}

void
Model::on_frame(double dt)
{
    blue_time_elapsed += dt;
    red_time_elapsed += dt;
    yellow_time_elapsed += dt;
    pink_time_elapsed += dt;

    if (pacman_ghost_collision()) {
        kill_pacman();
    }

    is_win();

    ///
    /// Blue Ghost Movement
    ///

    // in cage
    if (is_blue_in_cage && blue_time_elapsed >= 5.0) {
        pos_blue_ghost = {13, 14};
        is_blue_in_cage = false;
        is_blue_ghost_moving = true;
    }

    // in maze
    if (is_blue_ghost_moving) {

        frame_count += dt;

        if (frame_count >= 0.25) {
            move_blue_ghost();
            frame_count = 0;
        }
    }

    ///
    /// Red Ghost Movement
    ///

    // // in pos
    // if (is_red_in_pos && red_time_elapsed >= 2.0) {
    //     pos_red_ghost = {13, 14};
    //     is_red_in_pos = false;
    //     is_red_ghost_moving = true;
    // }

    // if (red_time_elapsed >= 2.0) {
    //     is_red_ghost_moving = true;
    // }

    // in maze
    if (is_red_ghost_moving) {

        frame_count += dt;

        if (frame_count >= 0.244) {
            pos_red_ghost.x = red_ghost_desired_x;
            pos_red_ghost.y = red_ghost_desired_y;
            frame_count = 0;
        }

        if (pos_red_ghost.y == red_ghost_desired_y
            && pos_red_ghost.x == red_ghost_desired_x) {
            is_red_ghost_moving = false;
        }

    } else {
        move_red_ghost();
    }

    ///
    /// Pink Ghost Movement
    ///

    // in cage
    if (is_pink_in_cage && pink_time_elapsed >= 10) {
        pos_pink_ghost = {13, 14};
        is_pink_in_cage = false;
        is_pink_ghost_moving = true;
    }

    // in maze
    if (is_pink_ghost_moving) {

        frame_count += dt;

        if (frame_count >= 0.25) {
            move_pink_ghost();
            frame_count = 0;
        }
    }

    ///
    /// Yellow Ghost Movement
    ///

    // in cage
    if (is_yellow_in_cage && yellow_time_elapsed >= 15) {
        pos_yellow_ghost = {13, 14};
        is_yellow_in_cage = false;
        is_yellow_ghost_moving = true;
    }

    // in maze
    if (is_yellow_ghost_moving) {

        frame_count += dt;

        if (frame_count >= 0.25) {
            move_yellow_ghost();
            frame_count = 0;
        }
    }

    ///
    /// Edible State
    ///

    if (is_big_dot_eaten) {
        total_time_elapsed += dt;

        if (total_time_elapsed >= 10.0) {
            is_big_dot_eaten = false;
            total_time_elapsed = 0.0;
        }
    }
}
