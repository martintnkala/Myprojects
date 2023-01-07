package Nkala;

import Nkala.Echoer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        /* I created the Server Socket with a port number.
         * This is the SERVER HOST side that I am working on. I will need the SERVER HOST and the CLIENT HOST
         * inorder for the connection to be established.
         * */
        try (ServerSocket serverSocket = new ServerSocket(5000)) {


            while(true){
                // kicking a new thread
                new Echoer(serverSocket.accept()).start();
//                Socket socket = serverSocket.accept();
//                Echoer echoer = new Echoer(socket);
//                echoer.start();

//                Created a Socket to connect to the client.
//                Socket socket = serverSocket.accept();
//                System.out.println("Client connected");
//                BufferedReader input = new BufferedReader(
//                        new InputStreamReader(socket.getInputStream()));
//                PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
//
//                String echoString  = input.readLine();
//                if(echoString.equals("exit")){
//                    break;
//                }
//                output.println("Echo from server: " + echoString);
            }

        } catch (IOException e) {
            System.out.println("Server exception: " + e.getMessage());
        }
    }
}
