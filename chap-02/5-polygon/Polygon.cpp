#include "Polygon.h"

void Polygon::add_vertex(int a, int b) {
    // Vertex vertex(a, b);
    // _vertices.emplace_back(vertex);
    _vertices.emplace_back(a, b);
}

const Vertex& Polygon::get_vertex(int index) const {
    return _vertices[index];
}

std::ostream& operator<<(std::ostream& out, const Polygon& polygon) {
    for (const auto& elem : polygon._vertices) {
        out << "(" << elem.first << "," << elem.second << ") ";
    }
    return out;
}
