#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Audio/Sound.hpp>

void PlayerTakeDamage::TakeDamage(float& hp, float damage)
{
    hp -= damage;
    HealthBarManager::RemoveHeart(damage);


    if (hp <= 0)
    {
        Sound::PlayOnce("aaagh.wav", 0.2f);
        Sound::SetMusic("menu_theme_v2.wav", 0.2f);
        Sound::PlayMusic(true);
    }
    else 
        Sound::PlayOnce("ugh.wav", 0.2f);

}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}