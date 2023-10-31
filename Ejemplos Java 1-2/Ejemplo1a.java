public class Ejemplo1a {
	public static void main(String[] args) {
		Runtime r = Runtime.getRuntime();
		String comando = "NOTEPAD";

		Process p;
		System.out.println("comando: "+comando);
		try {
			p = r.exec(comando);
		} catch (Exception e) {
			System.out.println("Error en: " + comando);
			e.printStackTrace();
		}
	}
}// Ejemplo1a
