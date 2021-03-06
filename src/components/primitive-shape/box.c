#include "../../../inc/components/primitive-shape/box.h"


/**
 * @brief Create a box object
 * 
 * @param p : the position
 * @param width : the width
 * @param height : the height
 * @param depth : the depth
 * @return box 
 */
box create_box(position p, double width, double height, double depth) {

    box b; 
    b.pos = p;
    
    b.width = width;
    b.height = height;
    b.depth = depth;

    b.bb_primitive_shape = set_object_bounding_box(p, width, height, depth);
    b.is_primitive = 1;

    b.health = BOX_HEALTH;

    b.length = 6;
    b.arr_face = (face *) malloc(b.length * sizeof(face));
    
    // down side
    b.arr_face[0] = create_face(4,
        QUADS,
        set_color(0.3, 0.3, 1),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + width , get_y(p), get_z(p)),
        set_position(get_x(p) + width , get_y(p), get_z(p) + depth),
        set_position(get_x(p), get_y(p), get_z(p) + depth)
    );

    // front side
    b.arr_face[1] = create_face(4,
        QUADS,
        set_color(0.1, 0.1, 1),
        set_position(get_x(p), get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p) + height, get_z(p) + depth),
        set_position(get_x(p), get_y(p) + height, get_z(p) + depth)
    );
    
    // back side
    b.arr_face[2] = create_face(4,
        QUADS,
        set_color(0.8, 0.8, 1),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p) + width, get_y(p), get_z(p)),
        set_position(get_x(p) + width, get_y(p) + height, get_z(p)),
        set_position(get_x(p), get_y(p) + height, get_z(p))
    );

    // right side
    b.arr_face[3] = create_face(4,
        QUADS,
        set_color(0.5, 0.5, 1),
        set_position(get_x(p) + width, get_y(p), get_z(p)),
        set_position(get_x(p) + width, get_y(p), get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p) + height, get_z(p) + depth),
        set_position(get_x(p) + width, get_y(p) + height, get_z(p))
    );

    // left side
    b.arr_face[4] = create_face(4,
        QUADS,
        set_color(0.5, 0.5, 1),
        set_position(get_x(p), get_y(p), get_z(p)),
        set_position(get_x(p), get_y(p), get_z(p) + depth),
        set_position(get_x(p), get_y(p) + height, get_z(p) + depth),
        set_position(get_x(p), get_y(p) + height, get_z(p))
    );

    // up side
    b.arr_face[5] = create_face(4,
        QUADS,
        set_color(0.3, 0.3, 1),
        set_position(get_x(p), get_y(p) + height, get_z(p)),
        set_position(get_x(p) + width, get_y(p) + height, get_z(p)),
        set_position(get_x(p) + width, get_y(p) + height, get_z(p) + depth),
        set_position(get_x(p), get_y(p) + height, get_z(p) + depth)  
    );

    return b;
}