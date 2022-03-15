#include "view.hxx"
#include "model.hxx"

// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

///
/// Audio Files
///

// File in Resources/ to read background music from. (Might not exist.)
static std::string const bg_music_filename {"bg_music.mp3"};
static std::string const pacman_chomp_filename {"pacman_chomp.wav"};
static std::string const pacman_beginning_filename {"pacman_beginning.wav"};

///
/// Constructor
///

View::View(Model const& model, Game_config const& config, ge211::Mixer& mixer)
        : model_(model),
          config_(config),
          mixer_(mixer),

          wall_sprite({16, 16},
                      Color(25, 25, 166)),
          gate_sprite({16, 16}, Color::white()),
          nothing_sprite({32, 32}, Color::black()),

          dot_sprite(2, Color::white()),
          big_dot_sprite(8, Color::white()),

          pacman_sprite(8, Color::medium_yellow()),
          red_ghost_sprite(8, Color::medium_red()),
          red_ghost_left_sprite("red_ghost_left.png"),
          red_ghost_right_sprite("red_ghost_right.png"),

          blue_ghost_sprite(8, Color(0, 0, 203)),
          blue_ghost_right_sprite("blue_ghost_right.png"),

          yellow_ghost_sprite(8, Color(255, 174, 66)),
          yellow_ghost_right_sprite("yellow_ghost_right.png"),

          pink_ghost_sprite(8, Color(255, 192, 203)),
          pink_ghost_left_sprite("pink_ghost_left.png"),
          pink_ghost_right_sprite("pink_ghost_right.png"),

          edible_ghost_sprite("edible_ghost.png"),

          pacman_left_sprite("pacman_left.png"),
          // pacman_right_sprite("pacman_right.png"),
          // pacman_up_sprite("pacman_up.png"),
          // pacman_down_sprite("pacman_down.png"),

          cherry_sprite("cherry.png"),
          background_sprite("background.jpg")
{
    if (mixer_.is_enabled()) {

        load_audio_();
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    return config_.scene_dims;
}

void
View::draw(ge211::Sprite_set& set, std::string const& title, int points,
           std::string const& player, std::string const& you_win, std::string
           const& game_over, std::string const& ready)
{
    ///
    /// Text Sprite
    ///

    // title text sprite
    ge211::Text_sprite::Builder title_builder(emu16);
    title_builder.color(Color::white()) << title;
    title_sprite.reconfigure(title_builder);
    set.add_sprite(title_sprite,{model_.POS_TITLE.x * 16 + 6,
                                model_.POS_TITLE.y * 16}, 3);

    // points text sprite
    ge211::Text_sprite::Builder points_builder(emu16);
    points_builder.color(Color::white()) << points;
    points_sprite.reconfigure(points_builder);
    set.add_sprite(points_sprite,{model_.POS_POINTS.x * 16,
                                  model_.POS_POINTS.y * 16}, 3);

    // 1up text sprite
    ge211::Text_sprite::Builder player_builder(emu16);
    player_builder.color(Color::white()) << player;
    player_sprite.reconfigure(player_builder);
    set.add_sprite(player_sprite,{model_.POS_PLAYER.x * 16,
                                 model_.POS_PLAYER.y * 16}, 3);

    // ready text sprite
    if (model_.points == 0) {
        ge211::Text_sprite::Builder ready_builder(emu16);
        ready_builder.color(Color(255, 255, 0)) << ready;
        ready_sprite.reconfigure(ready_builder);
        set.add_sprite(ready_sprite,
                       {model_.POS_READY.x * 16,
                        model_.POS_READY.y * 16 - 2}, 4);
    }

    ///
    /// Background
    ///

    // creating walls and points in array
    for (int i = 0; i < 28; i++) {

        for (int j = 0; j <36; j++) {

            if (model_.layout[i][j] == 1) {
                set.add_sprite(wall_sprite,
                               {i * 16, j * 16}, 0);

            } else if (model_.layout[i][j] == 2) {
                set.add_sprite(dot_sprite,
                               {i * 16 + 6, j * 16 + 6}, 2);

            } else if (model_.layout[i][j] == 3) {
                set.add_sprite(big_dot_sprite,
                               {i * 16, j * 16}, 2);
            }
        }
    }

    // decoration
    set.add_sprite(cherry_sprite, {24 * 16, 34 * 16}, 3);

    // set.add_sprite(gate_sprite, {13 * 16, 15 * 16}, 1);
    // set.add_sprite(gate_sprite, {14 * 16, 15 * 16}, 1);

    // background image
    set.add_sprite(background_sprite, {0 * 16, 0 * 16}, 1);

    set.add_sprite(nothing_sprite,{2 * 16, 13 * 16}, 4);
    set.add_sprite(nothing_sprite,{2 * 16, 14 * 16}, 4);
    set.add_sprite(nothing_sprite,{1 * 16, 13 * 16}, 4);
    set.add_sprite(nothing_sprite,{1 * 16, 14 * 16}, 4);

    ///
    /// Pacman Animation
    ///

    // set.add_sprite(pacman_sprite,
    //                {int(model_.pos_pacman.x * 16),
    //                 model_.pos_pacman.y * 16},3);

    if (!model_.is_game_over) {
        set.add_sprite(pacman_left_sprite, {
                int(model_.pos_pacman.x * 16 - 8),
                model_.pos_pacman.y * 16 - 8}, 3,
                       model_.DIRECTION);
    }

    ///
    /// Red Ghost Animation
    ///

    // set.add_sprite(red_ghost_sprite,
    //                {int(model_.pos_red_ghost.x * 16),
    //                 model_.pos_red_ghost.y * 16},3);

    set.add_sprite(red_ghost_right_sprite,
                   {int(model_.pos_red_ghost.x * 16 - 8),
                    model_.pos_red_ghost.y * 16 - 8},3);

    ///
    /// Blue Ghost Animation
    ///

    // set.add_sprite(blue_ghost_sprite,
    //                {int(model_.pos_blue_ghost.x * 16),
    //                 model_.pos_blue_ghost.y * 16},3);

    set.add_sprite(blue_ghost_right_sprite,
                   {int(model_.pos_blue_ghost.x * 16 - 8),
                    model_.pos_blue_ghost.y * 16 - 8},3);

    ///
    /// Yellow Ghost Animation
    ///

    // set.add_sprite(yellow_ghost_sprite,
    //                {int(model_.pos_yellow_ghost.x * 16),
    //                 model_.pos_yellow_ghost.y * 16},3);

    set.add_sprite(yellow_ghost_right_sprite,
                   {model_.pos_yellow_ghost.x * 16 - 8,
                    model_.pos_yellow_ghost.y * 16 - 8},3);

    ///
    /// Pink Ghost Animation
    ///

    // set.add_sprite(pink_ghost_sprite,
    //                {int(model_.pos_pink_ghost.x * 16),
    //                 model_.pos_pink_ghost.y * 16},3);

    set.add_sprite(pink_ghost_right_sprite,
                   {int(model_.pos_pink_ghost.x * 16 - 8),
                    model_.pos_pink_ghost.y * 16 - 8},3);

    ///
    /// Edible Ghost Animation
    ///

    if (model_.is_big_dot_eaten) {
        set.add_sprite(edible_ghost_sprite,
                       {int(model_.pos_pink_ghost.x * 16 - 8),
                        model_.pos_pink_ghost.y * 16 - 8},4);

        set.add_sprite(edible_ghost_sprite,
                       {int(model_.pos_red_ghost.x * 16 - 8),
                        model_.pos_red_ghost.y * 16 - 8},4);

        set.add_sprite(edible_ghost_sprite,
                       {int(model_.pos_blue_ghost.x * 16 - 8),
                        model_.pos_blue_ghost.y * 16 - 8},4);

        set.add_sprite(edible_ghost_sprite,
                       {int(model_.pos_yellow_ghost.x * 16 - 8),
                        model_.pos_yellow_ghost.y * 16 - 8},4);
    }

    ///
    /// Pacman Lives
    ///

    // display number of total lives
    set.add_sprite(pacman_left_sprite, {0 * 16, 34 * 16}, 3);
    set.add_sprite(pacman_left_sprite, {2 * 16, 34 * 16}, 3);
    // set.add_sprite(pacman_life_sprite, {4 * 16, 34 * 16}, 3);

    // change display of lives
    if (model_.lives == 2) {
        set.add_sprite(nothing_sprite,{2 * 16, 34 * 16}, 4);
        }

    if (model_.lives == 1) {
        set.add_sprite(nothing_sprite,{2 * 16, 34 * 16}, 4);
        set.add_sprite(nothing_sprite,{0 * 16, 34 * 16}, 4);
        }

    if (model_.lives == 0) {
        // set.add_sprite(nothing_sprite,{4 * 16, 34 * 16}, 4);
        set.add_sprite(nothing_sprite,{2 * 16, 34 * 16}, 4);
        set.add_sprite(nothing_sprite,{0 * 16, 34 * 16}, 4);
    }

    // display winning and loosing
    if (model_.lives == 0) {

        if (model_.dots + model_.big_dots == 0) {
            ge211::Text_sprite::Builder you_win_builder(emu16);
            you_win_builder.color(Color::white()) << you_win;
            you_win_sprite.reconfigure(you_win_builder);
            set.add_sprite(you_win_sprite,
                           {model_.POS_YOU_WIN.x * 16,
                                           model_.POS_YOU_WIN.y * 16 - 2},
                                           5);

        } else {
            ge211::Text_sprite::Builder game_over_builder(emu16);
            game_over_builder.color
            (Color(255, 0, 0)) << game_over;
            game_over_sprite.reconfigure(game_over_builder);
            set.add_sprite(game_over_sprite,
                           {model_.POS_GAME_OVER.x * 16,
                                           model_.POS_GAME_OVER.y * 16 - 2},
                                           5);
        }

    } else if (model_.lives > 0 && model_.big_dots + model_.dots == 0) {
        ge211::Text_sprite::Builder you_win_builder(emu16);
        you_win_builder.color(Color::white()) << you_win;
        you_win_sprite.reconfigure(you_win_builder);
        set.add_sprite(you_win_sprite,
                       {model_.POS_YOU_WIN.x * 16,
                        model_.POS_YOU_WIN.y * 16 - 2}, 5);
    }
}

void
View::load_audio_()
{
    pacman_chomp_.try_load(pacman_chomp_filename, mixer_);
    pacman_beginning_.try_load(pacman_beginning_filename, mixer_);

    try {
        // To enable background music, put a file named bg_music.ogg
        // in the Resources/ directory.
        if (bg_music_.try_load(bg_music_filename, mixer_)) {
            mixer_.play_music(bg_music_, true);
            mixer_.set_music_volume(0.3);

        }
    } catch (ge211::Environment_error const& exn) {
        ge211::internal::logging::warn(exn.what())
                << "To enable background music, put a file named\n"
                << bg_music_filename << " in the Resources/ directory.";
    }
}

void
View::play_pacman_chomp() const
{
    mixer_.try_play_effect(pacman_chomp_);
}

void
View::play_pacman_beginning() const
{
    mixer_.try_play_effect(pacman_beginning_);
}


void
View::set_animating(bool active)
{
    // If the sound effect should stop, reset the handle so that we
    // won't repeat the it again.
    if (!active) {
        success_handle_ = {};
    }

    // If the sound effect hasn't been started yet or has finished,
    // (re)start it.
    else if (success_handle_.empty() ||
             success_handle_.get_state() == ge211::Mixer::State::detached) {
        success_handle_ = mixer_.try_play_effect(pacman_chomp_);
    }

        // If the sound effect is currently paused, resume it.
    else if (success_handle_.get_state() == ge211::Mixer::State::paused) {
        success_handle_.resume();
    }

    // Otherwise there is nothing to do.
}

void
View::resume_music_if_ended() const
{
    if (mixer_.get_music_state() == ge211::Mixer::State::paused) {
        mixer_.resume_music();
    }
}

