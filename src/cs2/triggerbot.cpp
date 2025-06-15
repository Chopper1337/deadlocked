#include <chrono>
#include <random>

#include "cs2/cs2.hpp"
#include "cs2/features.hpp"
#include "math.hpp"
#include "mouse.hpp"

std::optional<std::chrono::steady_clock::time_point> next_shot = std::nullopt;
std::optional<std::chrono::steady_clock::time_point> mouse_left_down_time = std::nullopt;
bool previous_key_state = false;
bool toggled = false;
bool mouse_left_down = false;

i32 rng_delay(f32 min, f32 max)
{
    std::random_device dev;
    std::mt19937 rng {dev()};
    const f32 mean =
        static_cast<f32>(min + max) / 2.0f;
    std::normal_distribution normal {
        mean, static_cast<f32>(max - min) / 2.0f};

    return static_cast<i32>(normal(rng));
}

void Triggerbot() {
    if (!config.triggerbot.enabled) {
        return;
    }

    const auto now = std::chrono::steady_clock::now();
    const auto mouse_left_release_delay = std::chrono::milliseconds(rng_delay(config.triggerbot.hold_min, config.triggerbot.hold_max));

    if (mouse_left_down && mouse_left_down_time)
    {
        auto mouse_left_release_time = *mouse_left_down_time + mouse_left_release_delay;

        if (now > mouse_left_release_time)
        {
            MouseLeftRelease();
            mouse_left_down = false;
            mouse_left_down_time = std::nullopt;
        }
    }

    const bool key_state = IsButtonPressed(config.triggerbot.hotkey);
    if (config.triggerbot.toggle_mode) {
        // toggle mode
        if (key_state && !previous_key_state) {
            toggled = !toggled;
        }
        previous_key_state = key_state;
        misc_info.triggerbot_active = toggled;
    } else {
        // default mode, key has to be held
        misc_info.triggerbot_active = key_state;
    }

    if (!misc_info.triggerbot_active) {
        return;
    }

    if (next_shot) {
        const auto time = *next_shot;
        if (now > time) {
            MouseLeftPress();
            mouse_left_down = true;
            mouse_left_down_time = now;
            next_shot = std::nullopt;
        }
        return;
    }

    const std::optional<Player> local_player = Player::LocalPlayer();
    if (!local_player) {
        return;
    }

    if (config.triggerbot.flash_check && local_player->IsFlashed()) {
        return;
    }

    if (config.triggerbot.scope_check && local_player->GetWeaponClass() == WeaponClass::Sniper &&
        !local_player->IsScoped()) {
        return;
    }

    const std::optional<Player> crosshair_entity = local_player->EntityInCrosshair();
    if (!crosshair_entity) {
        return;
    }

    if (config.triggerbot.head_only) {
        const glm::vec3 enemy_head = target.player->BonePosition(Bones::Head);
        const glm::vec3 crosshair_pos = local_player->EyePosition();

        const glm::vec2 target_angle = TargetAngle(crosshair_pos, enemy_head, glm::vec2(0.0f));

        const glm::vec2 view_angles = local_player->ViewAngles();

        const f32 fov_distance = AnglesToFov(view_angles, target_angle);

        constexpr f32 head_radius_world = 3.5f;
        const f32 head_radius_fov = head_radius_world / target.distance * 100.0f;

        if (fov_distance > head_radius_fov) {
            return;
        }
    }

    if (!IsFfa() && crosshair_entity->Team() == local_player->Team()) {
        return;
    }

    next_shot = std::chrono::steady_clock::now() + std::chrono::milliseconds(rng_delay(config.triggerbot.delay_min, config.triggerbot.delay_max));
}

