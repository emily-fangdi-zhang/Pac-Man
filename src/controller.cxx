#include "controller.hxx"

Controller::Controller()
        : config_(),
          model_(config_),
          view_(model_, config_, mixer())
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set, model_.title, model_.points,
               model_.player, model_.you_win,
               model_.game_over, model_.ready);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

void
Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q')) {
        quit();

    } else if (key == ge211::Key::code(' ') && !model_.is_game_over) {
        model_.DIRECTION = ge211::Transform().set_rotation(0.0);

        if (model_.pos_pacman.x == 2 && model_.pos_pacman.y == 14) {

            if (model_.lives > 0) {
                model_.revive();
            }
        }

    } else if (key == ge211::Key::up()) {
        model_.DIRECTION = ge211::Transform().set_rotation(90.0);
        model_.move_pacman('u');

    } else if (key == ge211::Key::down()) {
        model_.DIRECTION = ge211::Transform().set_rotation(270.0);
        model_.move_pacman('d');

    } else if (key == ge211::Key::left()) {
        model_.DIRECTION = ge211::Transform().set_rotation(0.0);
        model_.move_pacman('l');

    } else if (key == ge211::Key::right()) {
        model_.DIRECTION = ge211::Transform().set_rotation(180.0);
        model_.move_pacman('r');
    }
}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
    // view_.set_animating(animating_);
    view_.resume_music_if_ended();
}

