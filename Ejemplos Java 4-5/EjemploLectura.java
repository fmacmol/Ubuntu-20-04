import java.io.*;

/* Lee una cadena de la entrada estándar (System.in) y la visualiza */
public class EjemploLectura {
	public static void main(String[] args) {
		
		//Recoge la entrada estándar en un InputStream
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(in);
		String texto;
		
		//Imprime en pantalla
		try {
			System.out.println("Introduce una cadena.... ");
			texto = br.readLine();
			System.out.println("Cadena escrita: " + texto);
			in.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
