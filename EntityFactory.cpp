#include "EntityFactory.h"

EntityFactory::EntityFactory()
{

}

EntityFactory::~EntityFactory()
{

}

bool EntityFactory::init()
{
    if(!alienScoutImage.load("graphics/sprites/jellyfish.bmp", 196, 256))
    {
        return false;
    }

    if(!bossImage.load("graphics/sprites/boss.bmp"))
    {
        return false;
    }

    if(!bulletImage.load("graphics/sprites/bullets.bmp", 25, 25))
    {
        return false;
    }

    if(!checkpointImage.load("graphics/sprites/checkpoint.bmp"))
    {
        return false;
    }

    if(!explosionImage.load("graphics/sprites/explosion.bmp", 50, 50))
    {
        return false;
    }

    if(!explosionSmallImage.load("graphics/sprites/explosion_small.bmp", 24, 24))
    {
        return false;
    }

    if(!playerImage.load("graphics/sprites/diverR06.bmp", 256, 108 ))
    {
        return false;
    }

    if(!explosionSound.load("audio/sfx/explosion.wav"))
    {
        return false;
    }

    if(!bulletSound.load("audio/sfx/bullet.wav"))
    {
        return false;
    }

    if(!bossBulletImage.load("graphics/sprites/bossBullet.bmp", 25, 25)) {
        return false;
    }

    return true;
}

void EntityFactory::free()
{
    alienScoutImage.free();
    bossImage.free();
    bulletImage.free();
    explosionImage.free();
    explosionSmallImage.free();
    playerImage.free();
    explosionSound.free();
    bulletSound.free();
    bossBulletImage.free();
}

void EntityFactory::setCamera(Rectangle* c)
{
    camera = c;
}
void EntityFactory::setMap(Map* m)
{
    map = m;
}

SceneNode* EntityFactory::makeEntity(int e, int x, int y)
{
    switch(e)
    {
    case ENTITY_PLAYER:
        return new PlayerEntity(&playerImage, map, camera, x, y, this);
        break;
    case ENTITY_EXPLOSION:
        return new ExplosionEntity(&explosionImage, &explosionSound, x, y);
        break;
    case ENTITY_SILENT_EXPLOSION:
        return new ExplosionEntity(&explosionImage, NULL, x, y);
        break;
    case ENTITY_SMALL_EXPLOSION:
        return new ExplosionEntity(&explosionSmallImage, NULL, x, y);
        break;
    case ENTITY_PLAYER_BULLET:
        return new BulletEntity(&bulletImage, &bulletSound, map, camera, this, x, y, false);
        break;
    case ENTITY_ENEMY_BULLET:
        return new BulletEntity(&bulletImage, &bulletSound, map, camera, this, x, y, true);
        break;
    case ENTITY_ALIEN_SCOUT:
        return new AlienScoutEntity(&alienScoutImage, camera, this, x, y);
        break;
    case ENTITY_BOSS:
        return new BossEntity(&bossImage, camera, this, x, y);
        break;
    case ENTITY_CHECKPOINT:
        return new CheckpointEntity(&checkpointImage, x, y);
        break;
    case ENTITY_BOSS_BULLET:
        return new BulletEntity(&bossBulletImage, &bulletSound, map, camera, this, x, y, true);
        break;
    default:
        return NULL;
    }
}
