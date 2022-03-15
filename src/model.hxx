#pragma once

#include <ge211.hxx>
#include "game_config.hxx"

class Model
{
public:

    using Position = ge211::Posn<int>;

    ///
    /// CONSTRUCTOR
    ///

    explicit Model(Game_config const& config);

    ///
    /// MEMBER VARIABLES
    ///

    // The configuration parameters of the model. See game_config.hxx for a
    // description of what this determines. Models can be constructed with
    // different configurations, but the configuration never changes on an
    // existing model.
    Game_config const& config;

    // 0 is empty
    // 1 is wall
    // 2 is dots
    // 3 is big dots
    // background array
    int layout[28][36];

    ///
    /// Starting Positions
    ///

    Position pos_pacman = {13, 26};

    Position pos_red_ghost = {13, 14};
    Position pos_blue_ghost = {13, 17};
    Position pos_yellow_ghost = {int(11.5), 17};
    Position pos_pink_ghost = {int(15.5), 17};

    float distance(Position pos_1, Position pos_2);

    ///
    /// Pacman Member Variables and Functions
    ///

    int lives = 3;
    bool is_big_dot_eaten = false;

    // pacman display
    ge211::Transform DIRECTION = ge211::Transform().set_rotation(0.0);

    void move_pacman(char dir);
    void kill_pacman();
    bool pacman_ghost_collision ();
    bool is_collision(Position pos_player);
    void revive();
    bool is_in_bound(Position pos_player);
    bool is_win();

    ///
    /// Ghost Member Variables and Functions
    ///

    void move_red_ghost();
    bool is_red_ghost_moving = false;
    int red_ghost_desired_x;
    int red_ghost_desired_y;

    void move_blue_ghost();
    bool is_blue_ghost_moving = false;

    void move_pink_ghost();
    bool is_pink_ghost_moving = false;

    void move_yellow_ghost();
    bool is_yellow_ghost_moving = false;

    bool is_game_over = false;

    bool is_ghost_collision(Position pos_player);

    bool is_pink_in_cage = true;
    bool is_yellow_in_cage = true;
    bool is_blue_in_cage = true;
    bool is_red_in_pos = true;

    ///
    /// Display
    ///

    int dots = 240;
    int big_dots = 4;
    int points = 0;
    Position POS_POINTS = {4, 1};

    std::string title = "HIGH SCORE";
    Position POS_TITLE = {9, 0};

    std::string player = "1UP";
    Position POS_PLAYER = {3, 0};

    std::string you_win = "YOU WIN!";
    Position POS_YOU_WIN = {10, 20};

    std::string game_over = "GAME  OVER";
    Position POS_GAME_OVER = {9, 20};

    std::string ready = "READY!";
    Position POS_READY = {11, 20};


    ///
    /// On Frame
    ///

    double frame_count = 0;
    void on_frame(double dt);
    double total_time_elapsed = 0.0;
    double blue_time_elapsed = 0.0;
    double red_time_elapsed = 0.0;
    double yellow_time_elapsed = 0.0;
    double pink_time_elapsed = 0.0;
};
