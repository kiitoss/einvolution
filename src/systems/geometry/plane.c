#include "../../../inc/systems/geometry/plane.h"


/**
 * @brief Create a plane object
 * 
 * @param p1 : the first position
 * @param p2 : the second position 
 * @param p3 : the third position 
 * @return plane 
 */
plane create_plane(position p1, position p2, position p3) {
    plane p;

    vector v, u;
    
    // find 2 vectors of the plane
	v = create_vector_from_positions(p1, p2);
	u = create_vector_from_positions(p2, p3);

    // calculate the normal vector
	p.normal = unit_vector(cross_product(u, v));

    // set the d value
	p.d = -(scalar_product(p.normal, p2));

    return p;
}

/**
 * @brief return the distance between the plane
 * and the position of u
 * 
 * @param p : the plane
 * @param u : the position
 * @return double 
 */
double distance_to_plane(plane p, vector u) {
	return (p.d + scalar_product(p.normal, u));
}

/**
 * @brief print the plane
 * 
 * @param p : the plane 
 */
void print_plane(plane p) {
    fprintf(stdout, "\n[ PRINT PLANE ]\n");
    
    fprintf(stdout, "-----------------------\n");
    fprintf(stdout, "normal : ");
    
    print_vector(p.normal);
    
    fprintf(stdout, "D: %f)\n", p.d);
    
    fprintf(stdout, "-----------------------\n\n");
}