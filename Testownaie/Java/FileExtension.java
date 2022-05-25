import java.io.FileNotFoundException;
import java.util.Scanner;

import org.junit.jupiter.api.extension.ExtensionContext;
import org.junit.jupiter.api.extension.ParameterContext;
import org.junit.jupiter.api.extension.ParameterResolver;

public class FileExtension implements ParameterResolver{

    @Override
    public boolean supportsParameter(ParameterContext parameterContext, ExtensionContext extensionContext)
             {
                return parameterContext.getParameter().getType() == String.class;
    }
    @Override
    public Object resolveParameter(ParameterContext parameterContext, ExtensionContext extensionContext)
             {
                 String output = "";
                 java.io.File myObj = new java.io.File("C:\\Projekty\\University\\Testownaie\\Java\\file.txt"); // trzeba tu wrzucic to co przychodzi z tego parametru ale nie wiem jak nic nie działa nic nie ma
            try (Scanner myReader = new Scanner(myObj)) {
                while (myReader.hasNextLine()) {
                    String data = myReader.nextLine();
                    output = output + data;
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            return output;
    }

    public @interface File {
        String path();
    }





}
