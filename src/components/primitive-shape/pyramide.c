#include "../../../inc/components/primitive-shape/pyramide.h"


/**
 * @brief Create a pyramide object
 * 
 * @param p : the position
 * @param width : the width
 * @param height : the height
 * @param depth : the depth
 * @return pyramide 
 */
pyramide create_pyramide(position p, double width, double height, double depth) {

    pyramide py;
    py.pos = p;

    py.bb_primitive_shape = set_object_bounding_box(p, width, height * 2, depth);
    py.is_primitive = 1;

    py.health = PYRAMIDE_HEALTH;

    py.length = 5;
    py.arr_face = (face *) malloc(py.length * sizeof(face));

    // down side
    py.arr_face[0] = create_face(4,
        QUADS,
        set_color(0.3, 1, 0.3),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + width , get_y(p), get_z(p)),
        set_position(get_x(p) + width , get_y(p), get_z(p) + depth),
        set_position(get_x(p), get_y(p), get_z(p) + depth)
    );

    // back side
    py.arr_face[1] = create_face(3,
        TRIANGLES,
        set_color(0.8, 1, 0.8),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + width, get_y(p), get_z(p)),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );

    // left side
    py.arr_face[2] = create_face(3,
        TRIANGLES,
        set_color(0.5, 1, 0.5),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p), get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );
    
    // front side 
    py.arr_face[3] = create_face(3,
        TRIANGLES,
        set_color(0.5, 1, 0.5),
        set_position(get_x(p), get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );

    // right side 
    py.arr_face[4] = create_face(3,
        TRIANGLES,
        set_color(0.3, 1, 0.3),
        set_position(get_x(p) + width, get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p), get_z(p)),
        set_position(get_x(p) + width/2, get_y(p) + 2 * height, get_z(p) + depth/2)
    );
   
    return py;
}