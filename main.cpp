#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cassert>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef float f32;
typedef double f64;

#define WIDTH 10
#define HEIGHT 22
#define VISIBLE_HEIGHT 20
#define GRID_SIZE 30

struct Tetrino
{
	const u8* data;
	const s32 side;
};

inline Tetrino
tetrino(const u8* data, s32 side)
{
	return { data, side };
}

const u8 TETRINO_1[] = {
	0,0,0,0,
	1,1,1,1,
	0,0,0,0,
	0,0,0,0
};

const u8 TETRINO_2[] = {
	2,2,
	2,2
};

const u8 TETRINO_3[] = {
	0,0,0,
	3,3,3,
	0,3,0
};

const u8 TETRINO_4[] = {
	0,4,4,
	4,4,0,
	0,0,0
};

const u8 TETRINO_5[] = {
	5,5,0,
	0,5,5,
	0,0,0
};

const u8 TETRINO_6[] = {
	6,0,0,
	6,6,6,
	0,0,0
};

const u8 TETRINO_7[] = {
	0,0,7,
	7,7,7,
	0,0,0
};

const Tetrino TETRINOS[] = {
	tetrino(TETRINO_1, 4),
	tetrino(TETRINO_2, 2),
	tetrino(TETRINO_3, 3),
	tetrino(TETRINO_4, 3),
	tetrino(TETRINO_5, 3),
	tetrino(TETRINO_6, 3),
	tetrino(TETRINO_7, 3)
};

enum Game_Phase
{
	GAME_PHASE_START,
	GAME_PHASE_PLAY,
	GAME_PHASE_LINE,
	GAME_PHASE_GAMEOVER
};

struct Piece_State
{
	u8 tetrino_index;
	s32 offset_row;
	s32 offset_col;
	s32 rotation;
};

struct Game_State
{
	u8 board[WIDTH * HEIGHT];
	u8 lines[HEIGHT];
	s32 pending_line_count;

	Piece_State piece;

	Game_Phase phase;

	s32 start_level;
	s32 level;
	s32 line_count;
	s32 points;

	f32 next_drop_time;
	f32 highlight_end_time;
	f32 time;

};

inline u8 matrix_get(const u8* values, s32 width, s32 row, s32 col)
{
	s32 index = row * width + col;
	return values[index];
}

void matrix_set(u8* values, s32 width, s32 row, s32 col, u8 value)
{
	s32 index = row * width + col;
	values[index] = value;
}

inline u8 tetrino_get(Tetrino* tetrino, s32 row, s32 col, s32 rotation)
{
	s32 side = tetrino->side;
	switch (rotation)
	{
	case 0:
		return tetrino->data[row * side + col];
	case 1:
		return tetrino->data[(side - col - 1) * side + row];
	case 2:
		return tetrino->data[(side - row - 1) * side + (side - col - 1)];
	case 3:
		return tetrino->data[col * side + (side - row - 1)];
	}
	return 0;
}

struct Input_State
{
	u8 left;
	u8 right;
	u8 up;
	u8 down;

	u8 a;

	s8 dleft;
	s8 dright;
	s8 dup;
	s8 ddown;
	s8 da;
};


int main()
{

}