package OS.Rmi;

import java.rmi.Naming;
public class RmiClient { // RMI Client
    public static void main(String args[]) throws Exception {
        RmiServerIntf obj = (RmiServerIntf)
                Naming.lookup("//localhost/RmiServer");
        System.out.println(obj.getMessage());
    }
}
