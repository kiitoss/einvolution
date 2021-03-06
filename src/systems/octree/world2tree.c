#include "../../../inc/systems/octree/world2tree.h"
#include "../../../inc/entities/world/world.h"


/**
 * @brief generate recursively the world tree
 * 
 * @param w : the world
 * @param leaves : the leaves
 * @param x1 : the coords x of the first position of the cube 
 * @param y1 : the coords y of the first position of the cube
 * @param z1 : the coords z of the first position of the cube
 * @param x2 : the coords x of the second position of the cube
 * @param y2 : the coords y of the second position of the cube
 * @param z2 : the coords z of the second position of the cube
 * @param edge_size : the size of the cube edge
 * @return octree 
 */
static octree generate_world_tree_bis(world w, tree_leaves *leaves, float x1, float y1, float z1, float x2, float y2, float z2, float edge_size) {
    // create the curent cube
    cube c = create_cube(set_position(x1, y1, z1), set_position(x2, y2, z2), edge_size);
    
    // get the number of object in the current cube
    int number = get_number_object(w.object, c);

    // if the density is not full create a cube 
    if (number <= OBJECT_DENSITY && number > 0) {
        // save the current node
        construct_tree_leaves(leaves, w.object, c);

        return construct_octree(FULL, c, empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree());
    }

    // cube is empty
    if (!number) 
        return construct_octree(EMPTY, c, empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree());
   
    // split the current cube in 8 childs cube
    return construct_octree(UNDETERMINATE, c,
        generate_world_tree_bis(w, leaves, x1, y1, z1, (x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, leaves, (x1 + x2) / 2, y1, z1, x2, (y1 + y2) / 2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, leaves, (x1 + x2) / 2, (y1 + y2) / 2, z1, x2, y2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, leaves, x1, (y1 + y2) / 2, z1, (x1 + x2) / 2, y2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, leaves, x1, y1, (z1 + z2) / 2, (x1 + x2) / 2, (y1 + y2) / 2, z2, edge_size/2),
        generate_world_tree_bis(w, leaves, (x1 + x2) / 2, y1, (z1 + z2) / 2, x2, (y1 + y2) / 2, z2, edge_size/2),
        generate_world_tree_bis(w, leaves, (x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2, x2, y2, z2, edge_size/2),
        generate_world_tree_bis(w, leaves, x1, (y1 + y2) / 2, (z1 + z2) / 2, (x1 + x2) / 2, y2, z2, edge_size/2)
    );
}

/**
 * @brief generate the world tree
 *
 * @param c : the cube
 * @param obj : the world object
 * @param leaves : the leaves
 * @return octree 
 */
octree generate_world_tree(cube c, world_object obj, tree_leaves *leaves) {
    world w;

    w.cube = c; 
    w.object = obj;

    leaves->arr_world_object = (world_object *) malloc(MAX_OBJECT * sizeof(world_object));
    leaves->length = 0;


    return generate_world_tree_bis(w, leaves, w.cube.p1.x, w.cube.p1.y, w.cube.p1.z, w.cube.p2.x, w.cube.p2.y, w.cube.p2.z, w.cube.edge_size);
}

/**
 * @brief draw recursivly the octree 
 * 
 * @param A : the octree
 */
static void draw_world_tree_bis(octree A) {
  
    for (int i = 0; i < K; i++) {
        if (A->child[i] == NULL) return;

        octree child = A->child[i];
        if (child->val == FULL) draw_cube(child->cube);
        
        draw_world_tree_bis(child);
    }
}

/**
 * @brief draw the octree
 * 
 * @param k : the octree
 */
void draw_world_tree(octree k) { draw_world_tree_bis(k); }