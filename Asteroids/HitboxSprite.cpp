#include "HitboxSprite.h"

void HitboxSprite::setHitbox(const sf::FloatRect& hitbox) 
{
    this->m_hitbox = hitbox;
}

sf::FloatRect HitboxSprite::getGlobalHitbox() const 
{
    return this->getTransform().transformRect(m_hitbox);
}
