#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model, Game_config const& config,
                  ge211::Mixer& mixer);

    void draw(ge211::Sprite_set& set, std::string const& title, int points,
              std::string const& player, std::string const& you_win,
              std::string const& game_over, std::string const& ready);

    /// View dimensions will use 'int' coordinates
    using Dimensions = ge211::Dims<int>;

    Dimensions initial_window_dimensions() const;

    ///
    /// Sound Effect
    ///

    // Tells the view whether animation is currently happening, so it
    // can play a sound effect during the animation.
    void set_animating(bool);

    void play_pacman_chomp() const;
    void play_pacman_beginning() const;

    // Keeps the music going.
    void resume_music_if_ended() const;


private:
    Model const& model_;
    Game_config const& config_;

    /// Text Font
    ge211::Font emu16{"emulogic.ttf", 16};

    ///
    /// Audio Effect
    ///
    // Loads the audio clips if possible. (Only called from the constructor.)
    void load_audio_();

    // For audio:
    ge211::Mixer& mixer_;
    ge211::Music_track bg_music_;
    ge211::Sound_effect pacman_chomp_;
    ge211::Sound_effect pacman_beginning_;
    ge211::Sound_effect_handle success_handle_;

    /// Text Sprite
    ge211::Text_sprite title_sprite;
    ge211::Text_sprite points_sprite;
    ge211::Text_sprite player_sprite;
    ge211::Text_sprite you_win_sprite;
    ge211::Text_sprite game_over_sprite;
    ge211::Text_sprite ready_sprite;

    /// Background Sprite
    ge211::Rectangle_sprite const wall_sprite;
    ge211::Rectangle_sprite const gate_sprite;
    ge211::Rectangle_sprite const nothing_sprite;

    /// Points Sprite
    ge211::Circle_sprite const dot_sprite;
    ge211::Circle_sprite const big_dot_sprite;

    ///
    /// Pacman and Ghost Sprites
    ///
    ge211::Circle_sprite const pacman_sprite;

    ge211::Circle_sprite const red_ghost_sprite;
    ge211::Image_sprite const red_ghost_left_sprite;
    ge211::Image_sprite const red_ghost_right_sprite;

    ge211::Circle_sprite const blue_ghost_sprite;
    ge211::Image_sprite const blue_ghost_right_sprite;

    ge211::Circle_sprite const yellow_ghost_sprite;
    ge211::Image_sprite const yellow_ghost_right_sprite;

    ge211::Circle_sprite const pink_ghost_sprite;
    ge211::Image_sprite const pink_ghost_left_sprite;
    ge211::Image_sprite const pink_ghost_right_sprite;

    ge211::Image_sprite const edible_ghost_sprite;

    ge211::Image_sprite const pacman_left_sprite;
    // ge211::Image_sprite const pacman_right_sprite;
    // ge211::Image_sprite const pacman_up_sprite;
    // ge211::Image_sprite const pacman_down_sprite;

    ge211::Image_sprite const cherry_sprite;
    ge211::Image_sprite const background_sprite;
};
