package com.socket;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;


public class SocketServer {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(8888);
            System.out.println("Start server ...");
            Socket s = ss.accept();
            System.out.println("client: " + s.getInetAddress().getLocalHost() + "already connected");

            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            String msg = br.readLine();
            System.out.println("Client: " + msg);
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));

            bw.write(msg + "\n");
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
