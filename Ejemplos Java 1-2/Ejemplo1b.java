public class Ejemplo1b {
	public static void main(String[] args)  {
     Runtime r = Runtime.getRuntime();
     String comando= "CMD /DIR" ;
	 
	 Process p;
	 try {
		p = r.exec( comando );
	 } catch (Exception e) {	 
	     System.out.println("Error en: "+comando );
	     e.printStackTrace();
	 }
	}
}//Ejemplo1b
