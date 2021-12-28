#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int n, m; //n liczba wierzcholkow, m liczba krawedzi

class String
{
public:
    String(int32_t a, int32_t b, int64_t c) : source(a), destination(b), thickness(c) {}
    int32_t source;
    int32_t destination;
    int64_t thickness;
};

class Set
{
public:
    int32_t parent = -1;
    int32_t size = 0;
};

int32_t Find(std::vector<Set> &graph, int x)
{
    if (graph[x].parent == -1)
        return x;
    graph[x].parent = Find(graph, graph[x].parent);
    return graph[x].parent;
}

int64_t treeConstruct(const std::vector<String> &web, int n)
{
    int64_t maxCriticalEdge = INT64_MAX;
    std::vector<Set> graph(n + 1, std::move(Set()));
    for (const auto &string : web)
    {
        int x = Find(graph, string.source);
        int y = Find(graph, string.destination);

        if (x != y)
        {
            if (string.thickness < maxCriticalEdge)
            {
                maxCriticalEdge = string.thickness;
            }
            if (graph[x].size < graph[y].size)
            {
                std::swap(x, y);
            }
            graph[y].parent = x;
            graph[x].size += graph[y].size;
        }
    }
    return maxCriticalEdge;
}

int main()
{
    std::vector<String> web;
    int a, b, c;

    std::cin >> n;
    std::cin >> m;

    for (int i = 0; i < m; i++)
    {
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        web.push_back(String(a, b, c));
    }

    std::sort(web.begin(), web.end(), [](const auto &a, const auto &b)
              { return a.thickness > b.thickness; });

    std::cout << treeConstruct(web, n) << std::endl;
}