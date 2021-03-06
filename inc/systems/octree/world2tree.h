#if !defined(WORLD_2_TREE)
#define WORLD_2_TREE

#include "./octree.h"
#include "../../systems/object/world_object.h"


#define OBJECT_DENSITY 2 // define the density of object/cube


/**
 * @brief generate the world tree
 *
 * @param c : the cube
 * @param obj : the world object
 * @param leaves : the leaves
 * @return octree 
 */
octree generate_world_tree(cube c, world_object obj, tree_leaves *leaves);

/**
 * @brief draw the world tree
 * 
 * @param k : the octree
 */
void draw_world_tree(octree k);


#endif // WORLD_2_TREE