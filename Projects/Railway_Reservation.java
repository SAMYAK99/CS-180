package railwayreserve;

import com.Railway.ui.LoginDialog;
import com.jtattoo.plaf.hifi.HiFiLookAndFeel;
import java.util.Properties;
import javax.swing.JFrame;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;


public class RailwayReserve {

    
    public RailwayReserve(int a){
    /*    if(a==1){
            try{
                Properties p=new Properties();
                p.put("logoString","IMS");
                HiFiLookAndFeel.setCurrentTheme(p);
                UIManager.setLookAndFeel("com.jtattoo.plaf.hifi.HiFiLookAndFeel");  
           }catch(ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e){
               e.printStackTrace();
           }
        }else if(a==2){
            try{
                Properties p=new Properties();
                p.put("logoString","IMS");
                GraphiteLookAndFeel.setCurrentTheme(p);
                UIManager.setLookAndFeel("com.jtattoo.plaf.graphite.GraphiteLookAndFeel");
           }catch(ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e){
               e.printStackTrace();
           }
        } */
    }

    public static void main(String[] args) {
     //   f.setIconImage(Toolkit.getDefaultToolkit().getImage(ClassLoader.getSystemResource("/images/addPeople.png")));  
            try{
                Properties p=new Properties();
                p.put("logoString","IMS");
                HiFiLookAndFeel.setCurrentTheme(p);
                //UIManager.setLookAndFeel("com.jtattoo.plaf.hifi.HiFiLookAndFeel");  
                UIManager.setLookAndFeel("com.jtattoo.plaf.acryl.AcrylLookAndFeel");  
            }catch(ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e){
               e.printStackTrace();
            }
        

        LoginDialog ld=new LoginDialog();
        ld.setLocationRelativeTo(null);
        ld.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        ld.setVisible(true);
        //com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel
    }
    
}
