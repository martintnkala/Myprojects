package Networking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.channels.ServerSocketChannel;
import java.util.Scanner;

public class Networking {
    public static void main(String[] args){
        /* I created the Server Socket with a port number.
        * This is the SERVER HOST side that I am working on. I will need the SERVER HOST and the CLIENT HOST
        * inorder for the connection to be established.
        * */
        try(ServerSocket serverSocket = new ServerSocket(5000)){

            // Created a Socket to connect to the client.
            Socket socket = serverSocket.accept();
            Socket socket1 = new Socket("https://www.byui.edu/", 5000);
            System.out.println("Client connected");
//            BufferedReader input = new BufferedReader(
//                    new InputStreamReader(socket.getInputStream()));
//            PrintWriter output = new PrintWriter(socket.getOutputStream());

        } catch (IOException e){
            e.printStackTrace();
        }
    }

}
