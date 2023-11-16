import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Por favor, forneça o nome do arquivo como argumento.");
            return;
        }

        try {
            FileReader fileReader = new FileReader(args[0]);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            List<Processos> processos = new ArrayList<>();
            String linha;
            Scanner sc = new Scanner(System.in);

            while ((linha = bufferedReader.readLine()) != null) {
                String[] partes = linha.split(" ", 2);

                if (partes.length >= 2) {
                    String nome = partes[0];
                    int time = Integer.parseInt(partes[1]);
                    processos.add(new Processos(nome, time));
                } else {
                    System.out.println("Formato inválido na linha: " + linha);
                }
            }
            Processador processador5 = new Processador("Processador 5");
            Processador processador6 = new Processador("Processador 6");
            for (Processos proc : processos) {
                if (processador5.getTempoTotal() <= processador6.getTempoTotal()) {
                    processador5.executarProcesso(proc);
                } else {
                    processador6.executarProcesso(proc);
                }
            }

            Processador processador1 = new Processador("Processador 1");
            Processador processador2 = new Processador("Processador 2");
            Collections.sort(processos);
            for (Processos proc : processos) {
                if (processador1.getTempoTotal() <= processador2.getTempoTotal()) {
                    processador1.executarProcesso(proc);
                } else {
                    processador2.executarProcesso(proc);
                }
            }

            Processador processador3 = new Processador("Processador 3");
            Processador processador4 = new Processador("Processador 4");

            Collections.sort(processos, Collections.reverseOrder());
            for (Processos proc : processos) {
                if (processador3.getTempoTotal() <= processador4.getTempoTotal()) {
                    processador3.executarProcesso(proc);
                } else {
                    processador4.executarProcesso(proc);
                }
            }
            System.out.println("Deseja gerar arquivo de saída? (s/n)");
            String resposta = sc.nextLine().trim().toLowerCase();
            boolean test = resposta.equals("s");
            if (test) {
                BufferedWriter writer = new BufferedWriter(new FileWriter("saida.txt"));
                writer.write("Processos ordenados menor ao maior:\n\n");
                writer.write("Processador_1: \n" + processador1 + "\nProcessador_2: \n" + processador2);
                writer.write("Processos ordenados maior ao menor:\n\n");
                writer.write("Processador_3: \n" + processador3 + "\nProcessador_4: \n" + processador4);
                writer.write("Processos sem Ordenação: \n\n");
                writer.write("Processador_5: \n" + processador5 + "\nProcessador_6: \n" + processador6);
                writer.close();
            }
            else {
                System.out.println("Processos ordenados menor ao maior:\n");
                System.out.println("Processador_1: \n" + processador1);
                System.out.println("Processador_2: \n" + processador2);
                System.out.println("Processos ordenados maior ao menor:\n");
                System.out.println("Processador_3: \n" + processador3);
                System.out.println("Processador_4: \n" + processador4);
                System.out.println("Processos sem Ordenação:\n");
                System.out.println("Processador_5: \n" + processador5);
                System.out.println("Processador_6: \n" + processador6);
            }
            bufferedReader.close();
            sc.close();
        } catch (IOException e) {
            System.out.println("Ocorreu um erro ao ler o arquivo: " + e.getMessage());
        }
    }
}
