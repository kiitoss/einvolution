#if !defined(PLAYER_VIEW)
#define PLAYER_VIEW

#include "../../entities/camera/frustum.h"
#include "../octree/tree_leaves.h"
#include "../shape/cube.h"
#include "./collision.h"

#define DISTANCE_DETECTION 25


void draw_field_view(position eye, frustum frust, tree_leaves leaves);

#endif // PLAYER_VIEW
