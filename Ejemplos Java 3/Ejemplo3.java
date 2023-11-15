import java.io.*;

/* El programa Unsaludo toma la entrada desde la linea de comandos (un argumento)
 * y da la salida hacia la consola (println)
 */

/* Este programa intercepta la salida de Unsaludo.java
 * y da la salida a un fichero (indicado como argumento)
 */

public class Ejemplo3 {    
 public static void main(String[] args)  {
  Runtime r = Runtime.getRuntime();
  String comando= "java Unsaludo \"Hola_Mundo!!\" " ;  
  Process p=null;
  
  if (args.length < 1) {
     System.out.println("SE NECESITA UN NOMBRE DE FICHERO...");
     System.exit(1);
   }	
   
   try{
	 //fichero al que se enviará la salida de este programa
	 FileOutputStream fos = new FileOutputStream(args[0]);
	 PrintWriter pw = new PrintWriter(fos);
	 
	 //p es el proceso del programa Unsaludo.java
  	 p = r.exec(comando);
  	 
  	 //Interceptamos la salida del proceso con InputStream para leerla
     InputStream is = p.getInputStream();
	 BufferedReader br = new BufferedReader (new InputStreamReader (is));
     String linea;
     
     //Leemos la salida de Unsaludo
	 while((linea = br.readLine())!=null) 
	 {
       System.out.println("INSERTO EN "+args[0]+" > "+linea);
       pw.println(linea); //la inserta en el fichero
	 }
	 br.close();
	 pw.close();
   } 
   catch (Exception e)  { e.printStackTrace(); }
   
   // COMPROBACION DE ERROR  0 bien 1 mal
   int exitVal;
   try {
	 exitVal = p.waitFor();
	 System.out.println("Valor de Salida: " + exitVal);
	} catch (InterruptedException e) { e.printStackTrace(); } 
 }
}//Ejemplo3