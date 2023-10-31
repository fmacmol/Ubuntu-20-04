import java.io.*;
public class Ejemplo2b {    
   	public static void main(String[] args)  {
	  Runtime r = Runtime.getRuntime();    
	  String comando= "CMD /C DIRR" ;
	  Process p=null;;
      try
        {
  		  p = r.exec( comando );
          InputStream is = p.getInputStream();
          BufferedReader br = new BufferedReader (new InputStreamReader (is));                      
          String linea;
		  while((linea = br.readLine())!=null) //lee una línea del fichero 
              System.out.println(linea); 
		  br.close();
        } 
        catch (Exception e)
        {
              e.printStackTrace();
        }
		
		// CONTROL DE LOS MENSAJES DE ERROR
		try {
			InputStream er = p.getErrorStream();					
			BufferedReader brer = 
			    new BufferedReader(new InputStreamReader(er));
			String liner = null;
			while ((liner = brer.readLine()) != null)
				System.out.println("ERROR >" + liner);
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
		
		// COMPROBACION DE ERROR - 0 bien - 1 mal
		int exitVal;
		try {
			exitVal = p.waitFor();
			System.out.println("Valor de Salida: " + exitVal);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} 
    }
}//Ejemplo2b