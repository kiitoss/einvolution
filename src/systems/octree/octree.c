#include "../../../inc/systems/octree/octree.h"

static octree insert_child(octree A , octree fils);

/**
 * @brief construct the octree
 * 
 * @param e the root
 * @param c the cube
 * @param ... the childs
 * @return octree 
 */
octree construct_octree(element e, cube c, ...) {
    octree racine = create_node(e);
    
    va_list arg;
    va_start(arg, c);  

    if (e == FULL) racine->cube = c;

    for(int i = 1; i <= K; i++) {
        insert_child(racine, va_arg(arg, octree));
    }
        
    va_end(arg); 

    return racine;
}

/**
 * @brief check if the tree is empty
 * 
 * @param A 
 * @return int 
 */
static int is_tree_empty(octree A) { return (A == empty_tree()); }

/**
 * @brief Get the child by id
 * 
 * @param index 
 * @param A 
 * @return octree 
 */
static octree get_child_by_id(int index, octree A) { return A->fils[index]; }

/**
 * @brief insert child  
 * 
 * @param A 
 * @param fils 
 * @return octree 
 */
static octree insert_child(octree A , octree fils) {
    if(is_tree_empty(A)) return fils;
    else if(A->id >= K) {
        fprintf(stderr, "Error ! this node is full..\n --  %d --\n", get_tree_root(A));
        exit(EXIT_FAILURE);
    }

    A->fils[A->id++] = fils;
    
    return A;
}

/**
 * @brief return an empty tree 
 * 
 * @return octree 
 */
octree empty_tree() { return NULL; }

/**
 * @brief Get the tree root
 * 
 * @param A 
 * @return element 
 */
element get_tree_root(octree A) { return A->val; }

/**
 * @brief Create a node
 * 
 * @param e 
 * @return octree 
 */
octree create_node(element e) {
    octree A = (octree) malloc(sizeof(struct_node));

    A->id = 0;
    A->val = e;     
       
    for(int i = 0; i < K; i++)
        A->fils[i] = empty_tree();

    return A;
}

/**
 * @brief print the tree recursivly
 * 
 * @param A 
 * @param profondeur 
 */
static void print_tree_bis(octree A, int profondeur) {

    for (int i = 0; i < profondeur * PRINT_SPACE; i++) {
        fprintf(stdout, " ");
    }

    fprintf(stdout, "(%d)", get_tree_root(A));
    fprintf(stdout, "\n");

    for(int i = 0; i < K; i++){
        if(is_tree_empty(A->fils[i])) return;

        octree fils = get_child_by_id(i, A); 
        print_tree_bis(fils, profondeur + 1);
        
        fprintf(stdout, "\n");
    }
}

/**
 * @brief print the tree
 * 
 * @param A 
 */
void print_tree(octree A) { print_tree_bis(A, 0); }
