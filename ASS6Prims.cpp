 #include <iostream>
using namespace std;
class Graph
{
    int G[20][20];
    int
        vertices,
        edges;

public:
    Graph();
    void
    read();
    void
    print();
    void
    init();
    int
    prims(Graph &);
};
Graph::Graph()
{
    vertices = 0;
}
void Graph::init()
{
    int i, j;
    for (
        i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            G[i][j] = 0;
        }
    }
}
void Graph::read()
{
    int i, source, dest, weight;
    cout << "Enter Total Offices:- " << endl;
    cin >> vertices;
    init();
    cout << "Enter Total Phone Lines:- " << endl;
    cin >> edges;
    for (i = 0; i < edges; i++)
    {
        cout << "Enter Source and Destination with the Cost to connect them:- " << endl;
        cin >> source >> dest >> weight;
        G[source][dest] = G[dest][source] = weight;
    }
}
void Graph::print()
{
    int i, j;
    for (
        i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            if (G[i][j] != 0)
            {
                cout << i << " -> " << j << " = " << G[i][j] << " Rs. " << endl;
            }
        }
    }
}
int Graph::prims(Graph &g)
{
    int cost[20][20], distance[20], from[20], visited[20];
    int minimum_cost, minimum_distance, i, j, a, b, edge_no;
    g.vertices = vertices;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = 9999;
            }
            else
            {
                cost[i][j] =
                    G[i][j];
            }
            g.G[i][j] = 0;
        }
    }
    distance[0] = 0;
    visited[0] = 1;
    for (i = 1; i < vertices; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    minimum_cost = 0;
    edge_no = 0;
    while (edge_no <
           vertices - 1)
    {
        minimum_distance = 9999;
        for (i = 1; i < vertices; i++)
        {
            if (visited[i] == 0 && distance[i] < minimum_distance)
            {
                minimum_distance = distance[i];
                b = i;
            }
        }
        a =
            from[b];
        g.G[a][b] = g.G[b][a] = distance[b];
        minimum_cost = minimum_cost + cost[a][b];
        visited[b] = 1;
        for (i = 1; i < vertices; i++)
        {
            if (visited[i] == 0 && cost[i][b] < distance[i])
            {
                distance[i] = cost[i][b];
                from[i] = b;
            }
        }
        edge_no++;
    }
    return minimum_cost;
}
int main()
{
    Graph
        g,
        h;
    int
        choice,
        cost;
    do
    {
        cout << "\n1)Insert Landmarks\n2)Display Graph\n3)Shortest path\n4)Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.read();
            break;
        case 2:
            g.print();
            break;
        case 3:
            cost = g.prims(h);
            cout << "Minimum Cost to connect all the offices is: " << cost << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
