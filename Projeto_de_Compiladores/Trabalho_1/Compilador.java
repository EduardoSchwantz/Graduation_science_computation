import java.util.Scanner;

class Compilador{

	public static void main(String[]args)
	{
		ArvoreSintatica arv=null;

		try{
			Scanner sc = new Scanner(System.in);
			AnaliseLexica al = new AnaliseLexica(args[0]);
			Parser as = new Parser(al);

			arv = as.parseProg();

			System.out.println("Para gerar Output.txt para Máquina de Pilha, Digite: s");
			System.out.println("Para Interpretar e não gerar output.txt, Digite: n");
			System.out.print("Digite: ");
			String resposta = sc.nextLine().trim().toLowerCase();
			boolean test = resposta.equals("s");
			if (test){
				CodeGen backend = new CodeGen();
				String codigo = backend.geraCodigo(arv);
				System.out.println(codigo);
				Output out = new Output(codigo);
				out.geraOutput();
			}
			else {
				Interpretador interpretador = new Interpretador();
				Float resultadoInterpretado = interpretador.interpreta(arv);
				System.out.println("Resultado do interpretador: " + resultadoInterpretado);
			}

		}catch(Exception e)
		{
			System.out.println("Erro de compilação:\n" + e);
		}



	}
}
