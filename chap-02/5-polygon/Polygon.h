#pragma once

#include <ostream>
#include <utility>
#include <vector>

using Vertex = std::pair<int, int>;

class Polygon {
private:
    std::vector<Vertex> _vertices;

public:
    void          add_vertex(int a, int b);
    const Vertex& get_vertex(int index) const;

    friend std::ostream& operator<<(std::ostream& out, const Polygon& polygon);
};
