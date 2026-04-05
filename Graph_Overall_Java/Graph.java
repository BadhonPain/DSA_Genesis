package Graph_Overall_Java;

import java.util.ArrayList;
import java.util.Scanner;

class Edge {
    public int source;
    public int destination;

    public Edge(int u, int v) {
        source = u;
        destination = v;
        System.out.println("vertex 'u' and 'v' get connected !");
    }

};

public class Graph {

    Scanner sc = new Scanner(System.in);
    public ArrayList<Edge> graph[];

    public Graph(int vertexCount, int edgeCount) {
        graph = new ArrayList[vertexCount];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }
        for (int i = 0; i < edgeCount; i++) {
            System.out.println("Enter edges (u <==> v): ");
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(new Edge(u, v));
            graph[v].add(new Edge(v, u));
        }
    }

}
