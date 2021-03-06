#ifndef _GAME_H_
#define _GAME_H_

#include <stdlib.h>
#include <stdbool.h>

#include "user.h"
#include "enemy.h"

#define Dest(X) _Generic((X), \
    struct player *: user_dest, \
    struct enemy *: enemy_dest, \
    struct bullet *: bullet_dest \
)(X)

enum TAGS {
  USER,
  ENEMY
};

struct point {
  int x;
  int y;
};

struct game {
  struct player *user;
  struct player *second_user;
  struct enemy **aliens;
  unsigned int score;
};

struct game *game_init(void);
void free_game(struct game *);

#endif // _GAME_H_
