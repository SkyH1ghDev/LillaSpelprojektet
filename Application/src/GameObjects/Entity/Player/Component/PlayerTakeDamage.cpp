#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Audio/Sound.hpp>

void PlayerTakeDamage::TakeDamage(float& hp, float damage)
{
    hp -= damage;
    HealthBarManager::RemoveHeart(damage);


    if (hp <= 0)
        Sound::Play("aaagh.wav", 0.5f);
    else 
        Sound::Play("ugh.wav", 0.5f);

}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}