import java.io.*;
public class Ejemplo5 {    
   public static void main(String[] args)  {
      Runtime r = Runtime.getRuntime();    
      String comando="java EjemploLectura";
	Process p=null;
 	try{	 
	   p = r.exec(comando);
	   
       OutputStream os = p.getOutputStream();
       os.write("Hola Manuel\n".getBytes());
	   os.flush(); //vacía el buffer de salida
	 
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