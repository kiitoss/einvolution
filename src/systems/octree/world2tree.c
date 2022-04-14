#include "../../../inc/systems/octree/world2tree.h"
#include "../../../inc/entities/world/world.h"

/**
 * @brief generate recursively the octree
 * 
 * @param w the world
 * @param x1 
 * @param y1 
 * @param z1 
 * @param x2 
 * @param y2 
 * @param z2 
 * @param edge_size 
 * @return octree 
 */
static octree generate_world_tree_bis(world w, float x1, float y1, float z1, float x2, float y2, float z2, float edge_size) {
    // create the curent cube
    cube c = create_cube(set_position(x1, y1, z1), set_position(x2, y2, z2), edge_size);
    
    // get the number of object in the current cube
    int number = get_number_object(w.object, c);
    world_object object;

    // if the density is not full create a cube 
    if (number <= OBJECT_DENSITY && number > 0) {
        object = get_object_in_cube(w.object, c);
        return construct_octree(FULL, object, c, empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree());
    }

    // cube is empty
    if (!number) 
        return construct_octree(EMPTY, object, c, empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree(), empty_tree());
   
    // split the cube in 8 childs cube
    return construct_octree(UNDETERMINATE, object, c,
        generate_world_tree_bis(w, x1, y1, z1, (x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, y1, z1, x2, (y1 + y2) / 2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, (y1 + y2) / 2, z1, x2, y2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, x1, (y1 + y2) / 2, z1, (x1 + x2) / 2, y2, (z1 + z2) / 2, edge_size/2),
        generate_world_tree_bis(w, x1, y1, (z1 + z2) / 2, (x1 + x2) / 2, (y1 + y2) / 2, z2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, y1, (z1 + z2) / 2, x2, (y1 + y2) / 2, z2, edge_size/2),
        generate_world_tree_bis(w, (x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2, x2, y2, z2, edge_size/2),
        generate_world_tree_bis(w, x1, (y1 + y2) / 2, (z1 + z2) / 2, (x1 + x2) / 2, y2, z2, edge_size/2)
    );
}

/**
 * @brief generate the word octree
 * 
 * @param c the world cube
 * @param obj the world objects
 * @return octree 
 */
octree generate_world_tree(cube c, world_object obj) {
    world w;

    w.cube = c; 
    w.object = obj;

    return generate_world_tree_bis(w, w.cube.p1.x, w.cube.p1.y, w.cube.p1.z, w.cube.p2.x, w.cube.p2.y, w.cube.p2.z, w.cube.edge_size);
}

/**
 * @brief draw recursivly the octree 
 * 
 * @param A 
 */
static void draw_world_tree_bis(octree A) {
  
    for (int i = 0; i < K; i++){
        if(A->child[i] == NULL) return;

        octree child = A->child[i];
        if(child->val == FULL) draw_cube(child->cube);
        
        draw_world_tree_bis(child);
    }
}

/**
 * @brief draw the octree
 * 
 * @param k 
 */
void draw_world_tree(octree k) { draw_world_tree_bis(k); }