#ifndef WORLD_H
#define WORLD_H

#include "chunk.h"
#include "entity.h"
#include "input.h"

#define WORLD_SIZE 4

#define WORLD_TO_CHUNK(x) (x < 0 ? x % CHUNK_SIZE == 0 ? 0 : CHUNK_SIZE + x % CHUNK_SIZE : x % CHUNK_SIZE)
#define CHUNK_FROM_WORLD_COORDS(x) ((x / CHUNK_SIZE < 0 ? x + 1 : x) / CHUNK_SIZE + WORLD_SIZE / 2 - (x < 0 ? 1 : 0))

typedef struct
{
    chunk *chunks;

    float window_width;
    float window_height;

    entity player;
    vec3 camera_position;
    vec2 camera_rotation;
    int destroying_block;
    int placing_block;
    block_id selected_block;
    int selected_block_x;
    int selected_block_y;
    int selected_block_z;
    int selected_face_x;
    int selected_face_y;
    int selected_face_z;
    int block_in_range;

    block_vertex *chunk_data_buffer;

    mat4 blocks_model;
    mat4 world_view;
    mat4 world_projection;

    GLuint blocks_texture;
    GLuint blocks_program;
    GLuint blocks_position_location;
    GLuint blocks_normal_location;
    GLuint blocks_tex_coord_location;
    GLuint blocks_model_location;
    GLuint blocks_view_location;
    GLuint blocks_projection_location;

    GLuint lines_program;
    GLuint lines_position_location;
    GLuint lines_view_location;
    GLuint lines_projection_location;
    
    GLuint selection_box_vao;
    GLuint selection_box_buffer;
} world;

void world_init(world *w);
void world_handle_input(world *w, input *i);
void world_tick(world *w);
void world_draw(world *w, double delta_time);
void world_destroy(world *w);

block_id world_get_block(world *w, int x, int y, int z);
void world_set_block(world *w, int x, int y, int z, block_id new_block);

#endif