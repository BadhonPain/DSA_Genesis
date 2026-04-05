package Graph_Overall_Java;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Welcome to Graph ~ All you need session !\n"
                + "Type 'list' to see the full list of commands & 'exit' for aborting.");
        Scanner sc = new Scanner(System.in);

        try {
            while (true) {
                String command = sc.nextLine();
                switch (command) {
                    case "list":
                        System.out.println("list -> See the full list of the commands");
                        System.out.println("custom -> Create custom graph");
                        System.out.println("print -> Prints the whole graph");
                        System.out.println("exit -> Abort the Program");
                        break;

                    case "custom":   
                        int v = sc.nextInt();
                        int e = sc.nextInt();
                        Graph graph = new Graph(v, e);
                        break;
                    case "exit":
                        System.exit(0);

                    
                    default:
                        System.out.println("Invalid command. Type 'list' to see the full list of the commands");
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        sc.close();
    }
}
