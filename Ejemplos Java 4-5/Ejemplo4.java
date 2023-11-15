import java.io.*;

/* Este programa ejecuta DATE de Windows para modificar la fecha del
 * sistema.
 * 
 * Intercepta su entrada y su salida.
 */

public class Ejemplo4 {    
   public static void main(String[] args)  {
      Runtime r = Runtime.getRuntime();    
      String comando="CMD /C DATE";
	Process p=null;
 	try{	 
	   p = r.exec(comando);
	   
	   //Interceptamos la entrada a DATE con un OutputStream para escribir
       OutputStream os = p.getOutputStream();
       os.write("02/12/12\n".getBytes());
	   os.flush(); //vacía el buffer de salida
	 
	   //Interceptamos la salida de DATE con un InputStream para leerla
	  InputStream is = p.getInputStream();
       BufferedReader br = new BufferedReader
                (new InputStreamReader (is));               
       String linea;
       
       //Escribimos en pantalla
	   while((linea = br.readLine())!=null)
              System.out.println(linea);
	   br.close();
	 
       } catch (Exception e)  { e.printStackTrace(); }
		
	 // COMPROBACION DE ERROR - 0 bien 1 -mal
	 int exitVal;
	 try {
		exitVal = p.waitFor();
		System.out.println("Valor de Salida: " + exitVal);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} 
    }
}