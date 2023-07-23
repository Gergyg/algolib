class DSU {
public:
    explicit DSU(const size_t& n) {
        parent.resize(n);
        size.resize(n, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    void makeSet(const int& vertex) {
        parent[vertex] = vertex;
        size[vertex] = 1;
    }

    int getRoot(int vertex) { // return root of the set, where vertex located;
        while (vertex != parent[vertex]) {
            vertex = (parent[vertex] = parent[parent[vertex]]);
        }
        return vertex;
    }

    void merge(int lhs, int rhs) { // groups 2 sets into one: prent of root rhs - lhs
        lhs = getRoot(lhs);
        rhs = getRoot(rhs);
        if (lhs != rhs) {
//                if (size[lhs] < size[rhs]) {
//                    std::swap(lhs, rhs);
//                }
            parent[rhs] = lhs;
            size[lhs] += size[rhs];
        }
    }

    size_t getSize(size_t vertex) {
        return size[getRoot(vertex)];
    }

private:
    std::vector<int> parent{};
    std::vector<size_t> size{};
};


