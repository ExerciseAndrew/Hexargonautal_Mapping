#include <stdio.h>
#include <assert.h>
#include <vector>

// Six even sides
/// 
 ///point 1: (X + (s/2), Y - a)
 ///point 2: (X + s, Y)
 ///point 3: (X + (s/2), Y + a)
 ///point 4: (X - (s/2), Y + a)
/// point 5: (X - s, Y)
/// point 6: (X - (s/2), Y - a)
///

struct Hex { // Vector storage, cube constructor
    const int v[3];
    Hex(int x, int y, int z): v{x, y, z} {
        assert (x + y + z == 0);
    }

    inline int x() {return v[0]; }
    inline int y() {return v[0]; }
    inline int z() {return v[0]; }
};

bool operator == (Hex a, Hex b) {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }

bool operator != (Hex a, Hex b) {
    return !(a == b);
}

Hex hex_add(Hex a, Hex b) {
    return Hex(a.x + b.x, a.y + b.y, a.z + b.z);
}

Hex hex_subtract(Hex a, Hex b) {
    return Hex(a.x - b.x, a.y - b.y, a.z - b.z);
}

Hex hex_multipy(Hex a, int k) {
    return Hex(a.x * k, a.y * k, a.z + k);
}

int hex_length(Hex hex) {
    return int ((abs(hex.x) + abs(hex.y) + abs (hex.z)))
};

int hex_distance(Hex a, Hex b) {
    return hex_length(hex_subtract(a,b))
} 

const std::vector<Hex> hex_directions = {
    Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
    Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1) 
}

Hex hex_direction(int direction /* 0 to 5*/) {
    assert (0 <= direction && direction < 6);
    return hex_directions[direction];
}

Hex hex_neighbor()