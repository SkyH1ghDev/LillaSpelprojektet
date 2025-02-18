#include "EnemyTakeDamage.hpp"

void EnemyTakeDamage::TakeDamage(float& hp, float damage)
{
    hp -= damage;
}

void EnemyTakeDamage::SetHealth(float& hp)
{
    hp = 100;
}